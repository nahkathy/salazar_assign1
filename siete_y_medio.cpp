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
	std::cout << "\t" << "(" << engrank << " of " << engsuit << ") .\n";
}

void print_hand(Hand B) {
	vector<Card> bcards = B.get_cards(); 
	for (int i = 0; i < bcards.size(); i++) {
		print_card(bcards[i]); 
	}
}
// Stub for main
int main() {
	Player main(100);
	Hand main_hand;

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
	
	/*
	//Prompting player to draw another card or end their turn
	std:: cout << "Do you want another card (y/n)? " << std::endl;
	char x; 
	std::cin >> x;
	if (x == 'y')
	{
	std::cout << "New card: \n";
	Card new_card;
	main_hand.add_card(new_card); 
	cout << "\t"; 
	print_card(new_card); 
	std::cout << "Your cards: \n"; 


	} */
	return 0;
}