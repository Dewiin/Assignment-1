#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    Card* point_card = new PointCard();
    point_card->setInstruction("9");
    
    point_card->Print();
}