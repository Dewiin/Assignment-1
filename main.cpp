#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    //point card 1
    PointCard point1 = PointCard();
    point1.setInstruction("4");
    //cout << point1.isPlayable() << endl;

    //point card 2
    PointCard point2 = PointCard();
    point2.setInstruction("3");
    //cout << point2.isPlayable();

    //point card 3
    PointCard point3 = PointCard();
    point3.setInstruction("6");
    //cout << point3.isPlayable();

    //point card 4
    PointCard point4 = PointCard();
    point4.setInstruction("14");
    //cout << point4.isPlayable();

    //deck
    Deck<PointCard> point_deck;
    point_deck.AddCard(point1);
    point_deck.AddCard(point2);
    point_deck.AddCard(point3);
    point_deck.AddCard(point4);

    PointCard drawn1 = point_deck.Draw();

    //hand
    Hand hand1;
    hand1.addCard(move(drawn1));
    hand1.addCard(move(point2));
    hand1.addCard(move(point3));
    hand1.addCard(move(point4));

    for(auto i : hand1.getCards()){
        cout << i.getDrawn() << endl;
    }
    
    return 0;
}