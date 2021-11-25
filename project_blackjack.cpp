#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <ctime>

using namespace std;
const int DECK_SIZE = 52;
const int MAX_HAND = 11;

struct Card {
	string suit;
	string description;
	int rank;
	int value;

	Card() {
		suit = "";
		description = "";
		rank = 0;
		value = 0;
	}
};

struct CardArray {
	Card* cards;
	int maxCards;
	int currentCards;

	CardArray() {
		cards = nullptr;
		maxCards = 0;
		currentCards = 0;
	}
};

// Function Prototypes
void getNewDeck(CardArray & deck);
string swap(string card);
void shuffleDeck(CardArray & deck);
void printDeck(const CardArray & deck);
int blackjack(CardArray & deck);
void deal(const CardArray & deck, const CardArray & hand);

int main() {
	CardArray deck1;
	getNewDeck(deck1);
	cout << "DECK:" << endl;
  	printDeck(deck1);
	cout << endl;
	shuffleDeck(deck1);
	cout << "Shuffled DECK:" << endl;
	printDeck(deck1);
	delete[] deck1.cards;
} 


// PART 1
void getNewDeck(CardArray & deck){
	deck.maxCards = DECK_SIZE;
	deck.currentCards = DECK_SIZE;
	deck.cards = new Card[DECK_SIZE];

	string suit[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int rank[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	
	int firstSet = 0;
	int secondSet = 0;
	int thirdSet = 0;
	int fourthSet = 0;

	for(int i = 0; i < 52; i++){
		if(i < 13){
			deck.cards[i].suit = suit[0];
			deck.cards[i].rank = rank[firstSet];
			firstSet++;
			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AS";
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'S';
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JS";
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QS";
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KS";
				}
			}
		}
		else if(i >= 13 && i < 26){
			deck.cards[i].suit = suit[1];
			deck.cards[i].rank = rank[secondSet];
			secondSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AH";
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'H';
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JH";
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QH";
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KH";
				}
			}
		}
		else if(i >= 26 && i < 39){
			int n = 0;
			deck.cards[i].suit = suit[2];
			deck.cards[i].rank = rank[thirdSet];
			thirdSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AD";
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'D';
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JD";
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QD";
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KD";
				}
			}
		}
		else if(i >= 39 && i < 52){
			deck.cards[i].suit = suit[3];
			deck.cards[i].rank = rank[fourthSet];
			fourthSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AC";
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'C';
			}
			else if (deck.cards[i].rank >= 11){
				if(deck.cards[i].rank == 11){
					deck.cards[i].description = "JC";
				}
				else if(deck.cards[i].rank == 12){
					deck.cards[i].description = "QC";
				}
				else if(deck.cards[i].rank == 13){
					deck.cards[i].description = "KC";
				}
			}
		}
	}
}

void printDeck(const CardArray & deck){
	for(int i = 0; i < 52; i++){
		cout << setw(4) << deck.cards[i].description;
		if(i == 12){
			cout << endl;
		}
		if(i == 25){
			cout << endl;
		}
		if(i == 38){
			cout << endl;
		}
	}
}

void shuffleDeck(CardArray & deck){
	srand(time(0));
	for(int i = 0; i < DECK_SIZE; i++){
		int roll = rand() % 52;
		string temp = deck.cards[roll].description;
		deck.cards[roll].description = deck.cards[i].description;
		deck.cards[i].description = temp;
	}
}

// PART 2
int blackjack(CardArray & deck){
	CardArray playerHand;
	CardArray dealerHand;

	playerHand.cards = new Card[playerHand.currentCards];
	dealerHand.cards = new Card[dealerHand.currentCards];

	playerHand.maxCards = MAX_HAND;
	playerHand.currentCards = 0;

	// TO DO:
	// - Check on usage of const for deal function
	// - Implement hitting and standing using user input
		// - Deal again when hit
	// - Create the dealer
	// - Consistently check score to see if 21 or more
	// - Delete the dynamic memory arrays

	return 0;
}

void deal(CardArray & deck, CardArray & hand){ // Says to use constant but doesnt work if u do
	hand.cards[hand.currentCards] = deck.cards[deck.currentCards];
	deck.currentCards--;
	hand.currentCards++;
}

int scoreCheck(CardArray deck){
	int score = 0;
	for(int i = 0; i < deck.currentCards; i++){
		score += deck.cards[i].value;
	}
	return score;
}