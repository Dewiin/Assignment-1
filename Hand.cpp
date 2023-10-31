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
Hand::~Hand() {
    cards_.clear();
}

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
    cards_ = other.cards_;

    return *this;
}

/**
* Move Constructor
* @param: other Hand object
*/
Hand::Hand(Hand&& other) {
    cards_ = other.cards_;
    other.cards_.clear();
}

/**
* Move assignment operator
* @param: other Hand object
* @return this Hand
*/
Hand& Hand::operator=(Hand&& other) {
    cards_ = other.cards_;
    other.cards_.clear();

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
    deque<PointCard> new_hand;

    for(int i = cards_.size()-1; i >= 0; i--) {
        new_hand.push_back(cards_[i]);
    }

    cards_ = new_hand;
}

/**
* @post: Play the card at the front of the hand, removing it from the
hand
* Throws an exception if the hand is empty or the card is not playable
* If the card is not playable, the card is removed from the hand
* @return the points earned from playing the card
*/
int Hand::PlayCard() {
    if(isEmpty()) {
        cout << "Hand is empty.";
        return -1;
    }

    if(cards_.front().isPlayable()){
        int points = stoi(cards_[0].getInstruction());

        //remove card from hand
        cards_.pop_front();

        //move all cards back one index
        for(int i = 1; i < cards_.size(); i++) {
            cards_[i-1] = cards_[i];
        }

        //remove last index
        cards_.pop_back();
        
        return points;
    }
    else{
        cout << "Card is not playable";

        //remove card from hand
        cards_.pop_front();

        //move all cards back one index
        for(int i = 1; i < cards_.size(); i++) {
            cards_[i-1] = cards_[i];
        }

        return -1;
    }
}