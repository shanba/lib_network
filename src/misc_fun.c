#include "misc_fun.h"


int in_checksum(uint16 *ptr, int nbytes)
{
    register int sum;
	uint16 oddbyte = 0;
	register uint16 result;
	uint8 *p, *q;

	sum = 0;
	while (nbytes > 1)
	{
		sum += *ptr++;
		nbytes -= 2;
	}

	if (nbytes == 1)
	{
		p = (u_int8_t *)&oddbyte;
		q = (u_int8_t *)ptr;
		*p = *q;
		sum += oddbyte;
	}

	sum  = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	result = ~sum;

	return result;

}
