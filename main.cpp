#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    //point card 1
    PointCard point_card;
    point_card.setInstruction("9");
    point_card.setDrawn(true);

    //point card 2
    PointCard point_card_2;
    point_card_2.setInstruction("5");
    point_card_2.setDrawn(true);

    //point card 3
    PointCard point_card_3;
    point_card_3.setInstruction("7");
    point_card_3.setDrawn(true);

    //point card 4
    PointCard point_card_4;
    point_card_4.setInstruction("2");
    
    //hand
    Hand hand;
    hand.addCard(move(point_card));
    hand.addCard(move(point_card_2));
    hand.addCard(move(point_card_3));
    hand.addCard(move(point_card_4));

    deque<PointCard> temp = hand.getCards();

    for(int i = 0; i < temp.size(); i++){
        cout << hand.PlayCard() << endl;
    }

}