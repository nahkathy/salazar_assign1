#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}

// Accessor: returns a string with the suit of the card in English 
string Card::get_english_suit() const {
	string span_suit = this->get_spanish_suit();
	string eng_suit;
	if (span_suit == "oros") eng_suit = "coins";
	if (span_suit == "copas") eng_suit = "cups";
	if (span_suit == "espadas") eng_suit = "spades";
	if (span_suit == "bastos") eng_suit = "clubs";
	return eng_suit;
}

// Accessor: returns a string with the rank of the card in English 
string Card::get_english_rank() const {
	string span_rank = this->get_spanish_rank();
	string eng_rank;
	if (span_rank == "As") eng_rank = "Ace";
	if (span_rank == "Dos") eng_rank = "Two";
	if (span_rank == "Tres") eng_rank = "Three";
	if (span_rank == "Cuatro") eng_rank = "Four";
	if (span_rank == "Cinco") eng_rank = "Five";
	if (span_rank == "Seis") eng_rank = "Six";
	if (span_rank == "Siete") eng_rank = "Seven";
	if (span_rank == "Sota") eng_rank = "Jack";
	if (span_rank == "Caballo") eng_rank = "Knight";
	if (span_rank == "Rey") eng_rank = "King";
	return eng_rank;
}


// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */
Hand::Hand() {
	Card x;
	Handvec.push_back(x);
}
vector<Card> Hand::get_cards() {
	return Handvec;
}
void Hand::add_card(Card new_card) {
	Handvec.push_back(new_card);
}
double Hand::value() {
	double val = 0;
	for (int i = 0; i < Handvec.size(); i++)
	{
		if (Handvec[i].get_rank() > 7)
			val += 0.5;
		else
			val += Handvec[i].get_rank();
	}
	return val;
}


/* *************************************************
Player class
************************************************* */
Player::Player(int new_money) {
	money = new_money;
}
int Player::get_money() const {
	return money;
}
void Player::increase_money(int m) {
	money += m;
}
void Player::decrease_money(int m) {
	money -= m;
}