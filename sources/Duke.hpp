#include <iostream>
using namespace std;
#include <string>
#include "Player.hpp"
namespace coup{
class Duke :public Player{
    public:
        Duke(Game &game, const string & name);
        void tax();
        void block(Player& player);

    };
}