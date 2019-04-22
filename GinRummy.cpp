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
    
    Deck deck;
    Player player;
    Computer computer;
    GameRules rules;
    deck.shuffle();
    player.hand = deck.deal();
    computer.hand = deck.deal();
    cout << "Welcome to Gin Rummy!" << endl;

    while((player.score < 100) && computer.score < 100){
        deck.gameStart(river);
        while((rules.gin(player.hand) != 20) && (rules.gin(computer.hand) != 20)){
            if (deck.getSize() == 0){
                deck.reshuffleDeck(river);
            }
            player.turn(deck, river, rules);
            computer.takeTurn(deck, river, rules);
            cout << deck.getSize() << endl;

        }
        if(rules.gin(player.hand) == 20){
            rules.countScore(computer.hand);
            cout << "End of round!" << endl;
        }
        if(rules.gin(computer.hand) == 20){
            rules.countScore(player.hand);
            cout << "End of round!" << endl;
        }
        resetRound(deck, player, computer, river);
    }
    
    
}

