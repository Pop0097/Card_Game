#include "Classes.h"

Cards::Cards(){
    face = 0;
    suit = 0;
    faceValue = 0;
}


Cards::Cards(int inputFace, int inputSuit){
    face = inputFace;
    suit = inputSuit;
    faceValue = inputFace;
}

string Cards::toString(){
    cout << faces[face] << " of " << suits[suit] << endl;
    return " ";
}

int Cards::getFace(){
    return face;
}

int Cards::getSuit(){
    return suit;
}

int Cards::getFaceValue(){
    return faceValues[faceValue];
}






