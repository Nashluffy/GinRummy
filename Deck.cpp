#include "Deck.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>


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
    cout << "Cards shuffled!" << endl;
};

void Deck::gameStart(vector<pair<int,string>>& river){
    river.push_back(topCard());
    deck.erase(deck.begin());
};

Deck::Deck(){
    vector<string> suite;
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
    cout << "Welcome to Gin Rummy!" << endl;
};