#include <vector>
#include <string>
#include <iostream>

#include "Computer.h"


using namespace std;

void Computer::takeTurn(Deck& deck, vector<pair<int,string>>& river, GameRules& rules){    
    vector<pair<int,string>> testGameRules;
    vector<pair<int,string>> driftWood;
    testGameRules.push_back(make_pair(3,"Diamonds"));
    testGameRules.push_back(make_pair(2,"Heart"));
    testGameRules.push_back(make_pair(4,"Spade"));
    testGameRules.push_back(make_pair(5,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(8,"Spade"));
    testGameRules.push_back(make_pair(10,"Spade"));
    testGameRules.push_back(make_pair(11,"Spade"));
    testGameRules.push_back(make_pair(15,"Spade"));
    testGameRules.push_back(make_pair(17,"Spade"));

    for( auto it:hand){
        cout << it.first << " of " << it.second << endl; 
    }

    driftWood = rules.unmatchedCards(hand);
    int origUnmatched = driftWood.size();

    
    pullCardRiver(river);
    //driftWood = rules.unmatchedCards(hand);
    //int newUnmatched = driftWood.size();

    /*if(origUnmatched > newUnmatched){
        for(int i = 0; i < driftWood.size(); i++){
            for(int j = 0; i < hand.size(); j++){
                if((hand.at(i).first == hand.at(j).first) && (hand.at(i).first == hand.at(j).first)){
                    putCard(i, river);
                }
            }
        }
    }
    else{
        
    }*/
    
}

