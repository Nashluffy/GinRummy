#include "Deck.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

// Created a deck with 52 cards. 
vector<pair<int,string>> Deck::deal(){
        vector<pair<int,string>> hand;
        for (auto i = deck.begin();  i != deck.end(); i++){
            if (hand.size() < 10){
                hand.push_back(*i);
                deck.erase(i);
            }
            else {
                return hand;
            }
        }
};

void Deck::shuffle(){
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
    cout << "Cards shuffled!" << endl; //Shuffled the cards before distributing the cards to player and computer. 
};

void Deck::gameStart(vector<pair<int,string>>& river){
    river.push_back(topCard());
    deck.erase(deck.begin());
};

Deck::Deck(){
    vector<string> suite; //pushing back a deck with suite. The pair consists the number and the string(suite).
    suite.push_back("Spade");
    suite.push_back("Heart");
    suite.push_back("Club");
    suite.push_back("Diamond");
    for (auto i = suite.begin(); i != suite.end(); i++) {
        for (int j = 1; j < 14; j++){
            pair <int, string> card;
            card = make_pair(j, *i);
            deck.push_back(card);
        }
    }
};

void Deck::reshuffleDeck(vector<pair<int,string>>& river){
    for (auto it:river){ 
        deck.push_back(it); //Put the card back into the deck. 
    }

    //Shuffle the deck
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
    
    river.clear(); //River is now empty
    river.push_back(deck.front()); //Take top card from deck and put in river
    deck.erase(deck.begin()); //Erase the top card from the deck
};
