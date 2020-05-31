
#include "Ship.hpp"

Ship::Ship(ResourceManager& resources) {
    player.setTexture(resources.get_texture(Player));
    velocity = 800.f;
    acceleration = velocity * 0.0001;
}

void Ship::move(float x, float y) {
    player.move(x, y);
}

void Ship::draw(sf::RenderWindow &window) {
    window.draw(player);
}


void Ship::set_position(sf::Vector2f pos) {
    player.setPosition(pos);
}

sf::FloatRect Ship::get_rect() {
    return player.getGlobalBounds();
}

sf::Vector2f Ship::get_position() {
    return player.getPosition();
}
