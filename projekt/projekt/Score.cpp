
#include "Score.hpp"

#include <iostream>
#include <string.h>

Score::Score(int width, ResourceManager& resources) {
    live.setTexture(resources.get_texture(PlayerLife));
    score_text.setFont(resources.get_font(MainFont));
    score_text.setColor(sf::Color::White);
    score = 0;
    for (int i=0; i<3; i++) {
        live.setPosition(i*live.getGlobalBounds().width + 10, 10);
        lives_vec.push_back(live);
    }
    score_text.setPosition(width - 100, 0);
    lives=3;
}

int Score::get_score() {
    return (int)score;
}

void Score::reset() {
    lives = 3;
    score = 0;
}

bool Score::update_lives(int update) {
    lives += update;
    if(lives<=0) {
        return false;
    }
    return true;
}

void Score::draw(sf::RenderWindow &window) {
    std::string s = std::to_string((int)score);
    score_text.setString(s);
    if(score_text.getGlobalBounds().width + score_text.getPosition().x > window.getSize().x) {
        score_text.setPosition(score_text.getPosition().x - 10, 0);
    }
    window.draw(score_text);
    score+=0.01;
    
    switch (lives) {
        case 1:
            window.draw(lives_vec[0]);
            break;
        case 2:
            window.draw(lives_vec[0]);
            window.draw(lives_vec[1]);
            break;
        case 3:
            window.draw(lives_vec[0]);
            window.draw(lives_vec[1]);
            window.draw(lives_vec[2]);
            break;
        default:
            break;
    }
}
