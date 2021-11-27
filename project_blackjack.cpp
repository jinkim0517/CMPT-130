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
void deal(CardArray & deck, CardArray & hand);
int scoreCheck(CardArray deck);
void printCards(CardArray deck);

int main() {
	CardArray deck1;
	getNewDeck(deck1);
	cout << "DECK:" << endl;
  	printDeck(deck1);
	cout << endl;
	shuffleDeck(deck1);
	cout << "Shuffled DECK:" << endl;
	printDeck(deck1);
	cout << endl;
	/*int i = 0;
	cout << deck1.cards[i].description << "//" << deck1.cards[i].value << "//" << deck1.cards[i].rank;*/
	blackjack(deck1);
	return 0;
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
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'S';
				deck.cards[i].value = deck.cards[i].rank;
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
				deck.cards[i].rank = value[9];
			}
		}
		else if(i >= 13 && i < 26){
			deck.cards[i].suit = suit[1];
			deck.cards[i].rank = rank[secondSet];
			secondSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AH";
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'H';
				deck.cards[i].value = deck.cards[i].rank;
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
				deck.cards[i].rank = value[9];
			}
		}
		else if(i >= 26 && i < 39){
			int n = 0;
			deck.cards[i].suit = suit[2];
			deck.cards[i].rank = rank[thirdSet];
			thirdSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AD";
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'D';
				deck.cards[i].value = deck.cards[i].rank;
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
				deck.cards[i].rank = value[9];
			}
		}
		else if(i >= 39 && i < 52){
			deck.cards[i].suit = suit[3];
			deck.cards[i].rank = rank[fourthSet];
			fourthSet++;

			if(deck.cards[i].rank == 1){
				deck.cards[i].description = "AC";
				deck.cards[i].value = value[10];
			}
			else if (deck.cards[i].rank > 1 && deck.cards[i].rank < 11){
				deck.cards[i].description = to_string(deck.cards[i].rank) + 'C';
				deck.cards[i].value = deck.cards[i].rank;
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
				deck.cards[i].rank = value[9];
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
		Card temp = deck.cards[roll];
		deck.cards[roll] = deck.cards[i];
		deck.cards[i] = temp;
	}
}

// PART 2
int blackjack(CardArray & deck){
	CardArray playerHand;
	CardArray dealerHand;

	playerHand.cards = new Card[MAX_HAND];
	dealerHand.cards = new Card[MAX_HAND];

	playerHand.maxCards = MAX_HAND;
	playerHand.currentCards = 0;

	dealerHand.maxCards = MAX_HAND;
	dealerHand.currentCards = 0;

	cout << "Deal First Card" << endl;
	cout << "---------------" << endl;

	cout << "////" << playerHand.currentCards;
	deal(deck, playerHand);
	deal(deck, dealerHand);
	cout << "////" << playerHand.currentCards;

	cout << "+Player+";
	printCards(playerHand);
	cout << endl;
	cout << "*Dealer*";
	printCards(dealerHand);
	cout << endl;

	cout << "Deal Second Card" << endl;
	cout << "---------------" << endl;

	deal(deck, playerHand);
	deal(deck, dealerHand); 
	cout << "////" << playerHand.currentCards;

	cout << "+Player+" ;
	printCards(playerHand);
	cout << endl;
	cout << "*Dealer*";
	cout << setw(4) << dealerHand.cards[0].description << setw(4) << "??";
	cout << endl;

	cout << scoreCheck(playerHand);

	if (scoreCheck(playerHand) == 21){
		cout << "You Win!!!" << endl;
	}
	else if (scoreCheck(playerHand) > 21){
		cout << "BUST!!! You lose" << endl;
	}
	
	char decision;
	cout << "Enter h to hit or s to stand: ";
	cin >> decision;

	while (decision == 'h'){
		int score = scoreCheck(playerHand);
		if (score == 21){
			cout << "You Win!!!" << endl;
		}
		else if (score > 21){
			cout << "BUST!!! You lose" << endl;
		}

		deal(deck, playerHand);
		printCards(playerHand);
		cout << endl;
		cout << "Enter h to hit or s to stand: ";
		cin >> decision;
		cout << "////" << scoreCheck(playerHand);
	}

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
	hand.cards[hand.currentCards] = deck.cards[deck.currentCards - 1];
	deck.currentCards--;
	hand.currentCards++;
}

int scoreCheck(CardArray deck){
	int score = 0;
	for(int i = 0; i <= deck.currentCards; i++){
		score += deck.cards[i].value;
	}
	return score;
}

void printCards(CardArray deck){
	for(int i = 0; i < deck.maxCards; i++){
		cout << setw(4) << deck.cards[i].description;
	}
}