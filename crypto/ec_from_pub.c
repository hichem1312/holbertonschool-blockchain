#include "hblk_crypto.h"

/**
 * ec_from_pub - a function that creates an EC_KEY structure given a public key
 * @pub: contains the public key to be converted
 * Return: pointer or NULL
 **/
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *p_key;
	EC_POINT *point;

	if (!pub)
		return (NULL);

	p_key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!p_key)
		return (NULL);
	point = EC_POINT_new(EC_KEY_get0_group(p_key));
	if (!EC_KEY_set_public_key(p_key, point))
	{
		EC_KEY_free(key);
		EC_POINT_free(point);
		return (NULL);
	}

	if (!EC_POINT_oct2point(EC_KEY_get0_group(p_key), point, pub, EC_PUB_LEN
						, NULL))
	{
		EC_KEY_free(key);
		EC_POINT_free(point);
		return (NULL);
	}
	return (p_key);
}
