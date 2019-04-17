#include <vector>
#include <string>
#include <iostream>

#include "Computer.h"

using namespace std;

void Computer::takeTurn(Deck deck, vector<pair<int,string>> river, GameRules rules){    
    vector<pair<int,string>> testHand;
    vector<pair<int,string>> driftWood;
    /*testHand.push_back(make_pair(1,"Spade"));
    testHand.push_back(make_pair(2,"Spade"));
    testHand.push_back(make_pair(3,"Spade"));
    testHand.push_back(make_pair(4,"Spade"));
    testHand.push_back(make_pair(5,"Spade"));
    testHand.push_back(make_pair(6,"Spade"));
    testHand.push_back(make_pair(7,"Spade"));
    testHand.push_back(make_pair(8,"Spade"));
    testHand.push_back(make_pair(9,"Spade"));
    testHand.push_back(make_pair(10,"Spade"));
    */
    cout << "t" << endl;

    driftWood = rules.unmatchedCards(hand);
    int origUnmatched = driftWood.size();

    cout << "test";
    pullCardRiver(river);
    driftWood = rules.unmatchedCards(hand);
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

