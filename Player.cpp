#include <vector>
#include <string>
#include <iostream>
#include "Player.h"


using namespace std;

vector<pair<int,string>> Player::putCard(int i, vector<pair<int,string>> river){
    hand.erase(hand.begin() + i);
    river.push_back(hand.at(i));
    return river;
};

void Player::displayHand(){
    int i = 1;
    for (auto it:hand){
        cout << i << ": " << it.first <<" of " << it.second << "s" << endl;
        i++;
    }
};

vector<pair<int,string>> Player::pullCardRiver(vector<pair<int,string>> river){
    hand.push_back(river.front());
};

vector<pair<int,string>> Player::pullCardDeck(vector<pair<int, string>> deck){
    hand.push_back(deck.front());
};

/*void Player::turn(vector<pair<int,string>> river){
    int choice;
    cout << "Your hand: " << endl;
    cout << displayHand << endl; 
    cout << "River: " << river << endl ;
    cout << "Enter 1 for gin, 2 for knock, 3 to draw from deck, 4 to pick up card from river." << endl;
    cin >> choice;
    if (choice = 1)
    {
        //rules.gin(hand);
    }
    if (choice = 2)
    {
       // rules.knock(hand);
    }
    if (choice = 3)
    {
        vector<pair<int,string>> choice2;
        pullCardDeck;
        cout << "Which card do you wish to discard? " << endl;
        cin >> choice2;
        putCard(choice2);
    }
    if (choice = 4)
    {
        vector<pair<int,string>> Choice3;
        pullCardRiver(river);
        cout << "Which card do you wish to discard?" << endl;
        cin >> Choice3;
        putCard(Choice3);

    }
    choice = 0;

};
*/
