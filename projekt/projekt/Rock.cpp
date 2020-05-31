
#include "Rock.hpp"

#include <iostream>

Rock::Rock(ResourceManager& resources) {
    medium_rock.setTexture(resources.get_texture(RockMedium));
    big_rock.setTexture(resources.get_texture(RockBig));
    rocks_index=0;
    velocity = 80;
    acceleration = velocity * 0.2;
    previous_distance = 0;
    rock_shot = true;
}

void Rock::reset() {
    for (int i=0; i<rocks.size(); i++) {
        rocks[i].second = false;
    }
    rock_clock.restart().asSeconds();
    rocks_index = 0;
    previous_distance = 0;
    velocity = 80;
}

void Rock::create_rocks() {
    int number_of_rocks = std::rand() % 3 + 3;
    for (int i = 0; i<number_of_rocks; i++) {
        rocks.push_back(std::make_pair(medium_rock, false));
        rocks.push_back(std::make_pair(big_rock, false));
    }
    rock_clock.restart().asSeconds();
}

bool Rock::rock_shot_down() {
    return rock_shot;
}

void Rock::draw_rocks(sf::RenderWindow &window, sf::Time elapsed) {
    rock_shot = true;
    int free_rock = -1;
    for (int i=0; i<rocks.size(); i++) {
        if (rocks[i].first.getGlobalBounds().height + rocks[i].first.getPosition().y >
            window.getSize().y) {
            rocks[i].first.setPosition(std::rand() % 800 + 100, -10);
            rocks[i].second = false;
            rock_shot = false;
        }
        if (rocks[i].second==false) {
            rocks[i].first.setPosition(std::rand() % 800 + 100, -10);
            free_rock = i;
        }
    }
    if (previous_distance > window.getSize().y/5 && free_rock!=-1) {
        rocks[free_rock].second = true;
        rock_clock.restart().asSeconds();
        previous_distance = 0;
    }
    
    for (int i = 0; i<rocks.size(); i++) {
        if (rocks[i].second==true) {
            window.draw(rocks[i].first);
            rocks[i].first.move(0, elapsed.asSeconds()*velocity);
        }
    }
    previous_distance += elapsed.asSeconds()*velocity;
}

