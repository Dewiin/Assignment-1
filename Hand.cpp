/*
Name: Devin Xie
Hand implementation for Assignment 1
CSCI 335 Fall Term 2023
*/

#include "Hand.hpp"

/**
* @post: Construct a new Hand object
*/
Hand::Hand() {}

/**
* @post: Destroy the Hand object
*/
Hand::~Hand() {}

/**
* Copy Constructor
* @param: other Hand object
*/
Hand::Hand(const Hand& other) {
    cards_ = other.cards_;
}

/**
* Copy Assignment Operator
* @param: other Hand object
* @return this Hand
*/
Hand& Hand::operator=(const Hand& other) {
    if(this != &other){
        cards_ = other.cards_;
    }

    return *this;
}

/**
* Move Constructor
* @param: other Hand object
*/
Hand::Hand(Hand&& other) {
    //transfer contents
    cards_ = move(other.cards_);
}

/**
* Move assignment operator
* @param: other Hand object
* @return this Hand
*/
Hand& Hand::operator=(Hand&& other) {
    if(this != &other){
        //transfer contents
        cards_ = move(other.cards_);
    }

    return *this;
}

/**
* @return Hand
*/
const deque<PointCard>& Hand::getCards() const {
    return cards_;
}

/**
* @post: Add a card to the hand
* @param PointCard object
*/
void Hand::addCard(PointCard&& card) {
    card.setDrawn(true);
    cards_.push_back(card);
}

/**
* @return true if hand is empty, false otherwise
*/
bool Hand::isEmpty() const {
    return cards_.empty();
}

/**
* @post: Reverse the hand
*/
void Hand::Reverse() {
    // size_t i = 0, j = cards_.size()-1;
    // while(i < j){
    //     swap(cards_[i], cards_[j]);
    //     i++;
    //     j--;
    // }

    //std::reverse
    reverse(cards_.begin(), cards_.end());
}

/**
* @post: Play the card at the front of the hand, removing it from the
hand
* Throws an exception if the hand is empty or the card is not playable
* If the card is not playable, the card is removed from the hand
* @return the points earned from playing the card
*/
int Hand::PlayCard() {
    //check if not empty
    if(!isEmpty()) {
        //if not playable
        if(!cards_.front().isPlayable()){
            //remove from hand
            cards_.pop_front();
            //throw exception
            throw runtime_error("Card is not playable.");
        }
        //else (if playable)

        //get the integer value of the points in the front card of the hand
        int points = stoi(cards_.front().getInstruction());
        //remove from hand
        cards_.pop_front();
        //return points
        return points;
    }
    //else (if empty)

    //throw exception   
    throw runtime_error("Hand is empty.");
}