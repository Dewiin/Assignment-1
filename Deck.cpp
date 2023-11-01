/*
Name: Devin Xie
Sep 15, 2023
Implementation of Deck
*/

#include "Deck.hpp"

/**
* @post: Construct a new Deck object
*/
template <class CardType>
Deck<CardType>::Deck() {}

/**
* @post: Destroy the Deck object
*/
template <class CardType>
Deck<CardType>::~Deck() {
    cards_.clear();
}

/**
* @post: Add a Card to the Deck
* @param: const reference to CardType card
*/
template <class CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    cards_.push_back(card);
}

/**
* @post: Draw a card from the deck
* @pre: the deck is not empty
* @return the right hand value of type CardType
*/
template <class CardType>
CardType&& Deck<CardType>::Draw() {
    if(!IsEmpty()) { 
        CardType&& drawn = move(cards_.back());
        cards_.pop_back();

        return move(drawn);
    }
    throw runtime_error("Deck is empty.");
}  

/**
* @return if the deck is empty
*/
template <class CardType>
bool Deck<CardType>::IsEmpty() const {
    return cards_.empty();
}

/**
* @post: Shuffle the deck
* Create a random number generator using mt19937 with seed
2028358904,
* then call shuffle on the vector of cards, and with the random
number generator as the third argument.
* https://en.cppreference.com/w/cpp/algorithm/random shuffle
* https://en.cppreference.com/w/cpp/numeric/random/
mersenne twister engine
*/
template <class CardType>
void Deck<CardType>::Shuffle() {
    //create random number generator with mt19937
    mt19937 seed(2028358904);

    //shuffle with rng seed
    shuffle(cards_.begin(), cards_.end(), seed);
}

/**
* @return the size of the deck
*/
template <class CardType>
int Deck<CardType>::getSize() const {
    return cards_.size();
}

/**
* @return the vector of cards in the deck
*/
template <class CardType>
vector<CardType> Deck<CardType>::getDeck() const {
    return cards_;
}