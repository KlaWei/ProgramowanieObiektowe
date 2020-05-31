
#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <memory.h>
#include <string.h>

enum TextureId {
    Background,
    BackgroundMenu,
    Player,
    EnemyTexture,
    LaserRed,
    LaserGreen,
    PlayerLife,
    RockMedium,
    RockBig,
    MenuIcon
};

enum AudioId {
    ShootLaserAudio,
    CrashAudio
};

enum FontId {
    MainFont
};

class ResourceManager {
public:
    ResourceManager() { }
    bool load_resources();
    sf::Texture& get_texture(TextureId id);
    sf::SoundBuffer& get_audio(AudioId id);
    sf::Font& get_font(FontId id);
private:
    void load_from_file_texture(TextureId id, std::string filename);
    void load_from_file_audio(AudioId, std::string filename);
    void load_from_file_font(FontId, std::string filename);
    std::map<TextureId, std::unique_ptr<sf::Texture>> textures;
    std::map<AudioId, std::unique_ptr<sf::SoundBuffer>> audio;
    std::map<FontId, std::unique_ptr<sf::Font>> fonts;
};

#endif
