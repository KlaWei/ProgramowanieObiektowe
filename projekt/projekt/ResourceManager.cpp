
#include "ResourceManager.hpp"
#include <iostream>

bool ResourceManager::load_resources() {
    try {
        load_from_file_texture(Player, "resources/playerShip2_red.png");
        load_from_file_texture(EnemyTexture, "resources/enemyRed1.png");
        load_from_file_texture(LaserRed, "resources/laserRed02.png");
        load_from_file_texture(LaserGreen, "resources/laserGreen12.png");
        load_from_file_texture(Background, "resources/darkPurple.png");
        load_from_file_texture(BackgroundMenu, "resources/background.png");
        load_from_file_texture(PlayerLife, "resources/playerLife2_red.png");
        load_from_file_texture(RockBig, "resources/meteorGrey_big4.png");
        load_from_file_texture(RockMedium, "resources/meteorGrey_med1.png");
        load_from_file_font(MainFont, "resources/kenvector_future.ttf");
        load_from_file_audio(ShootLaserAudio, "resources/laser1.wav");
        load_from_file_audio(CrashAudio, "resources/crash.wav");
        load_from_file_texture(MenuIcon, "resources/cursor.png");
        
    } catch (std::string str) {
        std::cout<<str<<"\n";
        return false;
    }
    
    return true;
}

void ResourceManager::load_from_file_texture(TextureId id, std::string filename) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if(!texture->loadFromFile(filename)) throw std::string("Can't load object");
    textures.insert(std::make_pair(id, std::move(texture)));
}

void ResourceManager::load_from_file_font(FontId id, std::string filename) {
    std::unique_ptr<sf::Font> font(new sf::Font());
    if(!font->loadFromFile(filename)) throw std::string("Can't load object");;
    fonts.insert(std::make_pair(id, std::move(font)));
}

void ResourceManager::load_from_file_audio(AudioId id, std::string filename) {
    std::unique_ptr<sf::SoundBuffer> music(new sf::SoundBuffer());
    if(!music->loadFromFile(filename)) throw std::string("Can't load object");;
    audio.insert(std::make_pair(id, std::move(music)));
}

sf::Texture& ResourceManager::get_texture(TextureId id) {
    auto ret = textures.find(id);
    return  *ret->second;
}

sf::Font& ResourceManager::get_font(FontId id) {
    auto ret = fonts.find(id);
    return *ret->second;
}

sf::SoundBuffer& ResourceManager::get_audio(AudioId id) {
    auto ret = audio.find(id);
    return *ret->second;
}
