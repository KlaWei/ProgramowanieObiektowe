
#include "Laser.hpp"

Laser::Laser(ResourceManager& resources, TextureId id) {
    laser.setTexture(resources.get_texture(id));
    laser_sound.setBuffer(resources.get_audio(ShootLaserAudio));
    velocity = 700.f;
}

void Laser::move(sf::Vector2f move_vector) {
    laser.move(move_vector);
}

void Laser::draw(sf::RenderWindow &window) {
    window.draw(laser);
}

sf::FloatRect Laser::get_rect() {
    return laser.getGlobalBounds();
}

void Laser::play() {
    laser_sound.play();
}

void Laser::set_position(sf::Vector2f pos) {
    laser.setPosition(pos);
}

sf::Vector2f Laser::get_position() {
    return laser.getPosition();
}


