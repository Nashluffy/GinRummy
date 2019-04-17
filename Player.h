#include <string>
#include <vector>
#include "GameRules.h"
#include "Deck.h"

using namespace std;

class Player {
    public:
        Player() {};
        vector<pair<int,string>> hand;
        void putCard(int i, vector<pair<int,string>>& river);
        void pullCardRiver(vector<pair<int,string>> river);
        void pullCardDeck(Deck& deck);
        void displayHand();
       void turn(Deck deck, vector<pair<int,string>> river, GameRules rules);
    private:
};
