#include <vector>
#include <string>

using namespace std;
//Explained the Deck.cpp file. 

class Deck {
    public:
        void flipCard();
        void shuffle();
        vector<pair<int,string>> deal();
        int getSize() {return deck.size();}
        pair<int,string> topCard() {return deck.front();} 
        vector<pair<int,string>> deck;
        void gameStart(vector<pair<int,string>>& river);
        void reshuffleDeck(vector<pair<int,string>>& river);
        Deck();
    private:
};
