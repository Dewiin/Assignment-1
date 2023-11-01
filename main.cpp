#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


int main() {
    int* img_data;
    img_data = new int[10];

    for(auto i ){
        img_data[i] = i;
    }
    Card* action_card = new ActionCard();
    action_card->setImageData(img_data);

    action_card->Print();

}