#include "Player.h"

class Computer : public Player {
    public:
        Computer() {};
        void takeTurn(Deck deck,vector<pair<int,string>> river, GameRules rules);
};