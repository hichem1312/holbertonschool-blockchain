#include "blockchain.h"

/**
 * block_destroy - a function that deletes an existing Block
 * @block: points to the Block to delete
 * Return: NULL
 **/
void block_destroy(block_t *block)
{
	if (!block)
		return;
	free(block);
}