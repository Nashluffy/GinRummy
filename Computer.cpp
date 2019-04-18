#include <vector>
#include <string>
#include <iostream>

#include "Computer.h"


using namespace std;

void Computer::takeTurn(Deck& deck, vector<pair<int,string>>& river, GameRules& rules){    
    vector<pair<int,string>> driftWood;         //Holds unmatched cards
    
    driftWood = rules.unmatchedCards(hand);     //Checks the hand for unmatched cards
    int origUnmatched = driftWood.size();       //and stores them
    
    pullCardRiver(river);                       //Draws the card from the river
    
    driftWood = rules.unmatchedCards(hand);     //Checks new hand
    int newUnmatched = driftWood.size();        

    if(origUnmatched > newUnmatched){                   //If the new hand has less unmatched cards
        for(int i = 0; i < driftWood.size(); i++){      //Compares the unmatched cards
            for(int j = 0; j < hand.size(); j++){       //to the hand
                if((driftWood.at(i).first == hand.at(j).first) && (driftWood.at(i).second == hand.at(j).second)){   //Finds the first unmatched card and
                    putCard(j, river);                                                                            //Sends it to the river
                    //cout << hand.at(i).first << " of " << hand.at(i).second << endl;                // Outputs the move to the player
                    cout << "Took River Card" << endl;

                    i = driftWood.size() - 1;           //Ends the loop
                    j = hand.size() - 1;
                }
            }
        }
    }
    else{
        putCard(hand.size()-1, river);          //If the new hand has more returns the drawn card to river
        pullCardDeck(deck);                         //Draws a card from the deck

        driftWood = rules.unmatchedCards(hand);     //Checks hand
        newUnmatched = driftWood.size();

        if(origUnmatched > newUnmatched){
            for(int i = 0; i < driftWood.size(); i++){      //Compares the unmatched cards
                for(int j = 0; j < hand.size(); j++){       //to the hand
                    if((driftWood.at(i).first == hand.at(j).first) && (driftWood.at(i).second == hand.at(j).second)){   //Finds the first unmatched card and
                        putCard(j, river);                                                                            //Sends it to the river
                        //cout << hand.at(i).first << " of " << hand.at(i).second << endl;                // Outputs the move to the player
                        cout << "Took Deck Card" << endl;

                        i = driftWood.size() - 1;           //Ends the loop
                        j = hand.size() - 1;
                    }
                }
            }
        }
        else{
            putCard(hand.size()-1, river);  //If card drawn from Deck has no use, put it on river
            cout << "Took No Card" << endl;
        }
    }
}

