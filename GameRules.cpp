#include "GameRules.h"
#include <bits/stdc++.h> 

using namespace std;


//The idea here is to return the deadwood (unmatched cards) as a vector, given a hand of cards
vector<pair<int,string>> GameRules::unmatchedCards(vector<pair<int,string>> hand){
    sort(hand.begin(), hand.end());
    vector<pair<int,string>> returnVector;
    returnVector = hand;
    //A set/run must contain at a minimum 3 cards, so look from first card to 8th card.
    for(int i = 0; i < returnVector.size() - 2; i++){
            //See if the next card could possibly form a run
            if ((returnVector.at(i).first + 1 == returnVector.at(i+1).first) && (returnVector.at(i).second == returnVector.at(i + 1).second)){
                int x = 2;
                //If the third card creates a set/run, it will enter this loop
                while ((i + x < returnVector.size()) && (returnVector.at(i + x).first == returnVector.at(i).first + x)){
                    x++; //Keep adding to this number to indicate how many cards are part of a run or set
                }
                if (x != 2){
                    //Delete the set/run from the hand
                    returnVector.erase(returnVector.begin() + i, returnVector.begin() + i + x );
                    i = 0;
                }
            }
            if (returnVector.empty()){ //This catches the case of Gin, so no error will be thrown
                i = -3;
            }
    }
    //Same as above, but for sets
    for(int i = 0; i < returnVector.size() - 2; i++){
        if (i < returnVector.size() && (returnVector.at(i).first == returnVector.at(i+1).first)){
            int x = 2;
            while((i + x < returnVector.size()) && (returnVector.at(i+x).first == returnVector.at(i).first)){
                x++;
            }
            if (x != 2){
                returnVector.erase(returnVector.begin() + i, returnVector.begin() + i + x);
                i = 0;
            }
        }
        if (returnVector.empty()){
            i = -3;
        }
    }
    
    
    return returnVector;
};


//Checks for gin if unmatchedCards call returns vector of size 0 (no unmatched cards) & returns the score
int GameRules::gin(vector<pair<int,string>> hand){
    vector<pair<int,string>> unCards;
    unCards = unmatchedCards(hand);
    if (unCards.size() == 0){
        return 20;
    }
    else{
        return 0;
    }
};

//Returns the score of the winning player, with the opposing hand being passed
int GameRules::countScore(vector<pair<int,string>>& player1){
    int score = 0;
    vector<pair<int,string>> unCards;
    unCards = unmatchedCards(player1);
    for(auto it:unCards){
        score = score + cardToScore(it);
    }
    return score;
};


//Converts face card values to their corresponding score value
int GameRules::cardToScore(pair<int,string> card){
    int cardValue;
    if(card.first < 11){
        cardValue = card.first;
    }
    else if(card.first > 10){
        cardValue = 10;
    }
    return cardValue;
};

