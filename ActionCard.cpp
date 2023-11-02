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
    string instruction = getInstruction();
    
    //Regex patterns
    regex pattern(R"((DRAW|PLAY)\s+(\d+)\s+CARD(S)?|REVERSE\sHAND|SWAP\sHAND\sWITH\sOPPONENT)");

    return regex_match(instruction, pattern);
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
    // Print the card type
    cout << "Type: " << getType() << endl;

    // Print the instruction
    cout << "Instruction: " << getInstruction() << endl;

    // Print the image data or "No image data" if it's not available
    const int* imageData = getImageData();
    if (imageData != nullptr) {
        cout << "Card:" << endl;
        for (int i = 0; i < 80; i++) { 
            cout << imageData[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Card:\nNo image data" << endl;
    }
}