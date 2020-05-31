
#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy(ResourceManager& resources) : enem_laser(resources, LaserGreen) {
    
    enemy.setTexture(resources.get_texture(EnemyTexture));
    enemy.setScale(0.9, 0.9);
    number_of_enemies = std::rand() % 5 + 5;
    hit = false;
    movement.push_back(sf::Vector2f(45, 50));
    movement.push_back(sf::Vector2f(0, 50));
    movement.push_back(sf::Vector2f(-45, 100));
    movement.push_back(sf::Vector2f(0, 50));
    movement.push_back(sf::Vector2f(45, 50));
    distance_to_travel = 100;
    distance_traveled=0;
    direction_index=0;
    laser_clock.restart().asSeconds();
    velocity = 1.3;
    acceleration = velocity * 0.05;
    laser_on_screen = false;
}

void Enemy::reset() {
    velocity = 1.3;
    direction_index = 0;
    distance_traveled = 0;
    hit = false;
    enemy.setPosition(400, -2*enemy.getGlobalBounds().height);
}

sf::Vector2f Enemy::get_position() {
    return enemy.getPosition();
}

sf::FloatRect Enemy::get_rect() {
    return enemy.getGlobalBounds();
}

void Enemy::create_enemies() {
    enemy.setPosition(400, -2*enemy.getGlobalBounds().height);
}

void Enemy::shoot_laser(sf::RenderWindow &window, sf::Time elapsed) {
    enem_laser.set_position(sf::Vector2f(enemy.getPosition().x + enemy.getGlobalBounds().width/2,
                                         enemy.getPosition().y + enemy.getGlobalBounds().height));
    laser_clock.restart().asSeconds();
    laser_on_screen = true;
    //enem_laser.draw(window);
}

void Enemy::draw_enemies(sf::RenderWindow &window, sf::Time elapsed) {
    if (hit==true) {
        enemy.setPosition(std::rand() % (window.getSize().x/2) + window.getSize().x/10 + 100,
                          -2*enemy.getGlobalBounds().height);
        distance_traveled=0;
        hit=false;
    }
    if (enem_laser.get_position().y >= window.getSize().y) {
        laser_on_screen = false;
    }
    
    if (laser_on_screen) {
        enem_laser.move(sf::Vector2f(0, elapsed.asSeconds() * enem_laser.get_velocity()));
        enem_laser.draw(window);
    }
    
    if (enemy.getPosition().y < 0) {
        enemy.move(0, 100*elapsed.asSeconds());
    }
    else if (distance_traveled < distance_to_travel) {
        if (enemy.getPosition().x < window.getSize().x &&
            enemy.getPosition().y < window.getSize().y &&
            enemy.getPosition().y >= 0)
        {
            if(laser_clock.getElapsedTime().asSeconds() > 2.0 && laser_on_screen==false)
                shoot_laser(window, elapsed);
            enemy.move(movement[direction_index].x * elapsed.asSeconds() * velocity,
                       movement[direction_index].y * elapsed.asSeconds() * velocity);
            window.draw(enemy);
            distance_traveled += movement[direction_index].y * elapsed.asSeconds() * velocity;
        }
        else enemy.setPosition(std::rand() % (window.getSize().x/2) + window.getSize().x/10,
                               -2*enemy.getGlobalBounds().height);
        
    }
    else {
        direction_index = (direction_index+1) % movement.size();
        distance_traveled = 0;
    }

}

void Enemy::set_position(sf::Vector2f pos) {
    enemy.setPosition(pos);
}

