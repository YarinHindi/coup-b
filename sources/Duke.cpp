#include "Duke.hpp"
using namespace coup;
Duke::Duke(Game &game, const string & name): Player(game,name,"Duke") {

}
void Duke::tax() {
    game->validAction(*this);
    game->updateTurn();
    this->cash+=3;
}
void Duke::block(Player &player) {
    if(player.lastAction!="foreign_aid"){
        throw invalid_argument("invalid block you cannot block this player");
    }
    player.cash-=2;
    this->lastAction = "Block";
}


