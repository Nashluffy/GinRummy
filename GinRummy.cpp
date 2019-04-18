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

    Deck deck;
    Player player;
    Computer computer;
    GameRules rules;
    deck.shuffle();
    player.hand = deck.deal();
    //computer.hand = deck.deal();
    int score;

    computer.hand.push_back(make_pair(13,"Heart"));
    computer.hand.push_back(make_pair(1,"Spade"));
    computer.hand.push_back(make_pair(1,"Club"));
    computer.hand.push_back(make_pair(12,"Diamond"));
    computer.hand.push_back(make_pair(6,"Heart"));
    computer.hand.push_back(make_pair(9,"Spade"));
    computer.hand.push_back(make_pair(11,"Spade"));
    computer.hand.push_back(make_pair(2,"Diamond"));
    computer.hand.push_back(make_pair(7,"Spade"));
    computer.hand.push_back(make_pair(8,"Club"));


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