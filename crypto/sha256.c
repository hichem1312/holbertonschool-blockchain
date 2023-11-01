#include "hblk_crypto.h"

/**
 * sha256 - a function that computes the hash of a sequence of bytes
 * @s: is the sequence of bytes to be hashed
 * @len: is the number of bytes to hash in s
 * @digest: The resulting hash
 * Return: NULL or hash string
 */

uint8_t *sha256(int8_t const *s, size_t len,
		uint8_t digest[SHA256_DIGEST_LENGTH])
{
	uint8_t *hash_result;

	if (!digest)
		return (NULL);

	hash_result = SHA256((const unsigned char *)s, len, digest);
	return (hash_result);
}
