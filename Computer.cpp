#include <vector>
#include <string>
#include <iostream>

#include "Computer.h"


using namespace std;

void Computer::takeTurn(Deck& deck, vector<pair<int,string>>& river, GameRules& rules){    
    vector<pair<int,string>> testGameRules;
    vector<pair<int,string>> driftWood;
    testGameRules.push_back(make_pair(1,"Diamonds"));
    testGameRules.push_back(make_pair(1,"Heart"));
    testGameRules.push_back(make_pair(1,"Spade"));
    testGameRules.push_back(make_pair(1,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(8,"Spade"));
    testGameRules.push_back(make_pair(10,"Spade"));
    testGameRules.push_back(make_pair(11,"Spade"));
    testGameRules.push_back(make_pair(12,"Spade"));


    driftWood = rules.unmatchedCards(testGameRules);
    int origUnmatched = driftWood.size();

    

    pullCardRiver(river);

    driftWood = rules.unmatchedCards(testGameRules);
    int newUnmatched = driftWood.size();
    for(auto it:driftWood){
        cout <<  it.first <<" of " << it.second << "s" << endl;
    }
    if(origUnmatched > newUnmatched){
        for(int i = 0; i < driftWood.size(); i++){
            for(int j = 0; i < hand.size(); j++){
                if((hand.at(i).first == hand.at(j).first) && (hand.at(i).first == hand.at(j).first)){
                    putCard(i, river);
                    //cout << hand.at(i).first << " of " << hand.at(i).second;
                }
            }
        }
    }
    else{
        
    }
    
}

