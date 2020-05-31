
#include "Screens.hpp"
#include <iostream>

Menu::Menu(float x, float y, ResourceManager& resources) {
    width = x;
    height = y;
    play_text.setFont(resources.get_font(MainFont));
    play_text.setColor(sf::Color::Red);
    play_text.setString("NEW GAME");
    play_text.setPosition(x/2 - play_text.getGlobalBounds().width/2, y/3);
    
    exit_text.setFont(resources.get_font(MainFont));
    exit_text.setColor(sf::Color::White);
    exit_text.setString("EXIT");
    exit_text.setPosition(x/2 - exit_text.getGlobalBounds().width/2, y/3 * 2);
    
    background.setTexture(resources.get_texture(BackgroundMenu));
    icon.setTexture(resources.get_texture(MenuIcon));
    icon.setPosition(x/2 - icon.getGlobalBounds().width * 1.5 - play_text.getGlobalBounds().width/2, y/3);
    current_option = 0;
}

void Menu::draw(sf::RenderWindow &window) {
    window.draw(background);
    window.draw(play_text);
    window.draw(exit_text);
    window.draw(icon);
}

void Menu::move_up() {
    if (current_option==1) {
        current_option=0;
        play_text.setColor(sf::Color::Red);
        exit_text.setColor(sf::Color::White);
        icon.setPosition(width/2 - icon.getGlobalBounds().width * 1.5 - play_text.getGlobalBounds().width/2, height/3);
    }
}

void Menu::move_down() {
    if(current_option==0) {
        current_option =1;
        play_text.setColor(sf::Color::White);
        exit_text.setColor(sf::Color::Red);
        icon.setPosition(width/2 - icon.getGlobalBounds().width * 1.5 - exit_text.getGlobalBounds().width/2, height/3 * 2);
    }
}

bool Menu::quit() {
    if (current_option == 1) {
        return true;
    }
    return false;
}

