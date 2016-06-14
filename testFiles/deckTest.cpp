#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"


int main()
{
	Deck* d = new Deck(2);

//	std::cout << "### BEFORE SHUFFLE ###\n" << std::endl;
//
//	for(int i = 0; i < d->m_deck.size(); i++)
//	{
//		std::cout << "Card: ";
//		d->m_deck[i]->PrintCard();
//		std::cout << std::endl;
//	}
//
//	std::cout << "\n\n### AFTER SHUFFLE ###\n" << std::endl;

	d->Shuffle();

	for(int i = 0; i < d->m_deck.size(); i++)
	{
		//std::cout << "Suffle: ";
		d->m_deck[i]->PrintCard();
		std::cout << std::endl;
	}

//	Card* c;
//
//	std::cout << "Top of the deck: ";
//	d->m_deck.back()->PrintCard();
//	
//	c = d->DealCard();
//
//	std::cout << "\nCard dealt: ";
//	c->PrintCard();
//
//	std::cout << "\nTop of the deck: ";
//	d->m_deck.back()->PrintCard();
//
//	std::cout << "\nSize: " << d->m_deck.size() << std::endl;
	return 0;
}
