#include "blockchain.h"

/**
 * block_hash - a function that computes the hash of a Block
 * @block: points to the Block to be hashed
 * @hash_buf: the buffer where the hash will be stored
 * Return: pointer
 **/
uint8_t *block_hash(block_t const *block,
			uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t len_b;

	len_b = sizeof(block->info) + block->data.len;
	sha256((int8_t const *)block, len_b, hash_buf);
	return (hash_buf);
}