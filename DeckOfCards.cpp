#include "Classes.h"

DeckOfCards::DeckOfCards(){
    currentCard = 0;
    deck = new Cards[52]; //initializes array in the heap

    for(int i = 0; i < 13; i++){ //for loop creates all of the cards
        for(int j = 0; j < 4; j++){
            Cards * c1 = new Cards(i, j);
            deck[currentCard] = *c1;
            currentCard++;
            delete c1;
        }
    }
    currentCard = 0; //sets value back to zero for future use
}

/*
// For testing purposes only (to see if deck was made)
string DeckOfCards::toString(){
   for(int i = 0; i < 52; i++){
       deck[i].toString();
   }
   return " ";
}
*/

DeckOfCards::~DeckOfCards(){
    delete deck; //deletes the array from the heap
}

void DeckOfCards::shuffle(){
    Cards * c2 = new Cards();
    int swap1 = 0;
    int swap2 = 0;
    srand(time(0));

    for(int i = 0; i < 100; i++){ //for loop shuffles deck randomly by swapping two cards 100 times
        swap1 = rand()%52;
        swap2 = rand()%52;
        *c2 = deck[swap1];
        deck[swap1] = deck[swap2];
        deck[swap2] = *c2;

    }

    delete c2;
}

Cards DeckOfCards::dealCard(){
    Cards * c3 = new Cards();
    Cards * c4 = new Cards(13, 4);
    if(moreCards()){ //checks if there are cards left
        *c3 = deck[currentCard];
        currentCard++;
        return *c3;
    }
    else{ //if no cards are left, card with identity, 0,0 is sent.
        cout << "There are no more cards" << endl;
        return *c4;
    }
}

bool DeckOfCards::moreCards(){
    if(currentCard >= 52){
        return false;
    }
    else{
        return true;
    }
}

int DeckOfCards::getCardsDelt(){
    return currentCard;
}
