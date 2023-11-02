#include "hblk_crypto.h"
/*
 * ec_create - a function that creates a new EC key pair.
 *Return: elliptic curve key
 */
EC_KEY *ec_create(void)
{
	EC_KEY *e_key;

	e_key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!EC_KEY_generate_key(e_key))
		return (NULL);
	return (e_key);
}
