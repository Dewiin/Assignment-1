#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    //point card 1
    PointCard point1;
    point1.setInstruction("4");
    //cout << point1.isPlayable() << endl;
    point1.Print();
    cout << endl;

    //point card 2
    PointCard point2; 
    point2.setInstruction("3");
    //cout << point2.isPlayable();

    //point card 3
    PointCard point3; 
    point3.setInstruction("6");
    //cout << point3.isPlayable();

    //point card 4
    PointCard point4; 
    point4.setInstruction("14");
    //cout << point4.isPlayable();

    //deck
    Deck<PointCard> point_deck;
    point_deck.AddCard(point1);
    point_deck.AddCard(point2);
    point_deck.AddCard(point3);
    point_deck.AddCard(point4);

    
    PointCard drawn2 = point_deck.Draw();
    PointCard drawn3 = point_deck.Draw();
    PointCard drawn4 = point_deck.Draw();


    //hand
    // Hand hand1;
    // hand1.addCard();
    // hand1.addCard();
    // hand1.addCard();
    // hand1.addCard();

    // for(auto i : hand1.getCards()){
    //     cout << i.getDrawn() << endl;
    // }

    return 0;
}