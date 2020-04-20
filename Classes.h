#include <iostream>
#include <string>
#include <array>
#include <cstdlib>

using namespace std;

/*defines Card class*/

#ifndef CARDS_H_
#define CARDS_H_

class Cards{
private:
    int face;
    int suit;
    int faceValue;
public:
    Cards(); //default constructor
    Cards(int, int); //constructor to create specific cards
    string toString(); //prints card
    int getFace();
    int getSuit();
    int getFaceValue();
};

//Extra "NULL"s added so if the dealer runs out of cards, he knows.
static const string faces[] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace", "NULL"};
static const int faceValues[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1}; //values of the faces for the blackjack game
static const string suits[] = {"Hearts", "Clubs", "Spades", "Diamonds", "NULL"};

#endif /* CARDS_H_ */

/*defines DeckOfCards class*/

#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_

class DeckOfCards{
private:
    int currentCard;
    const int SIZE_OF_DECK = 52;
    Cards * deck;
public:
    DeckOfCards(); //constructs the deck of cards
    //string toString(); //for testing purposes only
    ~DeckOfCards(); //destructor
    void shuffle(); //shuffles deck
    Cards dealCard(); //deals a card
    bool moreCards(); //checks if more cards can be dealt
    int getCardsDelt();
};

#endif /* DECKOFCARDS_H_ */

/*defines Dealer class*/

#ifndef DEALER_H_
#define DEALER_H_

class Dealer{
private:
    int gameType;
    DeckOfCards deck1;
    Cards player1Cards[15]; //these two arrays store the player's cards.
    Cards player2Cards[15];
    string playerHands[2];
    int playerScores[2];
    //blackJack only
    int dealerCardCount;
public:
    Dealer(int);
    //for the "GET THE HIGHEST HAND" game
    void dealHands(); //dealer deals hands here
    void displayHands(); //displays the players' hands
    void identifyHand(int); //identify hands and gives each player a score.
    int determineWinner();
    //for BlackJack
    void dealTwoCards();
    void displayPlayerCards(int);
    bool dealerTakeCard();
};

#endif /* DEALER_H_ */