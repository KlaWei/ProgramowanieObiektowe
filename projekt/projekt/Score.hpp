
#ifndef Score_hpp
#define Score_hpp

#include "ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include <stdbool.h>
#include <vector>

class Score {
public:
    Score(int width, ResourceManager& resources);
    bool update_lives(int update);
    int get_score();
    void draw(sf::RenderWindow &window);
    void reset();
private:
    std::vector<sf::Sprite> lives_vec;
    float score;
    int lives;
    sf::Sprite live;
    sf::Text score_text;
};

#endif /* Score_hpp */
