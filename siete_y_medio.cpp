#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)
void print_card(Card A);
void print_hand(Hand B); 

// Non member functions implementations (if any)
void print_card(Card A) {
	string spanrank = A.get_spanish_rank();
	string spansuit = A.get_spanish_suit();
	string engrank = A.get_english_rank();
	string engsuit = A.get_english_suit();
	std::cout << "\t" << spanrank << " de " << spansuit;
	std::cout << "\t\t" << "(" << engrank << " of " << engsuit << ").\n";
}

void print_hand(Hand B) {
	vector<Card> bcards = B.get_cards(); 
	for (int i = 0; i < bcards.size(); i++) {
		print_card(bcards[i]); 
	}
}


int main() {
	Player main(100);
	Player dealer(900);
	
	while (main.get_money() > 0 && dealer.get_money() > 0) {
		Hand main_hand;
		Hand dealer_hand;

		//Ask Player to bet 
		int bet = 0;
		std::cout << "You have $" << main.get_money() << ". Enter bet: ";
		std::cin >> bet;
		while (bet > main.get_money()) {
			cout << "You only have $" << main.get_money() << " to bet.";
			cout << "\tEnter bet: ";
			cin >> bet;
		}

		//Revealing player's cards and total
		std::cout << "Your cards: \n";
		print_hand(main_hand);
		std::cout << "Your total is " << main_hand.value() << ". ";

		//Prompting player to draw another card or end their turn
		char x = 'y';
		while (x == 'y') {
			if (main_hand.value() >= 7.5) break;
			std::cout << "Do you want another card (y/n)? " << std::endl;
			std::cin >> x;
			if (x == 'n') break;
			if (x == 'y')
			{
				std::cout << "\nNew card: \n";
				Card new_card;
				main_hand.add_card(new_card);
				print_card(new_card);
				std::cout << "Your cards: \n";
				print_hand(main_hand);
				std::cout << "Your total is " << main_hand.value() << ". ";
			}
		}

		//Dealer's Turn 
		std::cout << "\nDealer's cards: \n";
		print_hand(dealer_hand);
		std::cout << "The dealer's total is " << dealer_hand.value() << ". \n";
		while (dealer_hand.value() < 5.5)
		{
			std::cout << "\nNew card: \n";
			Card A;
			dealer_hand.add_card(A);
			print_card(A);
			std::cout << "\nDealer's cards: \n";
			print_hand(dealer_hand);
			std::cout << "The dealer's total is " << dealer_hand.value() << ". \n";
		}

		//Determine who wins 
		double player_total = main_hand.value();
		double dealer_total = dealer_hand.value();
		std::cout << "\n";
		if ((player_total <= 7.5) && (dealer_total <= 7.5) && ((7.5 - player_total) < (7.5 - dealer_total))) {//Neither bust, player closer to 7.5
			cout << "You win $" << bet << "!\n";
			main.increase_money(bet);
			dealer.decrease_money(bet);
		}
		else if ((player_total <= 7.5) && (dealer_total > 7.5)) { //Dealer busts
			cout << "You win $" << bet << "!\n";
			main.increase_money(bet);
			dealer.decrease_money(bet);
		}
		else if ((dealer_total <= 7.5) && (player_total <= 7.5) && ((7.5 - dealer_total) < (7.5 - player_total))) { //Neither bust, dealer closer to 7.5
			cout << "You lose $" << bet << "!\n";
			dealer.increase_money(bet);
			main.decrease_money(bet);
		}
		else if (player_total > 7.5) { //Player busts 
			cout << "You lose $" << bet << "!\n";
			dealer.increase_money(bet);
			main.decrease_money(bet);
		}
		else if (player_total > 7.5 && dealer_total > 7.5) { //Both bust, house advantage 
			cout << "You lose $" << bet << "!\n";
			dealer.increase_money(bet);
			main.decrease_money(bet);
		}
		else {
			cout << "Nobody wins!";
		}
		std::cout << "\n";
	}

	//End game 
	if (main.get_money() == 0) {
		std::cout << "You have $0. GAME OVER!" << std::endl; 
		std::cout << "Come back when you have more money."; 
		std::cout << "\n\nBye!"; 
	}
	if (dealer.get_money() == 0) {
		std::cout << "Congratulations. You beat the casino! "; 
		std::cout << "\n\nBye!"; 
	}

	return 0;
}