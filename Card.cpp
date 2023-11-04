/*
    Name: Devin Xie
    Card implementation for Assignment 1
    CSCI 335 Fall Term 2023
*/

#include "Card.hpp"

/**
* Destructor
* @post: Destroy the Card object
*/
Card::~Card() {
    //delete allocated array
    delete[] bitmap_;
    //set pointer to nullptr
    bitmap_ = nullptr;
}

/**
* Copy Constructor
* @post: Construct a new Card object
* @param: const reference to a Card object
*/
Card::Card(const Card& rhs) {
    //allocate an empty array of 80 zeros
    bitmap_ = new int[80];

    // for(int i = 0; i < 80; i++){
    //     bitmap_[i] = rhs.bitmap_[i];
    // }

    //std::copy rhs bitmap to this->bitmap
    copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);

    //copy cardType
    cardType_ = rhs.cardType_;

    //copy instructions
    instruction_ = rhs.instruction_;

    //copy drawn bool
    drawn_ = rhs.drawn_;
}

/**
* Copy Assignment Operator
* @param const reference to a Card object
* @return this Card object
*/
Card& Card::operator=(const Card& rhs) {
    if(this != &rhs){
        //clear current bitmap
        if(bitmap_ != nullptr){
            delete[] bitmap_;
            bitmap_ = nullptr;
        }
        bitmap_ = new int[80];
        // for(int i = 0; i < 80; i++){
        //     bitmap_[i] = rhs.bitmap_[i];
        // }

        //std::copy
        copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);

        //copy cardType
        cardType_ = rhs.cardType_;
        
        //copy instructions
        instruction_ = rhs.instruction_;

        //copy drawn bool
        drawn_ = rhs.drawn_;
    }

    return *this;
}

/**
* Move Constructor
* @param: rvalue reference to a Card object
*/
Card::Card(Card&& rhs) {
    //copy bitmap
    bitmap_ = rhs.bitmap_;
    //clear rhs bitmap
    rhs.bitmap_ = nullptr;

    //copy cardType
    cardType_ = rhs.cardType_;

    //transfer ownership of instructions
    instruction_ = move(rhs.instruction_);

    //copy drawn bool
    drawn_ = rhs.drawn_;
    //reset rhs drawn bool
    rhs.drawn_ = false;
}

/**
* Move assignment operator
* @param: rvalue reference to a Card object
* @return this card object
*/
Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        //clear current bitmap
        delete[] bitmap_;

        //transfer bitmap ownership
        bitmap_ = rhs.bitmap_;
        //set rhs bitmap to nullptr
        rhs.bitmap_ = nullptr;

        //transfer cardType ownership
        cardType_ = rhs.cardType_;

        //transfer instruction ownership
        instruction_ = move(rhs.instruction_);

        //transfer drawn ownership
        drawn_ = rhs.drawn_;
        rhs.drawn_ = false;
    }

    return *this;
}

/**
* Default Constructor
* @post: Construct a new Card object
*/
Card::Card() {
    //allocate an empty array of 80 zeros
    bitmap_ = new int[80];

    //empty string of instructions
    instruction_ = "";

    //drawn set to false by default
    drawn_ = false;
}

/**
* @return the string representation of the card type
*/
string Card::getType() const {
   string type = (cardType_ == POINT_CARD) ? "POINT_CARD" : "ACTION_CARD";
   return type;
}

/**
* @post: set the card type
* @param const reference to a CardType object
*/
void Card::setType(const CardType& type){
    cardType_ = type;
}

/**
* @return the string representation of the card instruction
*/
const string& Card::getInstruction() const {
    return instruction_;
}

/**
* @post: set the card instruction
* @param: const reference to an instruction
*/
void Card::setInstruction(const string& instruction) {
    instruction_ = instruction;
}

/**
* @return the image data
*/
const int* Card::getImageData() const {
    return bitmap_;
}

/**
* @post: Set the image data
* @param pointer to an array of integers
*/
void Card::setImageData(int* data) {
    bitmap_ = data;
}

/**
* @return the drawn status of the card
*/
bool Card::getDrawn() const {
    return drawn_;
}

/**
* @post: set the drawn status of the card
*
* @param: const reference to a boolean
*/
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}