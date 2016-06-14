#include <iostream>
#include <vector>
#include "Deck.h"
#include "Hand.h"

int main()
{
	Deck* deck = new Deck(2);
	deck->Shuffle();

	std::vector<Hand*> handList;
	Hand* h;

	for(int i = 0; i < 2; i++)
	{
		h = new Hand(i);
		handList.push_back(h);
	}

	std::cout << "### Top of the deck ###\n";
	deck->m_deck.back()->PrintCard();
	std::cout << std::endl;

	std::cout << "### Filling starting hands....\n\n";
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			handList[i]->m_hand.push_back(deck->DealCard());
		}
	}

	for(int i = 0; i < handList.size(); i++)
	{
		std::cout << "### Printing hand[" << i << "] ###\n";
		handList[i]->PrintHand();
		std::cout << std::endl;
	}

	std::cout << "\n### Dumping hands...\n\n";

	for(int i = 0; i < handList.size(); i++)
	{
		handList[i]->DumpHand();
	}

	for(int i = 0; i < handList.size(); i++)
	{
		std::cout << "### Printing hand[" << i << "] ###\n";
		handList[i]->PrintHand();
		std::cout << std::endl;
	}

	std::cout << "### Top of the deck ###\n";
	deck->m_deck.back()->PrintCard();
	std::cout << std::endl;

	std::cout << "### Filling starting hands....\n\n";
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			handList[i]->m_hand.push_back(deck->DealCard());
		}
	}

	for(int i = 0; i < handList.size(); i++)
	{
		std::cout << "### Printing hand[" << i << "] ###\n";
		handList[i]->PrintHand();
		std::cout << std::endl;
	}

	return 0;
}
