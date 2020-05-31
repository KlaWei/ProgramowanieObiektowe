
#include "Game.hpp"


int main () {
    ResourceManager resources;
    if(!resources.load_resources()) {
        exit(-1);
    };
    Game game(resources);
    game.run();
    
    return 0;
}
