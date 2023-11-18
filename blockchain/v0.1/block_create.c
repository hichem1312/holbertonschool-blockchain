#include "blockchain.h"

/**
 * block_create - function that creates a Block structure
 * @prev: is a pointer to the previous Block in the Blockchain
 * @data: points to a memory area to duplicate in the Block’s data
 * @data_len: stores the number of bytes to duplicate in data
 * Return: a pointer or NULL
 **/
block_t *block_create(block_t const *prev,
					  int8_t const *data, uint32_t data_len)
{
	block_t *block_to_create;

	if (data_len > BLOCKCHAIN_DATA_MAX)
	{
		data_len = BLOCKCHAIN_DATA_MAX;
	}
	block_to_create = calloc(1, sizeof(*block_to_create));
	if (!block_to_create)
		return (NULL);

	block_to_create->info.index = prev->info.index + 1;
	block_to_create->info.timestamp = time(NULL);
	block_to_create->info.nonce = 0;
	memcpy(block_to_create->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
	memcpy(block_to_create->data.buffer, data, data_len);
	block_to_create->data.len = data_len;
	return (block_to_create);
}
