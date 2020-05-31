
#ifndef EndScreen_hpp
#define EndScreen_hpp

#include "ResourceManager.hpp"
#include "Screens.hpp"
#include <SFML/Graphics.hpp>
#include <stdbool.h>

class EndScreen : public Screens {
public:
    EndScreen(int x, int y, ResourceManager& resources);
    void draw(sf::RenderWindow &window);
    void initialize(int s);
    void move_up();
    void move_down();
    bool quit();
private:
    sf::Sprite background;
    sf::Text exit;
    sf::Text play_again;
    sf::Text score;
    int current;
};

#endif
