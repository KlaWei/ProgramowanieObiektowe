
#ifndef Rock_hpp
#define Rock_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include <stdbool.h>
#include "Collision.hpp"
#include "ResourceManager.hpp"
#include "GameObject.hpp"

class Rock : public GameObject {
    friend class Collision;
public:
    Rock(ResourceManager& resources);
    void create_rocks();
    void draw_rocks(sf::RenderWindow &window, sf::Time elapsed);
    void reset();
    bool rock_shot_down();
private:
    std::vector<std::pair<sf::Sprite, bool>> rocks;
    int rocks_index;
    float previous_distance;
    sf::Sprite medium_rock;
    sf::Sprite big_rock;
    sf::Clock rock_clock;
    bool rock_shot;
};

#endif
