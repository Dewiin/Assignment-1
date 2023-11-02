#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    //point card 1
    PointCard point1; 
    point1.setDrawn(true);
    point1.setInstruction("4");
    //cout << point1.isPlayable();

    //point card 2
    PointCard point2; 
    point2.setDrawn(true);
    point2.setInstruction("3");
    //cout << point2.isPlayable();

    //point card 3
    PointCard point3; 
    point3.setDrawn(true);
    point3.setInstruction("6");
    //cout << point3.isPlayable();

    //point card 4
    PointCard point4; 
    point4.setDrawn(true);
    point4.setInstruction("14");
    //cout << point4.isPlayable();

    //hand
    Hand hand1;
    hand1.addCard(move(point1));
    hand1.addCard(move(point2));
    hand1.addCard(move(point3));
    hand1.addCard(move(point4));

    Hand hand2;
    hand2 = hand1;

    for(auto i : hand2.getCards()){
        cout << hand2.PlayCard() << endl;
    }


    return 0;
}