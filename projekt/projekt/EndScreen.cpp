
#include "Screens.hpp"
#include <iostream>
#include <string.h>

EndScreen::EndScreen(int x, int y, ResourceManager& resources) {
    height = y;
    width = x;
    background.setTexture(resources.get_texture(BackgroundMenu));
    exit.setFont(resources.get_font(MainFont));
    exit.setString("EXIT");
    exit.setColor(sf::Color::White);
    exit.setPosition(width/2 - exit.getGlobalBounds().width/2, height/4 * 3);
    
    play_again.setFont(resources.get_font(MainFont));
    play_again.setString("PLAY AGAIN");
    play_again.setColor(sf::Color::Red);
    play_again.setPosition(width/2 - play_again.getGlobalBounds().width/2, height/4 * 2);
    
    score.setFont(resources.get_font(MainFont));
    score.setCharacterSize(90);
    
    current = 0;
}

void EndScreen::initialize(int s) {
    score.setString("SCORE: "+std::to_string(s));
    score.setColor(sf::Color::Green);
    score.setPosition(width/2 - score.getGlobalBounds().width/2, height/4);
}

void EndScreen::move_up() {
    if (current==1) {
        play_again.setColor(sf::Color::Red);
        exit.setColor(sf::Color::White);
        current=0;
    }
}

void EndScreen::move_down() {
    if (current==0) {
        play_again.setColor(sf::Color::White);
        exit.setColor(sf::Color::Red);
        current=1;
    }
}

void EndScreen::draw(sf::RenderWindow &window) {
    window.draw(background);
    window.draw(score);
    window.draw(play_again);
    window.draw(exit);
}

bool EndScreen::quit() {
    if (current==0) return false;
    return true;
}

