#include "GameRules.h"
#include <bits/stdc++.h> 

using namespace std;

vector<pair<int,string>> GameRules::unmatchedCards(vector<pair<int,string>> hand){
    sort(hand.begin(), hand.end());
    vector<pair<int,string>> returnVector;
    returnVector = hand;
    
    //Pull out the runs from the deck
    for(int i = 0; i < returnVector.size() - 2; i++){
        if (returnVector.at(i).first + 1 == returnVector.at(i+1).first){
            int x = 2;
            while ((i + x < returnVector.size()) && (returnVector.at(i + x).first == returnVector.at(i).first + x)){
                x++;
            }
            if (x != 2){
                returnVector.erase(returnVector.begin() + i, returnVector.begin() + i + x );
                i = 0;
            }
        }

    }

    //Pull out the sets from the deck
    //Check if the next card is equal to current card
        //While next card is equal to current card, increment x
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
    }


    return returnVector;
};

int GameRules::gin(vector<pair<int,string>> hand){
    if (hand.empty()){
        return 20;
    }
    else{
        return 0;
    }
};
int GameRules::countScore(vector<pair<int,string>> player1, vector<pair<int,string>> player2){
    int score = 0;
    
    for (auto it:player1){
        if(it.first < 11){

        }
    }
};