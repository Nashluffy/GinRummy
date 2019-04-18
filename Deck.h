#include <vector>
#include <string>

using namespace std;

class Deck {
    public:
        void flipCard();
        void shuffle();
        vector<pair<int,string>> deal();
        int getSize() {return deck.size();}
        pair<int,string> topCard() {return deck.front();} 
        vector<pair<int,string>> deck;
        void gameStart(vector<pair<int,string>>& river);
        Deck();
    private:
};