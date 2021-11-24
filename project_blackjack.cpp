#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <ctime>

using namespace std;
const int DECK_SIZE = 52;

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
	int usedCards;

	CardArray() {
		cards = nullptr;
		maxCards = 0;
		usedCards = 0;
	}
};

// Function Prototypes
void getNewDeck(CardArray & deck);
string swap(string card);
void shuffleDeck(CardArray & deck);
void printDeck(const CardArray & deck);

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

void getNewDeck(CardArray & deck){
	deck.maxCards = DECK_SIZE;
	deck.usedCards = DECK_SIZE;
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
	for(int i = 0; i < 52; i++){
		int roll = rand() % 52;
		string temp = deck.cards[roll].description;
		deck.cards[roll].description = deck.cards[i].description;
		deck.cards[i].description = temp;
	}
}