#include <cstdlib>

#include "tolower_data.h"

static int compul(const void *a, const void *b)
{
	struct UPPER_LOWER *ul_a = (struct UPPER_LOWER *)a;
	struct UPPER_LOWER *ul_b = (struct UPPER_LOWER *)b;
	return ul_a->upper - ul_b->upper;
}

extern "C" {
int str_utf8_tolower(int code)
{
	struct UPPER_LOWER key;
	struct UPPER_LOWER *res;
	key.upper = code;
	res = (UPPER_LOWER *)bsearch(&key, tolower, NUM_TOLOWER, sizeof(struct UPPER_LOWER), compul);

	if(res == NULL)
		return code;
	return res->lower;
}
}
