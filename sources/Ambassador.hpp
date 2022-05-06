#include <iostream>
using namespace std;
#include <string>
#include "Player.hpp"
namespace coup{
    class Ambassador :public Player{
    public:
        Ambassador(Game &game, string const & name);
        void transfer(Player& first,Player &second);
        void block(Player& player);

    };
}