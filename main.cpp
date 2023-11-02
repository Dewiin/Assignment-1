#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    PointCard point_card;
    point_card.setInstruction("9");
    point_card.Print();

    Hand hand;
    hand.addCard(move(point_card));

    deque<PointCard> temp = hand.getCards();

    for(int i = 0; i < temp.size(); i++){
        temp[i].Print();
    }
}