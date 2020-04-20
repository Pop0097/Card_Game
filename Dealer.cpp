#include "Classes.h"

Dealer::Dealer(int game){
    gameType = game;
    if(gameType == 1){ //to play the game GET THE HIGHEST HAND
        cout << "Welcome to the game \"GET THE HIGHEST HAND\"!" << endl;
        cout << "The dealer will hand out two hands. The person with the higest hand wins!" << endl;
        cout << endl;
        cout << "Scoring works as follows: player with the highest hand wins. If both players have the same hand, then player with the highest cards wins. Should there be a tie, then the game will end in a draw" << endl;
        cout << endl;

        dealHands();
        displayHands();
        identifyHand(1); //dealer identifies hand for player 1
        identifyHand(2); //dealer identifies hand for player 2
        int winner = determineWinner();
        if(winner == 1){
            cout << "Player 1 wins with a " << playerHands[0] << "!" << endl;
            cout << "Player 2, you recieved a " << playerHands[1] << endl;
        } else if(winner == 2){
            cout << "Player 2 wins with a " << playerHands[1] << "!" << endl;
            cout << "Player 1, you recieved a " << playerHands[0] << endl;
        } else{
            cout << "It is a tie! You both recieved a " << playerHands[0] << endl;
        }
    }
    else{ //to play blackJack
        cout << "Welcome to the game Black Jack. Both you and the dealer will recieve two cards. Afterwards, you can choose to either recieve another card or end your turn. The goal is for the sum of your cards to be as close to 21 as possible. If you are above 21, you lose. Good luck!" << endl;
        cout << endl;

        dealTwoCards();

        int n = 0;
        int counter = 2;
        playerScores[0] = player1Cards[0].getFaceValue() + player1Cards[1].getFaceValue();
        playerScores[1] = player2Cards[0].getFaceValue() + player2Cards[1].getFaceValue();
        dealerCardCount = 2;
        bool dealerDone = false;
        while(n != 2 && playerScores[0] < 21){ //displays players cards and also
            dealerDone = dealerTakeCard(); //dealer chooses whether it will take a card
            cout << "Your cards are:" << endl;
            displayPlayerCards(counter);
            cout << "Your current Score is " << playerScores[0] << endl;
            cout << "Do you want another card? (1 = yes. 2 = no)" << endl;
            cin >> n;
            cout << endl;
            if(n != 2){ //if player inputs 2, card is not delt
                player1Cards[counter] = deck1.dealCard();
                playerScores[0] += player1Cards[counter].getFaceValue();
                counter++;
            }
        }

        cout << "Your cards are:" << endl;
        displayPlayerCards(counter);
        if(playerScores[0] <= 21){
            while(!dealerDone){ //makes sure dealer is done taking cards
                dealerDone = dealerTakeCard(); //dealer chooses whether it will take a card
            }
            //determins if player wins
            if((playerScores[0] > playerScores[1]) || playerScores[1] > 21){//player wins
                cout << "You won! Your score was " << playerScores[0] << " and the dealer's score was " << playerScores[1] << endl;
            }
            else if(playerScores[0] < playerScores[1]){//player wins
                cout << "You lost! Your score was " << playerScores[0] << " and the dealer's score was " << playerScores[1] << endl;
            }
            else{
                cout << "You tied! Your score was " << playerScores[0] << " and the dealer's score was " << playerScores[1] << endl;
            }
        }
        else{ //If player busts, dealer automatically wins
            cout << "Busted! Your score is above 21. The Dealer wins" << endl;
            cout << "Your score was " << playerScores[0] << ". The Dealer's score was " << playerScores[1] << endl;
        }
    }
}

void Dealer::dealHands(){
    deck1.shuffle(); //shuffles deck
    //deck1.toString();

    //dealer deals hands
    int player = 1;
    int counter1 = 0;
    int counter2 = 0;

    for(int i = 0; i < 10; i++){
        if(player == 1){
            player1Cards[counter1] = deck1.dealCard();
            player++;
            counter1++;
        }
        else if(player == 2){
            player2Cards[counter2] = deck1.dealCard();
            player = 1;
            counter2++;
        }
    }
}

