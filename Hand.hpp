/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
Hand.cpp Defines the Hand class.
*/

#ifndef HAND_HPP
#define HAND_HPP

#include <deque>
#include "PointCard.hpp"

class Hand {
    public:
        // Big Five and constructor
        /**
         * @post: Construct a new Hand object
         */
        Hand();
        /**
         * @post: Destroy the Hand object
         */
        ~Hand();
        /**
         * Copy Constructor
         * @param: other Hand object
         */
        Hand(const Hand& other);
        /**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
        Hand& operator=(const Hand& other);
        /**
         * Move Constructor
         * @param: other Hand object
         */
        Hand(Hand&& other);
        /**
         * Move assignment operator
         * @param: other Hand object
         * @return this Hand
         */
        Hand& operator=(Hand&& other);

        /**
         * @return Hand
         */
        const deque<PointCard>& getCards() const;
        
        /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
        void addCard(PointCard&& card);

        /**
         * @return true if hand is empty, false otherwise
         */
        bool isEmpty() const;

        /**
         * @post: Reverse the hand
         */
        void Reverse();

        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int PlayCard();

    private:
        deque<PointCard> cards_;
};

#endif
