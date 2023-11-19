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
    SHA256_CTX HASH256;
    if (!block || !hash_buf)
		return (NULL);
	SHA256_Init(&HASH256);
	SHA256_Update(&HASH256, block, block->data.len + sizeof(block->info));
	SHA256_Final(hash_buf, &HASH256);
	return (hash_buf);
}