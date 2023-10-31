/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name
Date
PointCard.hpp defines the PointCard class and inherits from the Card Class.
*/
#ifndef POINTCARD_HPP
#define POINTCARD_HPP

#include <iostream>
#include <string>
#include "Card.hpp"

class PointCard : public Card
{
    public:
        /**
         * @post: Construct a new Point Card object
         */
        PointCard();
        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
        bool isPlayable() override; 
        /**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
        void Print() const override;
};
#endif