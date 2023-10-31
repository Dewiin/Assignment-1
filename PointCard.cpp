/*
Name: Devin Xie
Point Card implementation for Assignment 1
CSCI 335 Fall Term 2023
*/

#include "PointCard.hpp"

/**
 * @post: Construct a new Point Card object
 */
PointCard::PointCard() {
    Card* point_card = new PointCard();

    point_card->setImageData(nullptr);
    point_card->setType(POINT_CARD);
    point_card->setDrawn(false);
    point_card->setInstruction(point_card->getInstruction());
}
/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable() {
    for(char c : getInstruction()){
        if(!(int(c) >= 48 && int(c) <= 57)) {
            return false;
        }
    }
    if(getDrawn()){ 
        return true;
    }
    return false;
} 
/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void PointCard::Print() const {
    if(getImageData() == nullptr){
        cout << "Type: " << getType() << endl <<
        "Points: " << getInstruction() << endl <<
        "Card: No image data";
    }

    cout << "Type: " << getType() << endl <<
    "Points: " << getInstruction() << endl <<
    "Card: " << *getImageData();
}