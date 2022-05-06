#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace coup;
Contessa::Contessa(Game &game, const string & name): Player(game,name,"Contessa") {
}
void Contessa::block(Player &player) {
    if(player.playerRole!="Assassin"||player.lastAction!="Coup"){
        throw invalid_argument("Contessa cant block this player");
    }
    Assassin* temp = dynamic_cast<Assassin*>(&player);
    if(temp->lastRemovedPlayer== nullptr){
        throw invalid_argument("Assassin has been couped already in this round");
    }
    game->revivePlayer(*temp->lastRemovedPlayer,temp->removedPlayerIndex);
    temp->lastRemovedPlayer = nullptr;

}

