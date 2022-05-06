#include <iostream>
using namespace std;
#include <string>
#include "Player.hpp"
namespace coup{
    class Captain :public Player{
    public:
        Captain(Game &game, const string & name);
        void block(Player &other);
        Player *lastStolenPlayer;
        void steal(Player &other);
    };
}