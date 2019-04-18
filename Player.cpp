#include <vector>
#include <string>
#include <iostream>
#include "Player.h"
#include <bits/stdc++.h> 

using namespace std;

void Player::putCard(int i, vector<pair<int,string>>& river){
    river.push_back(hand.at(i));
    hand.erase(hand.begin() + i);
};

void Player::displayHand(){
    int i = 0;
    sort(hand.begin(), hand.end());
    for (auto it:hand){
        string cardName;
        if((it.first < 11) && (it.first > 1)){
            cardName = to_string(it.first);
        }
        else if(it.first == 11){
            cardName = "Jack";
        }
        else if(it.first == 12){
            cardName = "Queen";
        }
        else if(it.first == 13){
            cardName = "King";
        }
        else if (it.first == 1 ){
            cardName = "Ace";
        }
        cout << (i+1) << ": " << cardName <<" of " << hand.at(i).second << "s";
        cout << endl;
        i++;
    }
};

void Player::turn(Deck& deck, vector<pair<int,string>>& river, GameRules rules){
    int choice =0;
    cout << "Your hand: " << endl;
    displayHand();
    cout << "River: " << endl;
    cout << river.front().first << " of " << river.front().second << "s" << endl;
    while(choice != 1 && choice != 2){
    cout << "Enter 1 to draw from deck, 2 to pick up card from river." << endl;
    cin >> choice;

    }
    if (choice == 1)
    {
        int choice2;
        pullCardDeck(deck);
        cout << "Which card do you wish to discard? " << endl;
        cin >> choice2;

        putCard(choice2 - 1, river);
        displayHand();

    }
    
    else if (choice == 2)
    {
        int Choice3;
        pullCardRiver(river);
        cout << "Which card do you wish to discard?" << endl;
        cin >> Choice3;
        putCard(Choice3 - 1, river);
        displayHand();

    }
    else
    {
     cout << "Invalid selection" <<endl;
    }
    
    choice = 0;

}

void Player::pullCardRiver(vector<pair<int,string>>& river){
    hand.push_back(river.front());
    river.erase(river.begin());
};

void Player::pullCardDeck(Deck& deck){
    hand.push_back(deck.topCard());
    deck.deck.erase(deck.deck.begin());
};