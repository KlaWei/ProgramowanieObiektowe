

#ifndef Menu_hpp
#define Menu_hpp

#include <SFML/Graphics.hpp>
#include <stdbool.h>
#include "ResourceManager.hpp"
//#include "Screens.hpp"

class Screens;

class Menu : public Screens {
public:
    Menu(float x, float y, ResourceManager& resources);
    void draw(sf::RenderWindow &window);
    void move_down();
    void move_up();
    bool quit();
private:
    int current_option;
    sf::Texture icon_texture;
    sf::Sprite icon;
    sf::Texture background_text;
    sf::Sprite background;
    sf::Font font;
    sf::Text play_text;
    sf::Text exit_text;
};

#endif /* Menu_hpp */
