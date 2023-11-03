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
    setType(POINT_CARD);
}
/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable() {
    if(!getDrawn()){ 
        return false;
    }
    for(char c : getInstruction()){
        if(!isdigit(c)) {
            return false;
        }
    }
    if(!(1 <= stoi(getInstruction()) <= 99)){
        return false;
    }
    return true;
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
    //Print the card type
    cout << "Type: " << getType() << endl;

    //Print the points
    cout << "Points: " << getInstruction() << endl;

    //Print the image data or "No image data" if it's not available
    const int* image_data = getImageData();
    if(getImageData() != nullptr) {
        cout << "Card:" << endl;
        for(int i = 0; i < 80; i++){
            cout << image_data[i] << " ";
        }
    }
    else{
        cout << "Card:\nNo image data" << endl;
    }
}