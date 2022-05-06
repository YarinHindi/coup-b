#include "Player.hpp"
#include "Assassin.hpp"
constexpr int coupAssassinCost = 3;
constexpr int coupRegPlayerCost = 7;
constexpr int maxCoup = 10;
using namespace coup;
Player::Player(Game & game, const string & name,const string & role) {
    this->cash = 0;
    this->game = &game;
    this->name = name;
    this->game->addPlayer(*this);
    this->lastAction = "";
    this->playerRole = role;
    this->playerStatus = 1;
}
void Player::checkIfMustCoup() const {
    if(this->cash>=maxCoup){
        throw invalid_argument("you must coup on that turn");
    }
}
void Player::income() {
    this->game->validAction(*this);
    checkIfMustCoup();
    this->game->updateTurn();
    this->cash++;
    this->lastAction = "income";
}
void Player::foreign_aid(){
    this->game->validAction(*this);
    checkIfMustCoup();
    this->game->updateTurn();
    this->cash+=2;
    this->lastAction = "foreign_aid";
}
int Player::coins()const {
    return this->cash;
}
string Player::role()const {
    return this->playerRole;
}

void Player::coup(Player &player) {
    this->game->validAction(*this);
    if(player.playerStatus==0){
        throw invalid_argument("this player already dead");
    }
    if(this->playerRole=="Assassin"&&(this->cash>=coupAssassinCost&&this->cash<coupRegPlayerCost)){
        Assassin *temp = dynamic_cast<Assassin*>(this);
        temp->lastRemovedPlayer = &player;
        for (unsigned int i = 0; i < this->game->playerCount ; ++i) {
            if(this->game->thePlayers.at(i)==&player){
                temp->removedPlayerIndex=i;
            }
        }
        this->game->removePlayer(player);
        this->game->updateTurn();
        this->cash-=coupAssassinCost;
        this->lastAction="Coup";
        return;
    }
    if(this->cash>=coupRegPlayerCost) {
        this->game->removePlayer(player);
        this->game->updateTurn();
        this->cash -= coupRegPlayerCost;
        this->lastAction="Coup";
        return;
    }

    throw invalid_argument("invalid coup you cannot coup this player");
}

