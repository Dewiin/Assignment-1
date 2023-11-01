/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Devin Xie
Date: Oct 27 2023
Player.cpp implements the Player class.
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Hand.hpp" 
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"

class Player 
{
    public:
        /**
         * @post: Construct a new Player object
         */
        Player();

        /**
         * @post: Destroy the Player object
         */
        ~Player();

        /**
         * @return the player's hand
         */
        const Hand& getHand() const;
        /**
         * @post: Set the player's hand
         * @param const reference to a hand object
         */
        void setHand(const Hand& hand);

        /**
         * @return the Player's current score
         */
        int getScore() const;
        /**
         * @post: Set the player's score
         * @param: score 
         */
        void setScore(const int& score);

        /**
         * @post: Play a given action card
         * @param: an Actioncard object
         * Begin the function by reporting the instruction of the card:
         * PLAYING ACTION CARD: [instruction]
         */
        void play(ActionCard&& card);

        /**
         * @post: Draw a point card and place it in the player's hand
         */
        void drawPointCard();
        /**
         * @post: Play a point card from the player's hand and update the player's score
         */
        void playPointCard();

        /**
         * @post: Set the opponent of the player
         * @param a pointer to a Player opponent 
         */
        void setOpponent(Player* opponent);
        /**
         * @return: a pointer to the player's opponent
         */
        Player* getOpponent();

        /**
         * @post: set the action deck of the player 
         * @param: A pointer to a deck holding Action cards 
         */
        void setActionDeck(Deck<ActionCard>* actiondeck);
        
        /**
         * @return a pointer to the player's action deck
         */
        Deck<ActionCard>* getActionDeck();

        /**
         * @post: set the point deck of the player
         * @param: A pointer to a deck holding Point cards
         */
        void setPointDeck(Deck<PointCard>* pointdeck);
        /**
         * @return: a pointer to the player's point deck
         */
        Deck<PointCard>* getPointDeck();
        
    private:
        Hand hand_;   // The player's hand
        int score_;  // The player's score
        Player* opponent_; // A pointer to another player opponent
        Deck<ActionCard>* actiondeck_; // A pointer to a deck
        Deck<PointCard>* pointdeck_; // A pointer to a deck

};

#endif
