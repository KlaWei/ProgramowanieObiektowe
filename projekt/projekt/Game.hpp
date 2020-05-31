

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <iostream>
#include "Ship.hpp"
#include "Laser.hpp"
#include "Collision.hpp"
#include "Enemy.hpp"
#include "Score.hpp"
#include "Rock.hpp"
#include "ResourceManager.hpp"
#include "Screens.hpp"

class Game {
public:
    Game(ResourceManager& resources);
    void run();
    void initialize();
private:
    void run_screen(Screens &screen, ScreenId id);
    void reset();
    int game_time_index;
    ScreenId current_screen;
    sf::RenderWindow game_window;
    Ship playerShip;
    Laser laser;
    sf::Sprite background;
    sf::Clock game_clock;
    sf::Clock game_time;
    Menu menu;
    Rock rocks;
    Enemy enemy;
    Score score;
    Collision collisions;
    EndScreen end_screen;
    bool game_on;
    int rocks_unshot;
};

#endif /* Game_hpp */
