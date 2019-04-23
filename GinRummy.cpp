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

//Used this function after the round has ended by emptying the player and computer's hand. 
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
    vector<pair<int,string>> river; //River is the middle of the computer and player's hand and is picked up if player or computer want the discard the card from the hand.
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

    while((player.score < 100) && computer.score < 100){ //both computer and player keep playing the game until the both of the scores reach to 100. 
        deck.gameStart(river);
        while((rules.gin(player.hand) != 20) && (rules.gin(computer.hand) != 20)){ //keep playing until the gin called, which the points are equal to 20. 
            if (deck.getSize() == 0){
                deck.reshuffleDeck(river);//After the river deck reached the size 0, the deck is reshuffled. 
            }
            player.turn(deck, river, rules);
            computer.takeTurn(deck, river, rules);
            cout << deck.getSize() << endl;

        }
        if(rules.gin(player.hand) == 20){ //If gin(20 points for computer or player), then the round has ended. 
            rules.countScore(computer.hand);
            cout << "End of round!" << endl;
        }
        if(rules.gin(computer.hand) == 20){
            rules.countScore(player.hand);
            cout << "End of round!" << endl;
        }
        resetRound(deck, player, computer, river);//reset the round after round is over. 
    }
    
    
}