void Dealer::displayHands(){
    cout << "Player 1's cards were: " << endl;
    for(int i = 0; i < 5; i++){
        player1Cards[i].toString();
    }
    cout << endl;

    cout << "Player 2's cards were:" << endl;
    for(int i = 0; i < 5; i++){
        player2Cards[i].toString();
    }
    cout << endl;
}

void Dealer::identifyHand(int player){
    //creates new arrays to store the faces and suits that the players posess.
    int playerFaces[5];
    int playerSuits[5];

    if(player == 1){
        for(int i = 0; i < 5; i++){
            playerFaces[i] = player1Cards[i].getFace();
            playerSuits[i] = player1Cards[i].getSuit();
        }
    }
    else{
        for(int i = 0; i < 5; i++){
            playerFaces[i] = player2Cards[i].getFace();
            playerSuits[i] = player2Cards[i].getSuit();
        }
    }

    //determines the number of each face present
    int facePresence[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < 5; i++){
        if(playerFaces[i] == 0){
            facePresence[0]++;
        } else if (playerFaces[i] == 1){
            facePresence[1]++;
        } else if (playerFaces[i] == 2){
            facePresence[2]++;
        } else if (playerFaces[i] == 3){
            facePresence[3]++;
        } else if (playerFaces[i] == 4){
            facePresence[4]++;
        } else if (playerFaces[i] == 5){
            facePresence[5]++;
        } else if (playerFaces[i] == 6){
            facePresence[6]++;
        } else if (playerFaces[i] == 7){
            facePresence[7]++;
        } else if (playerFaces[i] == 8){
            facePresence[8]++;
        } else if (playerFaces[i] == 9){
            facePresence[9]++;
        } else if (playerFaces[i] == 10){
            facePresence[10]++;
        } else if (playerFaces[i] == 11){
            facePresence[11]++;
        } else{
            facePresence[12]++;
        }
    }

    //checks if faces are in ascending order
    bool ascendingOrder = false;
    for(int i = 0; i < 9; i++){
        if(facePresence[i] > 0){
            if(facePresence[i+1] > 0 && facePresence[i+2] > 0 && facePresence[i+3] > 0 && facePresence[i+4] > 0){
                ascendingOrder = true;
            }
        }
    }

    //Checks if there are pairs, three of a kind or four of a kind and which cards make the set.
    int pairs = 0, three = 0, four = 0;

    int highestDoubleCard = 0;
    int highestTripleCard = 0;
    int highestQuadrupleCard = 0;
    int highCard = 0;

    for(int i = 0; i < 13; i++){
        if(facePresence[i] == 2){
            pairs++;
            highestDoubleCard = i; //stores the card that has the pair. If there are two pairs, pair with the best face is stored.
        } else if(facePresence[i] == 3){
            three++;
            highestTripleCard = i;//scores the card that has three occurrences
        } else if(facePresence[i] == 4){
            four++;
            highestQuadrupleCard = i;//stores the card that has four occurrences
        }
    }

    //checks for the high Card
    if(pairs == 0 && three == 0 && four == 0){
        int counter = 12;
        int found = false;
        while(!found && counter >= 0){
            if(facePresence[counter] > 0){
                highCard = counter;
                found = true;
            }
            counter--;
        }
    }

    //Checks the suits that are present
    int suitPresence[4] = {0, 0, 0, 0};
    for(int i = 0; i < 5; i++){
        if(playerSuits[i] == 0){
            suitPresence[0]++;
        }else if(playerSuits[i] == 1){
            suitPresence[1]++;
        }else if(playerSuits[i] == 2){
            suitPresence[2]++;
        }else {
            suitPresence[3]++;
        }
    }

    //checks if all suits are the same
    bool fiveOfSameSuit = false;
    for(int i = 0; i < 4; i++){
        if(suitPresence[i] == 5){
            fiveOfSameSuit = true;
        }
    }

    //Determining the hand present. Scores take the face of the cards into account in order to break ties. Deuce is the lowest (+0 to the base score of the hand) and Ace is the highest (+12 points to the base score of the hand).

    if(fiveOfSameSuit == true){
        if(facePresence[12] == 1 && ascendingOrder == true){ //Royal Flush
            playerScores[player-1] = 106;
            playerHands[player-1] = "Royal Flush";
        } else if(ascendingOrder == true && facePresence[12] == 0){ //Straight Flush
            playerScores[player-1] = 98 + highCard - 4; //room for 8 if need to diffrentiate
            playerHands[player-1] = "Straight Flush";
        } else if(ascendingOrder == false){ //Flush
            playerScores[player-1] = 60 + highCard;
            playerHands[player-1] = "Flush";
        }
    }else{
        if(four == 1){ //Four of a Kind
            playerScores[player-1] = 85 + highestQuadrupleCard;
            playerHands[player-1] = "Four of a Kind";
        } else if(three == 1 && pairs == 1){ //Full House
            if(highestTripleCard < highestDoubleCard){
                playerScores[player-1] = 73 + highestDoubleCard;
            } else{
                playerScores[player-1] = 73 + highestTripleCard;
            }
            playerHands[player-1] = "Full House";
        } else if(ascendingOrder == true){ //Straight
            playerScores[player-1] = 51 + highCard - 4;
            playerHands[player-1] = "Straight";
        } else if(three == 1 && pairs == 0){//Three of a Kind
            playerScores[player-1] = 38 + highestTripleCard;
            playerHands[player-1] = "Triple Card";
        } else if(pairs == 2){ //Two Pair
            playerScores[player-1] = 26 + highestDoubleCard;
            playerHands[player-1] = "Two Pair";
        } else if(pairs == 1 && three == 0){//Pair
            playerScores[player-1] = 13 + highestDoubleCard;
            playerHands[player-1] = "Pair";
        }else{//High Card
            playerScores[player-1] = highCard;
            playerHands[player-1] = "High Card";
        }
    }

    cout << "Player " << player << " hand: " << playerHands[player-1] << endl;
    cout << endl;
}

