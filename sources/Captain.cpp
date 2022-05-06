#include "Captain.hpp"
#include <algorithm>
using namespace coup;
Captain::Captain(Game &game, const string & name): Player(game,name,"Captain") {
        this->lastStolenPlayer = nullptr;
}
void Captain::block(Player& other){
    if(other.lastAction!="Steal"||other.playerRole!="Captain"){
        throw invalid_argument("invalid block you cannot block this player");
    }

    Captain* temp = dynamic_cast<Captain*>(&other);
    if(temp->lastStolenPlayer== nullptr){
        throw invalid_argument("invalid block you cannot block this player");
    }
    other.cash-=2;
    temp->lastStolenPlayer->cash+=2;
    temp->lastStolenPlayer = nullptr;
    this->lastAction = "Block";

}
void Captain::steal(Player &other) {
    this->lastAction="Steal";
    this->game->validAction(*this);
    this->game->updateTurn();
    this->cash+=min(other.cash,2);
    other.cash= max(0,other.cash-2);
    this->lastStolenPlayer = &other;

}

