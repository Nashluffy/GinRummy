#include <string>
#include <vector>


using namespace std;

class Player {
    public:
        Player() {};
        vector<pair<int,string>> hand;
        vector<pair<int,string>> putCard(int i, vector<pair<int,string>> river);
        vector<pair<int,string>> pullCardRiver(vector<pair<int,string>> river);
        vector<pair<int,string>> pullCardDeck(vector<pair<int,string>> deck);
        void displayHand();
        void turn(vector<pair<int,string>> river);
    private:
};
