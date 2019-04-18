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

#include "Computer.h"

using namespace std;

void resetRound(Deck& deck, Player& player, Computer& computer, vector<pair<int,string>>& river){
    Deck newDeck;
    deck = newDeck;
    player.hand.clear();
    player.hand = deck.deal();
    computer.hand.clear();
    computer.hand = deck.deal();
    river.clear();
}

int main(){
    vector<pair<int,string>> river;
    vector<pair<int,string>> testGameRules;
    vector<pair<int,string>> matchedCards;
    testGameRules.push_back(make_pair(1,"Spade"));
    testGameRules.push_back(make_pair(1,"Diamond"));
    testGameRules.push_back(make_pair(1,"Club"));
    testGameRules.push_back(make_pair(1,"Heart"));
    testGameRules.push_back(make_pair(3,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(7,"Spade"));
    testGameRules.push_back(make_pair(10,"Heart"));
    testGameRules.push_back(make_pair(10,"Club"));
    testGameRules.push_back(make_pair(10,"Spade"));

    Deck deck;
    Player player;
    Computer computer;
    GameRules rules;
    deck.shuffle();
    player.hand = deck.deal();
    computer.hand = deck.deal();

    while((player.score < 100) && computer.score < 100){
        deck.gameStart(river);
        while((rules.gin(player.hand) != 20) && (rules.gin(computer.hand) != 20)){
            player.turn(deck, river, rules);
            computer.takeTurn(deck, river, rules);
        }
        if(rules.gin(player.hand) == 20){
            rules.countScore(computer.hand);
        }
        resetRound(deck, player, computer, river);
    }
    
    
}