int Dealer::determineWinner(){
    if(playerScores[0] > playerScores[1]){ //player 1 wins
        return 1;
    } else if(playerScores[1] > playerScores[0]){ //player 2 wins
        return 2;
    } else{ // a tie
        return 0;
    }
}

void Dealer::dealTwoCards(){
    deck1.shuffle(); //shuffles deck

    //deals two cards to each player
    player1Cards[0] = deck1.dealCard();
    player2Cards[0] = deck1.dealCard();
    player1Cards[1] = deck1.dealCard();
    player2Cards[1] = deck1.dealCard();
}

void Dealer::displayPlayerCards(int counter){
    for(int i = 0; i < counter; i++){
        player1Cards[i].toString();
    }
    cout << endl;
}


bool Dealer::dealerTakeCard(){
    bool cardNotTaken = true;
    int difference = 21 - playerScores[1];
    int possibleCards = 0.0;
    if(difference > 2){
        //calculates probability of overshooting. Assumes that each face has four cards associated with it despite amount of cards delt.
        if(difference < 10){
            possibleCards = difference*4;
        } else{
            possibleCards = 52.0 - deck1.getCardsDelt();
        }
        double probability = (double) possibleCards/possibleCards; //gets probability of not busting
        if(probability > 0.50){ //if probability is greater than 0.50, dealer will take a card
            player2Cards[dealerCardCount] = deck1.dealCard();
            playerScores[1] += player2Cards[dealerCardCount].getFaceValue(); //calculates new score
            dealerCardCount++;
            cardNotTaken = false;
        }
    }
    return cardNotTaken;
}
