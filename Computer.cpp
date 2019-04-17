#include <vector>
#include <string>
#include <iostream>

#include "Computer.h"


using namespace std;

void Computer::takeTurn(Deck& deck, vector<pair<int,string>>& river, GameRules& rules){    
    vector<pair<int,string>> driftWood;

    vector<pair<int,string>> testGameRules;
    /*testGameRules.push_back(make_pair(1,"Spade"));
    testGameRules.push_back(make_pair(1,"Diamond"));
    testGameRules.push_back(make_pair(1,"Club"));
    testGameRules.push_back(make_pair(1,"Heart"));
    testGameRules.push_back(make_pair(3,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(10,"Heart"));
    testGameRules.push_back(make_pair(10,"Club"));
    testGameRules.push_back(make_pair(10,"Spade"));*/

    driftWood = rules.unmatchedCards(hand);
    int origUnmatched = driftWood.size();
    
    pullCardRiver(river);
    
    driftWood = rules.unmatchedCards(hand);
    int newUnmatched = driftWood.size();
   
    cout << origUnmatched << " " << newUnmatched<<endl;

    if(origUnmatched > newUnmatched){
        for(int i = 0; i < driftWood.size(); i++){
            for(int j = 0; j < hand.size(); j++){
                if((driftWood.at(i).first == hand.at(j).first) && (driftWood.at(i).second == hand.at(j).second)){
                    putCard(i, river);
                    cout << hand.at(i).first << " of " << hand.at(i).second;
                    cout << " " << hand.size() << endl;
                    i = driftWood.size() - 1;
                    j = hand.size() - 1;
                }
            }
        }
    }
    else{
        
    }
    
}

