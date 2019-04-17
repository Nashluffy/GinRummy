#include <vector>
#include <string>
#include <iostream>

#include "Computer.h"


using namespace std;

void Computer::takeTurn(Deck& deck, vector<pair<int,string>>& river, GameRules& rules){    
    vector<pair<int,string>> driftWood;

    vector<pair<int,string>> testGameRules;
    testGameRules.push_back(make_pair(13,"H"));
    testGameRules.push_back(make_pair(1,"S"));
    testGameRules.push_back(make_pair(1,"C"));
    testGameRules.push_back(make_pair(12,"D"));
    testGameRules.push_back(make_pair(6,"H"));
    testGameRules.push_back(make_pair(9,"S"));
    testGameRules.push_back(make_pair(11,"S"));
    testGameRules.push_back(make_pair(2,"D"));
    testGameRules.push_back(make_pair(7,"H"));
    testGameRules.push_back(make_pair(8,"C"));
    
    driftWood = rules.unmatchedCards(hand);
    int origUnmatched = driftWood.size();
    cout << "first" << endl;

    pullCardRiver(river);
    testGameRules.push_back(make_pair(7,"D"));
    
    
    driftWood = rules.unmatchedCards(hand);
    int newUnmatched = driftWood.size();
    cout << "second" << endl;

    cout << origUnmatched << " " << newUnmatched<<endl;

    if(origUnmatched > newUnmatched){
        for(int i = 0; i < driftWood.size(); i++){
            for(int j = 0; j < hand.size(); j++){
                if((driftWood.at(i).first == hand.at(j).first) && (driftWood.at(i).second == hand.at(j).second)){
                    putCard(i, river);
                    cout << hand.at(i).first << " of " << hand.at(i).second << endl;
                    
                    i = driftWood.size() - 1;
                    j = hand.size() - 1;
                }
            }
        }
    }
    else{
        
    }
    
}

