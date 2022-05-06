#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
#include <string>
#include <array>
#include <vector>
#include "Player.hpp"
#include <stdexcept>
constexpr int  MaxPlayerNum  = 6;
namespace coup{
    class Player;
    class Game {
    public :
        vector<Player*> thePlayers;
        unsigned int playerCount;
        unsigned int currentTurn;
        Game();
        ~Game();
        int started ;
        vector<string> players() const;
        void addPlayer(Player & player);
        void revivePlayer(Player & player,unsigned int pos);
        void validAction(Player & player);
        void removePlayer(Player &player);
        string turn()const;
        string winner()const;
        void updateTurn();
    };
}
#endif