
#ifndef Laser_hpp
#define Laser_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "GameObject.hpp"
#include "ResourceManager.hpp"

class Laser : public GameObject {
    friend class Collision;
public:
    Laser(ResourceManager& resources, TextureId id);
    void move(sf::Vector2f move_vector);
    void draw(sf::RenderWindow &window);
    sf::FloatRect get_rect();
    void set_position(sf::Vector2f pos);
    sf::Vector2f get_position();
    void play();
private:
    sf::Sprite laser;
    sf::Sound laser_sound;
};

#endif /* Laser_hpp */
