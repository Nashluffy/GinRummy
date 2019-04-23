
#include <vector>
#include <string>
using namespace std;

class GameRules {
    public:
        vector<pair<int,string>> unmatchedCards(vector<pair<int,string>> hand);
        int gin(vector<pair<int,string>> hand);
        int countScore(vector<pair<int,string>>& player1);
        int cardToScore(pair<int,string> card);
    private:
};

