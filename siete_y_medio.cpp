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
	std::cout << "\t" << "(" << engrank << " of " << engsuit << ").\n";
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
		std::cout << "The dealer's total is " << dealer_hand.value() << ". "; 
	}
 


	return 0;
}