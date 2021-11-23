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

int main() {
	CardArray deck1;
	getNewDeck(deck1);
	cout << deck1.cardArray[2].rank;
} 

void getNewDeck(CardArray & deck){
	deck.maxCards = DECK_SIZE;
	deck.usedCards = DECK_SIZE;
	Card* newDeck = new Card[DECK_SIZE];

	string suit[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int rank[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	
	int firstSet = 0;
	int secondSet = 0;
	int thirdSet = 0;
	int fourthSet = 0;

	for(int i = 0; i < 52; i++){
		if(i < 13){
			newDeck[i].suit = suit[0];
			newDeck[i].rank = rank[firstSet];
			firstSet++;
			if(newDeck[i].rank == 1){
				newDeck[i].description = "AS";
			}
			else if (newDeck[i].rank > 1 && newDeck[i].rank < 11){
				newDeck[i].description = to_string(newDeck[i].rank) + 'S';
			}
			else if (newDeck[i].rank >= 11){
				if(newDeck[i].rank == 11){
					newDeck[i].description = "JS";
				}
				else if(newDeck[i].rank == 12){
					newDeck[i].description = "QS";
				}
				else if(newDeck[i].rank == 13){
					newDeck[i].description = "KS";
				}
			}
		}
		else if(i >= 13 && i < 26){
			newDeck[i].suit = suit[1];
			newDeck[i].rank = rank[secondSet];
			secondSet++;

			if(newDeck[i].rank == 1){
				newDeck[i].description = "AH";
			}
			else if (newDeck[i].rank > 1 && newDeck[i].rank < 11){
				newDeck[i].description = to_string(newDeck[i].rank) + 'H';
			}
			else if (newDeck[i].rank >= 11){
				if(newDeck[i].rank == 11){
					newDeck[i].description = "JH";
				}
				else if(newDeck[i].rank == 12){
					newDeck[i].description = "QH";
				}
				else if(newDeck[i].rank == 13){
					newDeck[i].description = "KH";
				}
			}
		}
		else if(i >= 26 && i < 39){
			int n = 0;
			newDeck[i].suit = suit[2];
			newDeck[i].rank = rank[thirdSet];
			thirdSet++;

			if(newDeck[i].rank == 1){
				newDeck[i].description = "AD";
			}
			else if (newDeck[i].rank > 1 && newDeck[i].rank < 11){
				newDeck[i].description = to_string(newDeck[i].rank) + 'D';
			}
			else if (newDeck[i].rank >= 11){
				if(newDeck[i].rank == 11){
					newDeck[i].description = "JD";
				}
				else if(newDeck[i].rank == 12){
					newDeck[i].description = "QD";
				}
				else if(newDeck[i].rank == 13){
					newDeck[i].description = "KD";
				}
			}
		}
		else if(i >= 39 && i < 52){
			newDeck[i].suit = suit[3];
			newDeck[i].rank = rank[fourthSet];
			fourthSet++;

			if(newDeck[i].rank == 1){
				newDeck[i].description = "AC";
			}
			else if (newDeck[i].rank > 1 && newDeck[i].rank < 11){
				newDeck[i].description = to_string(newDeck[i].rank) + 'C';
			}
			else if (newDeck[i].rank >= 11){
				if(newDeck[i].rank == 11){
					newDeck[i].description = "JC";
				}
				else if(newDeck[i].rank == 12){
					newDeck[i].description = "QC";
				}
				else if(newDeck[i].rank == 13){
					newDeck[i].description = "KC";
				}
			}
		}
	}
}

void printDeck(const CardArray & deck){
		for(int i = 0; i < 52; i++){
		//cout << CardArray.description << " ";
		if(i == 12)
		cout << endl;
		if(i == 25)
		cout << endl;
		if(i == 38)
		cout << endl;
	}
}

void deckShuffle(string *deck){
	for(int i = 0; i < 52; i++){
		srand(time(0));
		int roll = rand() % 52;
		deck[i] = deck[roll];
	}
		for(int i = 0; i < 52; i++){
		cout << deck[i] << " ";
		if(i == 12)
		cout << endl;
		if(i == 25)
		cout << endl;
		if(i == 38)
		cout << endl;
	}
}