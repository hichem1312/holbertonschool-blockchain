#include "hblk_crypto.h"

/**
 * ec_sign - a function that signs a given set of bytes
 * @key: points to the EC_KEY structure
 * @msg: points to the msglen characters to be signed
 * @msglen: message lenght
 * @sig: signature structure
 * Return: pointer or NULL
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
				size_t msglen, sig_t *sig)
{
	unsigned int len_1;

	if (!(key) || !(msg) || !(sig))
		return (NULL);
	len_1 = sig->len;
	if (ECDSA_sign(0, msg, msglen, sig->sig, &len_1, (EC_KEY *)key) == -1)
		return (NULL);
	sig->len = len_1;

	return (sig->sig);
}