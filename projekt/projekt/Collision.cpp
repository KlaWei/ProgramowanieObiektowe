
#include "Collision.hpp"
#include "Rock.hpp"
#include "Enemy.hpp"

#include <iostream>

Collision::Collision(ResourceManager &resources) {
    collision_sound.setBuffer(resources.get_audio(CrashAudio));
}

bool Collision::enemy_hit(Laser &laser, Enemy &enemy) {
    if (laser.get_rect().intersects(enemy.get_rect()) &&
        laser.get_position().y > 0) {
        laser.set_position(sf::Vector2f(-10.f, -10.f));
        collision_sound.play();
        enemy.hit = true;
        //std::cout<<"enemy hit\n";
    }
    else  {
        
        return false;
    }
}

bool Collision::player_hit(Ship &player, Enemy &enemy) {
    if (player.get_rect().intersects(enemy.get_rect())) {
        enemy.hit=true;
        collision_sound.play();
        return true;
    }
    else if (player.get_rect().intersects(enemy.enem_laser.get_rect())) {
        enemy.enem_laser.set_position(sf::Vector2f(-100.f, -100.f));
        collision_sound.play();
        return true;
    }
    return false;
}

bool Collision::rock_hit(Rock &rock, Laser &laser) {
    bool hit = false;
    for (int i = 0; i<rock.rocks.size(); i++) {
        if (rock.rocks[i].first.getGlobalBounds().intersects(laser.get_rect())
            && laser.get_position().y > 0) {
            rock.rocks[i].second=false;
            collision_sound.play();
            laser.set_position(sf::Vector2f(-10.f, -10.f));
            hit = true;
        }
    }
    return hit;
}

bool Collision::player_hit_rock(Rock &rock, Ship &player) {
    bool hit = false;
    for (int i=0; i<rock.rocks.size(); i++) {
        if (rock.rocks[i].first.getGlobalBounds().intersects(player.get_rect())) {
            hit = true;
            rock.rocks[i].second = false;
        }
    }
    return hit;
}

