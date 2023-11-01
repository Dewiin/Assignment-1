#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    Card* action_card = new PointCard();
    action_card->setInstruction("DRAW 17 CARDS");
    action_card->setDrawn(true);
    action_card->setImageData(nullptr);
    
    action_card->Print();
    cout << endl << action_card->isPlayable();
}