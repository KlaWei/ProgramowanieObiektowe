//
//  Ship.hpp
//  myspaceex
//
//  Created by weik on 02/06/2017.
//  Copyright © 2017 weik. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "GameObject.hpp"

class Ship : public GameObject {
public:
    Ship(ResourceManager& resources);
    void move(float x, float y);
    void draw(sf::RenderWindow &window);
    sf::FloatRect get_rect();
    void set_position(sf::Vector2f);
    sf::Vector2f get_position();
private:
    sf::Sprite player;
};

#endif /* Ship_hpp */
