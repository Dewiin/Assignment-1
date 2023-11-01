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
    delete bitmap_;
    instruction_.clear();
    drawn_ = false;
}

/**
* Copy Constructor
* @post: Construct a new Card object
* @param: const reference to a Card object
*/
Card::Card(const Card& rhs) {
    bitmap_ = new int(*rhs.bitmap_);
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
}

/**
* Copy Assignment Operator
* @param const reference to a Card object
* @return this Card object
*/
Card& Card::operator=(const Card& rhs) {
    if(this != &rhs){
        *bitmap_ = *rhs.bitmap_;
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
    }

    return *this;
}

/**
* Move Constructor
* @param: rvalue reference to a Card object
*/
Card::Card(Card&& rhs) {
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;

    cardType_ = rhs.cardType_;

    instruction_ = rhs.instruction_;
    rhs.instruction_.clear();

    drawn_ = rhs.drawn_;
    rhs.drawn_ = false;
}

/**
* Move assignment operator
* @param: rvalue reference to a Card object
* @return this card object
*/
Card& Card::operator=(Card&& rhs) {
    swap(bitmap_, rhs.bitmap_);
    swap(cardType_, rhs.cardType_);
    swap(instruction_, rhs.instruction_);
    swap(drawn_, rhs.drawn_);

    return *this;
}

/**
* Default Constructor
* @post: Construct a new Card object
*/
Card::Card() {
    //all bitmap_ is nullptr
    bitmap_ = new int[80];
    instruction_ = "";
    drawn_ = false;
}

/**
* @return the string representation of the card type
*/
string Card::getType() const {
    string type;
    if(cardType_ == POINT_CARD){
        type = "POINT_CARD";
    }
    if(cardType_ == ACTION_CARD){
        type =  "ACTION_CARD";
    }
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