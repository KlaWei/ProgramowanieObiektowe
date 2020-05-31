
#ifndef Collision_hpp
#define Collision_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdbool.h>
#include "Ship.hpp"
#include "Laser.hpp"
#include "ResourceManager.hpp"

class Rock;
class Enemy;

class Collision { // zmienic zeby uzywalo resource
public:
    Collision(ResourceManager &resources);
    bool player_hit(Ship &player, Enemy &enemy);
    bool enemy_hit(Laser &laser, Enemy &enemy);
    bool rock_hit(Rock &rock, Laser &laser);
    bool player_hit_rock(Rock &rock, Ship &player);
private:
    sf::Sound collision_sound;
};

#endif /* Collision_hpp */
