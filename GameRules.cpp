#include "GameRules.h"
#include <bits/stdc++.h> 

using namespace std;

vector<pair<int,string>> GameRules::unmatchedCards(vector<pair<int,string>> hand){
    sort(hand.begin(), hand.end());
    vector<pair<int,string>> returnVector;
    returnVector = hand;
    
    for(int i = 0; i < returnVector.size() - 2; i++){
            if ((returnVector.at(i).first + 1 == returnVector.at(i+1).first) && (returnVector.at(i).second == returnVector.at(i + 1).second)){
                int x = 2;
                while ((i + x < returnVector.size()) && (returnVector.at(i + x).first == returnVector.at(i).first + x)){
                    x++;
                }
                if (x != 2){
                    returnVector.erase(returnVector.begin() + i, returnVector.begin() + i + x );
                    i = 0;
                }
            }
            if (returnVector.empty()){
                i = -3;
            }
    }

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
int GameRules::countScore(vector<pair<int,string>>& player1){
    int score = 0;
    vector<pair<int,string>> unCards;
    unCards = unmatchedCards(player1);
    for(auto it:unCards){
        score = score + cardToScore(it);
    }
    return score;
};

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

