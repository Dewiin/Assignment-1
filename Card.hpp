/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Devin Xie
Date: Oct 27 2023
Card.hpp defines the Card class and its member functions.
*/

#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
using namespace std;

enum CardType 
{
    POINT_CARD,
    ACTION_CARD
};

class Card
{
    public:
        // Big Five and Constructor
        /**
         * Destructor
         * @post: Destroy the Card object
        */
        ~Card();
        /**
         * Copy Constructor
         * @post: Construct a new Card object
         * @param: const reference to a Card object
        */
        Card(const Card& rhs);
        /**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
        Card& operator=(const Card& rhs);
        /**
         * Move Constructor
         * @param: rvalue reference to a Card object 
        */
        Card(Card&& rhs);
        /**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
        Card& operator=(Card&& rhs);
        /**
         * Default Constructor
         * @post: Construct a new Card object 
         */
        Card();

        /**
         * @return the string representation of the card type
         */
        string getType() const;
        /**
         * @post: set the card type
         * @param const reference to a CardType object
         */
        void setType(const CardType& type);

        /**
         * @return the string representation of the card instruction
        */
        const string& getInstruction() const;
        /**
         * @post: set the card instruction
         * @param: const reference to an instruction 
         */
        void setInstruction(const string& instruction);

        /**
         * @return the image data
         */
        const int* getImageData() const;
        /**
         * @post: Set the image data
         * @param pointer to an array of integers
         */
        void setImageData(int* data);

        /**
         * @return the drawn status of the card
        */
        bool getDrawn() const;
        /**
         * @post: set the drawn status of the card
         * 
         * @param: const reference to a boolean
         */
        void setDrawn(const bool& drawn);

        // Pure Virtual Functions
        virtual void Print() const = 0;
        virtual bool isPlayable() = 0;

    private:
        CardType cardType_;
        string instruction_;
        int* bitmap_;
        bool drawn_;
};

#endif
