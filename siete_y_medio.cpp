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

// Non member functions implementations (if any)
void print_card(Card A) {
	string spanrank = A.get_spanish_rank();
	string spansuit = A.get_spanish_suit();
	string engrank = A.get_english_rank();
	string engsuit = A.get_english_suit();
	std::cout << "\t" << spanrank << " de " << spansuit;
	std::cout << "\t" << "(" << engrank << " of " << engsuit << ") .\n";
}

// Stub for main
int main() {
	/* --STATEMENTS-- */
	return 0;
}