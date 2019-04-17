#include <vector>
#include <string>
#include "Player.h"
#include "GameRules.h"
#pragma once

using namespace std;

class Deck {
    public:
        void flipCard();
        void shuffle();
        vector<pair<int,string>> deal();
        void putCard(pair<int,string> card, Player player);
        void pullCard(pair<int,string> card, Player player);
        int getSize() {return deck.size();}
        pair<int,string> topCard() {return deck.front();} 
        vector<pair<int,string>> deck;
        Deck();
    private:
};