#include "Classes.h"

int main() {
    bool inputGood = false;
    int n;
    int counter = 0;
    cout << "Choose a game: \n- GET THE HIGHEST HAND (type 1)\n- Blackjack (type 2)" << endl;
    cin >> n;
    while(!inputGood){
        if(counter > 0){
            cout << "Input was incorrect. Please choose a game: \n- GET THE HIGHEST HAND (type 1)\n- Blackjack (type 2)" << endl;
            cin >> n;
        }
        if(n == 1){
            cout << endl;
            Dealer * d1 = new Dealer(1); //creates a dealer class that will control the rest of the "GET THE HIGHEST HAND" game
            inputGood = true;
        }
        else if(n == 2){
            cout << endl;
            Dealer * d1 = new Dealer(2); //creates a dealer class that will control the rest of the "blackjack" game
            inputGood = true;
        }
        counter++;
    }

    return 0;
}