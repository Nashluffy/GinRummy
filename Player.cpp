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

vector<pair<int,string>> Player::pullCardRiver(vector<pair<int,string>>& river){
    hand.push_back(river.front());
    river.erase(river.begin());
};

vector<pair<int,string>> Player::pullCardDeck(vector<pair<int, string>>& deck){
    hand.push_back(deck.front());
    deck.erase(deck.begin());
};