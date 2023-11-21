#include "deck.h"

#include <stdio.h>

void sort_by_suit(deck_node_t **deck);
void sort_by_value(deck_node_t **deck);
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2);
int compare_values(const card_t *card1, const card_t *card2);

/**
 * sort_deck - sorts a 52 card deck
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	sort_by_suit(deck);
	sort_by_value(deck);
}

/**
 * sort_by_suit - sorts a deck of cards by suit
 * @deck: deck to sort
 */
void sort_by_suit(deck_node_t **deck)
{
	deck_node_t *current, *temp;

	for (current = (*deck)->next; current && current->prev; current = current->next)
	{
		for (; current && current->prev && current->card->kind < current->prev->card->kind; current = current->prev)
		{
			temp = current->prev;
			swap_nodes(deck, temp, current);
			current = current->next;
		}
	}
}

/**
 * sort_by_value - sorts a deck of cards by value
 * @deck: deck to sort
 */
void sort_by_value(deck_node_t **deck)
{
	deck_node_t *current, *temp;

	for (current = (*deck)->next; current && current->prev; current = current->next)
	{
		for (; current && current->prev && compare_values(current->card, current->prev->card) && current->card->kind == current->prev->card->kind; current = current->prev)
		{
			temp = current->prev;
			swap_nodes(deck, temp, current);
			current = current->next;
		}
	}
}

/**
 * swap_nodes - swaps two consecutive nodes of a doubly linked list
 * @deck: Head node for the deck
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	deck_node_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*deck = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}

/**
 * compare_values - compares values of two cards
 * @card1: The first card to compare
 * @card2: The second card to compare
 *
 * Return: 1 if less than, 0 if greater or equal to
 */
int compare_values(const card_t *card1, const card_t *card2)
{
	char char1 = card1->value[0], char2 = card2->value[0];
	const char *value_order[14] = {"Ac", "1", "2", "3", "4", "5", "6",
	                               "7", "8", "9", "10", "Ja", "Qu", "Ki"};
	int idx1 = 0, idx2 = 0, i;

	if ((char1 >= '0' && char1 <= '9') && (char2 >= '1' && char2 <= '9'))
	{
		if (card1->value[1] == '0')
			char1 = ':';
		if (card2->value[1] == '0')
			char2 = ':';
		return (char1 < char2);
	}
	else
	{
		for (i = 0; i < 14; i++)
		{
			if (card1->value[0] == value_order[i][0] &&
			    card1->value[1] == value_order[i][1])
				idx1 = i;
			if (card2->value[0] == value_order[i][0] &&
			    card2->value[1] == value_order[i][1])
				idx2 = i;
		}
		return (idx1 < idx2);
	}
}
