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
	Card* cardArray;
	int maxCards;
	int usedCards;

	CardArray() {
		cardArray = nullptr;
		maxCards = 0;
		usedCards = 0;
	}
};

// Function Prototypes
void getNewDeck(CardArray & deck);
string swap(string card);
void deckShuffle(string *deck);
void printDeck(const CardArray & deck);

int main() {
	CardArray deck1;
	getNewDeck(deck1);
  	printDeck(deck1);
} 

void getNewDeck(CardArray & deck){
	deck.maxCards = DECK_SIZE;
	deck.usedCards = DECK_SIZE;
	deck.cardArray = new Card[DECK_SIZE];

	string suit[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int rank[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	
	int firstSet = 0;
	int secondSet = 0;
	int thirdSet = 0;
	int fourthSet = 0;

	for(int i = 0; i < 52; i++){
		if(i < 13){
			deck.cardArray[i].suit = suit[0];
			deck.cardArray[i].rank = rank[firstSet];
			firstSet++;
			if(deck.cardArray[i].rank == 1){
				deck.cardArray[i].description = "AS";
			}
			else if (deck.cardArray[i].rank > 1 && deck.cardArray[i].rank < 11){
				deck.cardArray[i].description = to_string(deck.cardArray[i].rank) + 'S';
			}
			else if (deck.cardArray[i].rank >= 11){
				if(deck.cardArray[i].rank == 11){
					deck.cardArray[i].description = "JS";
				}
				else if(deck.cardArray[i].rank == 12){
					deck.cardArray[i].description = "QS";
				}
				else if(deck.cardArray[i].rank == 13){
					deck.cardArray[i].description = "KS";
				}
			}
		}
		else if(i >= 13 && i < 26){
			deck.cardArray[i].suit = suit[1];
			deck.cardArray[i].rank = rank[secondSet];
			secondSet++;

			if(deck.cardArray[i].rank == 1){
				deck.cardArray[i].description = "AH";
			}
			else if (deck.cardArray[i].rank > 1 && deck.cardArray[i].rank < 11){
				deck.cardArray[i].description = to_string(deck.cardArray[i].rank) + 'H';
			}
			else if (deck.cardArray[i].rank >= 11){
				if(deck.cardArray[i].rank == 11){
					deck.cardArray[i].description = "JH";
				}
				else if(deck.cardArray[i].rank == 12){
					deck.cardArray[i].description = "QH";
				}
				else if(deck.cardArray[i].rank == 13){
					deck.cardArray[i].description = "KH";
				}
			}
		}
		else if(i >= 26 && i < 39){
			int n = 0;
			deck.cardArray[i].suit = suit[2];
			deck.cardArray[i].rank = rank[thirdSet];
			thirdSet++;

			if(deck.cardArray[i].rank == 1){
				deck.cardArray[i].description = "AD";
			}
			else if (deck.cardArray[i].rank > 1 && deck.cardArray[i].rank < 11){
				deck.cardArray[i].description = to_string(deck.cardArray[i].rank) + 'D';
			}
			else if (deck.cardArray[i].rank >= 11){
				if(deck.cardArray[i].rank == 11){
					deck.cardArray[i].description = "JD";
				}
				else if(deck.cardArray[i].rank == 12){
					deck.cardArray[i].description = "QD";
				}
				else if(deck.cardArray[i].rank == 13){
					deck.cardArray[i].description = "KD";
				}
			}
		}
		else if(i >= 39 && i < 52){
			deck.cardArray[i].suit = suit[3];
			deck.cardArray[i].rank = rank[fourthSet];
			fourthSet++;

			if(deck.cardArray[i].rank == 1){
				deck.cardArray[i].description = "AC";
			}
			else if (deck.cardArray[i].rank > 1 && deck.cardArray[i].rank < 11){
				deck.cardArray[i].description = to_string(deck.cardArray[i].rank) + 'C';
			}
			else if (deck.cardArray[i].rank >= 11){
				if(deck.cardArray[i].rank == 11){
					deck.cardArray[i].description = "JC";
				}
				else if(deck.cardArray[i].rank == 12){
					deck.cardArray[i].description = "QC";
				}
				else if(deck.cardArray[i].rank == 13){
					deck.cardArray[i].description = "KC";
				}
			}
		}
	}
}

void printDeck(const CardArray & deck){
	for(int i = 0; i < 52; i++){
		cout << setw(4) << deck.cardArray[i].description;
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

/*void deckShuffle(string *deck){
	srand(time(0));
	for(int i = 0; i < 52; i++){
		int roll = rand() % 52;
		string temp = cardArray.description;
		deck.cardArray[roll].description = deck.cardArray[i].description;
		deck.cardArray[i].description = temp;
	}
}*/