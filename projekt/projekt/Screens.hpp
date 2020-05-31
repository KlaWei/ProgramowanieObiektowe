
#ifndef Screens_hpp
#define Screens_hpp

#include <SFML/Graphics.hpp>
#include <stdbool.h>
#include "ResourceManager.hpp"

enum ScreenId {
    MenuScreen,
    GameOver
};

class Screens {
public:
    virtual void move_up() {}
    virtual void move_down() {}
    virtual bool quit() { return false; }
    virtual void draw(sf::RenderWindow &window) {}
protected:
    int width;
    int height;
};

class Menu : public Screens {
public:
    Menu(float x, float y, ResourceManager& resources);
    void draw(sf::RenderWindow &window);
    void move_down();
    void move_up();
    bool quit();
private:
    int current_option;
    sf::Sprite icon;
    sf::Sprite background;
    sf::Text play_text;
    sf::Text exit_text;
};

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
