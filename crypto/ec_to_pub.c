#include "hblk_crypto.h"

/**
 * ec_to_pub - a function that extracts the public key from an EC_KEY
 * @key:  is a pointer to the EC_KEY structure to retrieve the public key from
 * @pub:  is the address at which to store the extracted public key
 * Return: pointer to the public key or NULL
 **/
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_POINT *p_key;

	if (!key)
		return (NULL);

	p_key = EC_KEY_get0_public_key(key);
    if (!p_key)
        return (NULL);
	if (!EC_POINT_point2oct(EC_KEY_get0_group(key), p_key,
						POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, NULL));
    {
        return (NULL);
    }

	return (pub);
}
