#include "hblk_crypto.h"

/**
 * ec_verify - a function that verifies the signature of a given set of bytes
 * @key: points to the EC_KEY structure containing the public key
 * @msg:  points to the msglen characters to verify the signature
 * @msglen: message length
 * @sig: points to the signature to be checked
 * Return: 1 or 0
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg,
				size_t msglen, sig_t const *sig)
{
	if (!(key) || !(msg) || !(sig))
		return (0);
	return (ECDSA_verify(0, msg, msglen, sig->sig,
						sig->len, (EC_KEY *)key) == 1);
}
