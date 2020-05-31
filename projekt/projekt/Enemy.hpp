

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Collision.hpp"
#include "Laser.hpp"
#include "ResourceManager.hpp"
#include "GameObject.hpp"
#include <stdlib.h>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <vector>

class Enemy : public GameObject {
    friend class Collision;
public:
    Enemy(ResourceManager& resources);
    void draw(sf::RenderWindow &window);
    void set_position(sf::Vector2f pos);
    sf::Vector2f get_position();
    sf::FloatRect get_rect();
    void draw_enemies(sf::RenderWindow &window, sf::Time elapsed);
    void create_enemies();
    void shoot_laser(sf::RenderWindow &window, sf::Time elapsed);
    void reset();
    bool hit;
private:
    sf::Sprite enemy;
    Laser enem_laser;
    bool laser_on_screen;
    std::vector<sf::Vector2f> movement;
    float distance_to_travel;
    float distance_traveled;
    int direction_index;
    int number_of_enemies;
    sf::Clock laser_clock;
    //sf::Time time_since_last_shot;
};

#endif /* Enemy_hpp */
