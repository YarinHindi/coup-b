#include "Game.hpp"
using namespace coup;
Game::Game(){
    this->currentTurn = 0;
    this->playerCount = 0;
    this->started = 0;


}

Game::~Game() {

}

void Game::addPlayer(Player& player) {
    if(playerCount==MaxPlayerNum){
        throw invalid_argument("must have less than 6 in the the game");
    }
    if(started==1){
        throw invalid_argument("game already started");
    }
//    this->thePlayers.at(playerCount) = &player;
    this->thePlayers.push_back(&player);
    playerCount++;
}
vector<string> Game::players() const {
    vector<string> ans;
    for (unsigned int i=0;i< playerCount;i++){
        if(thePlayers.at(i)->playerStatus==1) {
            ans.push_back(this->thePlayers.at(i)->name);
        }
    }
    return ans;
}
void Game::validAction(Player & player){
    if(playerCount==1){
        throw invalid_argument("must have more than 1 player to start the game");
    }
    if(this->thePlayers.at(this->currentTurn)!= &player){
        throw invalid_argument("this is not your turn");
    }
    this->started=1;
}
void Game::updateTurn() {
    for (unsigned i = this->currentTurn+1; i < playerCount+this->currentTurn; ++i) {
        if(this->thePlayers.at(i % playerCount)->playerStatus==1){
            this->currentTurn =i % playerCount;
            break;
        }
    }
}
string Game::turn()const {
    return this->thePlayers.at(this->currentTurn)->name;
}
void Game::removePlayer(Player &player) {
    for (unsigned int i = 0; i < playerCount; ++i) {
        if(this->thePlayers.at(i)==&player){
            this->thePlayers.at(i)->playerStatus = 0;
            break;
        }
    }
}

void Game::revivePlayer(Player &player, unsigned int pos) {
    for (unsigned int i = 0; i < playerCount; ++i) {
        if(this->thePlayers.at(i)==&player){
            this->thePlayers.at(i)->playerStatus = 1;
            break;
        }
    }
}
string Game::winner() const {
    int count = 0;
    string ans;
    for (unsigned int i = 0; i < playerCount; ++i) {
        if (this->thePlayers.at(i)->playerStatus == 1) {
            count++;
            ans = this->thePlayers.at(i)->name;
        }
    }
    if(count>1||started==0){
        throw  invalid_argument("there is now winner yet");
    }
    return ans;
}