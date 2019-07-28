#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main (int argc, char **argv) {
	mpz_t begin, m1, m2;
	int count;

	// set begin to 2^127
	mpz_init_set_str(begin, "170141183406469631731687303715884105728", 0);

	count = (argc == 1) ? 10 : atoi(argv[1]);

	while (count--) {
		mpz_nextprime(begin, begin);
		gmp_printf("%Zd\n", begin);
	}

	mpz_clear(begin);
}
