//Game Rules Class 
    //Class Data Members
        //Vector to hold "set" rules
        //Vector to hold "run" rules
    //Class Member Functions
        //Check current hand against rules

//How to play the game
    //Place card down at index i
    


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "Deck.h"
#include "Computer.h"

using namespace std;

int main(){
    vector<pair<int,string>> river;
    vector<pair<int,string>> testGameRules;
    vector<pair<int,string>> matchedCards;
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

    Deck deck;
    Player player;
    Computer computer;
    GameRules rules;
    deck.shuffle();
    player.hand = deck.deal();
    computer.hand = deck.deal();
    int score;

   // player.turn(river, rules);

    //Testing for Computers turn
    river.push_back(make_pair(3,"Diamond"));
    for(auto it:river){
        cout <<  it.first <<" of " << it.second << "s" << endl;
    }

    computer.takeTurn(deck, river, rules);
    
    for(auto it:river){
        cout <<  it.first <<" of " << it.second << "s" << endl;
    }
    

      /*Testing for finding unmatched cards and Score
    matchedCards = rules.unmatchedCards(testGameRules);*/
    for (auto it:matchedCards){
        cout <<  it.first <<" of " << it.second << "s" << endl;
    }

    /*while(rules.unmatchedCards(computer.hand).second || rules.unmatchedCards(player.hand).second != 25 + (rules.unmatchedCards(computer.hand).second ||rules.unmatchedCards(player.hand).second))  {
        score = rules.countScore((rules.unmatchedCards(player.hand),rules.unmatchedCards(computer.hand))).second;
    }
    if(score < 100) {
        cout << "Not enough points. Play again!" << endl;
    }

    else {
        cout << "Game over!" << endl;
    }*/
    
}

//Next card needs to have different suit
//and same value to be set

//It is not a set if the next card has the same suit
//or a different value