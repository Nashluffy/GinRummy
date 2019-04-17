#include <vector>
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

void Player::putCard(int i, vector<pair<int,string>>& river){
    hand.erase(hand.begin() + i);
    river.push_back(hand.at(i));
};

void Player::displayHand(){
    int i = 1;
    for (auto it:hand){
        cout << i << ": " << it.first <<" of " << it.second << "s" << endl;
        i++;
    }
};

void Player::turn(Deck deck, vector<pair<int,string>> river, GameRules rules){
    int choice;
    cout << "Your hand: " << endl;
    displayHand();
    cout << "River: " << endl;
     for( auto it:river){
        cout << it.first << " of " << it.second << endl; 
    }
    cout << "Enter 1 for gin, 2 to draw from deck, 3 to pick up card from river." << endl;
    cin >> choice;
    if (choice == 1)
    {
        rules.gin(hand);
    }
    else if (choice == 2)
    {
        int choice2;
        pullCardDeck(deck);
        cout << "Which card do you wish to discard? " << endl;
        cin >> choice2;

        putCard(choice2 - 1, river);
        displayHand();
    }
    
    else if (choice == 3)
    {
        int Choice3;
        pullCardRiver(river);
        cout << "Which card do you wish to discard?" << endl;
        cin >> Choice3;
        putCard(Choice3, river);

    }
    else
    {
     cout << "Invalid selction" <<endl;
    }
    
    choice = 0;

}

void Player::pullCardRiver(vector<pair<int,string>> river){
    hand.push_back(river.front());
    river.erase(river.begin());
};

void Player::pullCardDeck(Deck& deck){
    hand.push_back(deck.topCard());
    deck.deck.erase(deck.deck.begin());
};