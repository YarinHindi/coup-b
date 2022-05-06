#include "Assassin.hpp"
using namespace coup;
Assassin::Assassin(Game &game, const string & name): Player(game,name,"Assassin") {
    this->lastRemovedPlayer = nullptr;
    this->removedPlayerIndex = 0;
}
