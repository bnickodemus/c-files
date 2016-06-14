#include <iostream>
#include <vector>
#include "Card.h"

class Card;

int main()
{
	std::vector<Card*> cards;
	Card* c;

	Card::Suit heart = Card::Heart;
	Card::Suit diamond = Card::Diamond;
	Card::Suit club = Card::Club;
	Card::Suit spade = Card::Spade;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 2; j < 14; j++)
		{
			c = new Card(j, (Card::Suit)i);
			cards.push_back(c);
		}
	}

	int val;

	for(int i = 0; i < cards.size(); i++)
	{
		std::cout << "Card: ";
		cards[i]->PrintCard();
		val = cards[i]->GetValue();
		std::cout << " Value: " << val;
		std::cout << std::endl;
	}
	c = new Card(2, (Card::Suit)4);

}
