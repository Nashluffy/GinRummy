#include <vector>
#include <string>
#include <iostream>

#include "Computer.h"

using namespace std;

void Computer::takeTurn(Deck& deck, vector<pair<int,string>>& river, GameRules& rules){    
    vector<pair<int,string>> testGameRules;
    vector<pair<int,string>> driftWood;
    testGameRules.push_back(make_pair(1,"Spade"));
    testGameRules.push_back(make_pair(1,"Diamond"));
    testGameRules.push_back(make_pair(1,"Club"));
    testGameRules.push_back(make_pair(3,"Heart"));
    testGameRules.push_back(make_pair(3,"Spade"));
    testGameRules.push_back(make_pair(3,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(9,"Heart"));
    testGameRules.push_back(make_pair(9,"Club"));
    testGameRules.push_back(make_pair(9,"Spade"));
    
    cout << "t" << endl;

    driftWood = rules.unmatchedCards(testGameRules);
    int origUnmatched = driftWood.size();

    cout << "test";
    pullCardRiver(river);
    driftWood = rules.unmatchedCards(testGameRules);
    int newUnmatched = driftWood.size();

    // Hey im testing this

    if(origUnmatched > newUnmatched){
        for(int i = 0; i < driftWood.size(); i++){
            for(int j = 0; i < hand.size(); j++){
                if((hand.at(i).first == hand.at(j).first) && (hand.at(i).first == hand.at(j).first)){
                    putCard(i, river);
                }
            }
        }
    }
    else{
        
    }
    
}

