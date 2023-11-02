#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    //action card 1
    ActionCard action_card;
    action_card.setDrawn(true);
    action_card.setInstruction("DRAW 90 CARDS");
    cout << action_card.isPlayable();
    
    return 0;
}