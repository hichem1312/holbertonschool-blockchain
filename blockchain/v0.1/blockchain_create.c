#include "blockchain.h"

#define  HASH "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03"
/**
 * blockchain_create - a function that creates a Blockchain structure.
 * Return: Pointer.
 */

blockchain_t *blockchain_create(void)
{
	blockchain_t *blockchain;
	block_t *block;
	llist_t *list;



	blockchain = calloc(1, sizeof(*blockchain));
	block = calloc(1, sizeof(*block));
	list = llist_create(MT_SUPPORT_TRUE);

	block->info.timestamp = 1537578000;
	memcpy(&(block->data.buffer), "Holberton School", 16);
	block->data.len = 16;
	memcpy(&(block->hash), HASH, SHA256_DIGEST_LENGTH);
	if (llist_add_node(list, block, ADD_NODE_FRONT) == -1)
	{
		free(blockchain);
		free(block);
		llist_destroy(list, 1, NULL);
		return (NULL);
		return (NULL);
	}
	blockchain->chain = list;
	return (blockchain);
}