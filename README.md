# Card_Game
This project builds on Simple_Card_Game by using OOP to create the card game. 

Users can choose to play BlackJack against a dealer. The program includes a feature where the Dealer only picks up a card if the probability of busting is below 50%. This makes the game appear more realistic. 

Two players can also play together in a game called GET THE HIGHEST HAND. In the game, each player is delt a hand and the player with the highest hand wins. 

Why did I make this project? I recently learned OOP with C++ and wanted to practice it by making a card game program. 

How does the program work? There are 52 Card objects, each representing one card in a deck of cards, which are stored in an array that is a part of the DeckOfCards object. The Dealer object, which is created in Main.cpp when the game starts, accesses the DeckOfCards object in order to deal cards. The Dealer is the one who classifies hands and determines the winner of each game. 
