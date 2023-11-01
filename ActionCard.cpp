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
    if(!getDrawn()){
        return false;
    }

    //Regex patterns
    regex drawPlayPattern(R"(^(DRAW|PLAY) (\d+) CARD(S)?$)");
    regex reversePattern(R"(^REVERSE HAND$)");
    regex swapPattern(R"(^SWAP HAND WITH OPPONENT$)");

    if( regex_match(getInstruction(), drawPlayPattern) || 
        regex_match(getInstruction(), reversePattern) ||
        regex_match(getInstruction(), swapPattern) ) {
        return true;
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