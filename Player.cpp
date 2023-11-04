/*
Name: Devin Xie
Player implementation for Assignment 1
CSCI 335 Fall Term 2023
*/

#include "Player.hpp"

/**
* @post: Construct a new Player object
*/
Player::Player(){
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

/**
* @post: Destroy the Player object
*/
Player::~Player() {
    //delete actiondeck
    if(actiondeck_ != nullptr){
        delete actiondeck_;
    }

    //delete pointdeck
    if(pointdeck_ != nullptr){
        delete pointdeck_;
    }

    //delete opponent
    if(opponent_ != nullptr){
        delete opponent_;
    }
}

/**
* @return the player’s hand
*/
const Hand& Player::getHand() const {
    return hand_;
}

/**
* @post: Set the player’s hand
* @param const reference to a hand object
*/
void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

/**
* @return the Player’s current score
*/
int Player::getScore() const {
    return score_;
}

/**
* @post: Set the player’s score
* @param: score
*/
void Player::setScore(const int& score) {
    score_ = score;
}

/**
* @post: Play a given action card
* @param: an Actioncard object
* Begin the function by reporting the instruction of the card:
* PLAYING ACTION CARD: [instruction]
*/
void Player::play(ActionCard&& card) {
    //if the card is playable
    if(card.isPlayable()){
        string instructions = card.getInstruction();

        //report the instructions of the card
        cout << "PLAYING ACTION CARD: " << instructions << endl;

        //REVERSE HAND
        if(instructions == "REVERSE HAND") {
            hand_.Reverse();
        }

        //SWAP HAND WITH OPPONENT
        if(instructions == "SWAP HAND WITH OPPONENT") {
            if(opponent_ != nullptr){
                //move constructor to make temp hand
                Hand temp = hand_;
                //swap this->hand with opponent
                setHand(opponent_->getHand());
                //opponent swaps hand with this->hand
                opponent_->setHand(temp);
            }
        }  

        //DRAW|PLAY
        else{ 
            //initialize vector to store each word in the instruction
            vector<string> parsed_words;
            //initialize a string to append each character that is not whitespace
            string word = "";

            //parsing through the instructions
            for(int i = 0; i < instructions.size(); i++){
                //if whitespace
                if(instructions[i] == ' '){
                    //push back the word into the vector
                    parsed_words.push_back(word);
                    //reset
                    word = "";
                }
                
                //if not whitespace
                else{
                    //append the character
                    word += instructions[i];
                }
            }

            //if draw
            if(parsed_words[0] == "DRAW"){
                for(int i = 0; i < stoi(parsed_words[1]); i++){
                    drawPointCard();
                }
            }
            //if play
            else{
                for(int i = 0; i < stoi(parsed_words[1]); i++){
                    playPointCard();
                }
            }
        }
    }
}

/**
* @post: Draw a point card and place it in the player’s hand
*/
void Player::drawPointCard() {
    if(pointdeck_ != nullptr){
        hand_.addCard(pointdeck_->Draw());
    }
}

/**
* @post: Play a point card from the player’s hand and update the player’
s score
*/
void Player::playPointCard() {
    setScore(getScore() + hand_.PlayCard());
}

/**
* @post: Set the opponent of the player
* @param a pointer to a Player opponent
*/
void Player::setOpponent(Player* opponent) {
    opponent_ = opponent;
}

/**
* @return: a pointer to the player’s opponent
*/
Player* Player::getOpponent() {
    return opponent_;
}

/**
* @post: set the action deck of the player
* @param: A pointer to a deck holding Action cards
*/
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

/**
* @return a pointer to the player’s action deck
*/
Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

/**
* @post: set the point deck of the player
* @param: A pointer to a deck holding Point cards
*/
void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

/**
* @return: a pointer to the player’s point deck
*/
Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}