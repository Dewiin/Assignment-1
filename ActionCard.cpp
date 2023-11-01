/*
    Name: Devin Xie
    Action Card implementation for Assignment 1
    CSCI 335 Fall Term 2023
*/

#include "ActionCard.hpp"

/**
 * @post: Construct a new Action Card object
*/
ActionCard::ActionCard() {
    setType(ACTION_CARD);
    setInstruction(getInstruction());
}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be valid
 * Valid instructions:
 * DRAW x CARD(S) : assume x is a positive integer
 * PLAY x CARD(S) : assume x is a positive integer
 * REVERSE HAND : reverse the order of the cards in the hand
 * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable() {
    const regex pattern("^(DRAW \\d+ CARD(S)?|REVERSE HAND|PLAY \\d+ CARD(S)?|SWAP HAND WITH OPPONENT)$");

    if(regex_match(getInstruction(), pattern)){
        if(getDrawn()){
            return true;
        }
        return false;
    }
    return false;
}

/**
 * @post: Print the ActionCard in the following format:
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void ActionCard::Print() const {
    if(getImageData() == nullptr){
        cout << "Type: " << getType() << endl << 
        "Instruction: " << getInstruction() << endl <<
        "Card: No image data";
        return;
    }

    cout << "Type: " << getType() << endl << 
    "Instruction: " << getInstruction() << endl <<
    "Card: " << *getImageData();
}