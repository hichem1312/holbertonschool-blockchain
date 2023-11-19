#include "blockchain.h"

/**
 * blockchain_destroy - a function that deletes an existing Blockchain.
 * @blockchain: points to the Blockchain structure to delete
 * Return: void
 **/
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	llist_destroy(blockchain->chain, 1, NULL);
	free(blockchain);
}
