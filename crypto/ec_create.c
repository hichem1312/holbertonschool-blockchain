#include "hblk_crypto.h"
/*
 * ec_create - a function that creates a new EC key pair.
 *Return: elliptic curve key
 */
EC_KEY *ec_create(void)
{
	EC_KEY *e_key;
	const char *curve_name = "secp256k1";

	e_key = EC_KEY_new_by_curve_name(curve_name);
	if (EC_KEY_generate_key(e_key) == NULL)
		return (NULL);
	return (e_key);
}