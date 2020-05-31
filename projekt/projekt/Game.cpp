
#include "Game.hpp"


Game::Game(ResourceManager &resources) :
               playerShip(resources),
               laser(resources, LaserRed),
               game_window(sf::VideoMode(1000, 810), "Space Shooter"),
               score(game_window.getSize().x, resources),
               menu(game_window.getSize().x, game_window.getSize().y, resources),
               enemy(resources),
               rocks(resources),
               end_screen(game_window.getSize().x, game_window.getSize().y, resources),
               collisions(resources)
{
    resources.get_texture(Background).setRepeated(true);
    background.setTexture(resources.get_texture(Background));
    background.setTextureRect(sf::IntRect(0,0,256,256));
    
    playerShip.set_position(sf::Vector2f(game_window.getSize().x/2,
                                         game_window.getSize().y-playerShip.get_rect().height));
    game_on = false;
    laser.set_velocity(1000);
    current_screen = MenuScreen;
    game_time_index = 1;
    rocks_unshot = 0;
}

void Game::initialize() {
    enemy.create_enemies();
    rocks.create_rocks();
    game_clock.restart().asSeconds();
    game_time.restart().asSeconds();
    game_on = true;
}

void Game::reset() {
    enemy.reset();
    rocks.reset();
    score.reset();
    playerShip.set_position(sf::Vector2f(game_window.getSize().x/2,
                                         game_window.getSize().y-playerShip.get_rect().height));
    game_time_index = 1;
    game_time.restart().asSeconds();
    game_on=true;
    rocks_unshot = 0;
}

void Game::run() {
    sf::Time elapsed;
    bool shoot_laser;
    int bgY = 0;
    while (game_window.isOpen()) {
        if (game_on == false) {
            switch (current_screen) {
                case MenuScreen:
                    run_screen(menu, MenuScreen);
                    break;
                case GameOver:
                    run_screen(end_screen, GameOver);
                    break;
                default:
                    break;
            }
        }
        else {
            if (game_time.getElapsedTime().asSeconds() > game_time_index*10) {
                enemy.accelerate();
                rocks.accelerate();
                game_time_index++;
            }
            elapsed = game_clock.getElapsedTime();
            game_clock.restart().asSeconds();
            sf::Event event;
            while (game_window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    game_window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    laser.set_position(sf::Vector2f(playerShip.get_position().x +
                                       playerShip.get_rect().width/2, playerShip.get_position().y));
                    
                    laser.play();
                    shoot_laser=true;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
                (playerShip.get_position().x - playerShip.get_velocity() * elapsed.asSeconds() > 0)) {
                playerShip.move(-playerShip.get_velocity() * elapsed.asSeconds(), 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
                (playerShip.get_position().x + playerShip.get_rect().width +
                 playerShip.get_velocity() * elapsed.asSeconds() < game_window.getSize().x)) {
                    playerShip.move(playerShip.get_velocity() * elapsed.asSeconds(), 0);
            }
            game_window.clear();
            bgY+=1;
            background.setTextureRect(sf::IntRect(0,bgY,game_window.getSize().x,
                                                  game_window.getSize().y));
            game_window.draw(background);
            score.draw(game_window);
            
            playerShip.draw(game_window);
            if(shoot_laser==true) {
                collisions.enemy_hit(laser, enemy);
                laser.draw(game_window);
                laser.move(sf::Vector2f(0, -1*(laser.get_velocity())*elapsed.asSeconds()));
            }
            rocks.draw_rocks(game_window, elapsed);
            enemy.draw_enemies(game_window, elapsed);
            collisions.rock_hit(rocks, laser);
            if (collisions.player_hit(playerShip, enemy) ||
                collisions.player_hit_rock(rocks, playerShip)) {
                if(score.update_lives(-1)==false) {
                    end_screen.initialize(score.get_score());
                    current_screen = GameOver;
                    game_on = false;
                }
            }
            if (!rocks.rock_shot_down()) {
                rocks_unshot++;
            }
            if (rocks_unshot == 3) {
                score.update_lives(-1);
            }
            game_window.display();
        }
    }
}

void Game::run_screen(Screens &screen, ScreenId id) {
    sf::Event event;
    while (game_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape) {
            game_window.close();
        }
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Down) {
            screen.move_down();
        }
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Up) {
            screen.move_up();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
            if (screen.quit() == true)
                game_window.close();
            else {
                switch (id) {
                    case MenuScreen:
                        initialize();
                        break;
                    case GameOver:
                        reset();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    game_window.clear();
    screen.draw(game_window);
    game_window.display();
    
}

