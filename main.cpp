#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    Card* action_card = new ActionCard();
    action_card->setInstruction("DRAW 7 CARDS");
    action_card->setDrawn(true);

    action_card->Print();
    cout << endl << action_card->isPlayable();
}