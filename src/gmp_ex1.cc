#include <gmpxx.h>
//using namespace std;

int main() {
	mpz_t a, b, c, d;
	mpz_init(a);
	mpz_init(b);
	mpz_init(c);
	mpz_init(d);

	// calculate 2^1000
	mpz_init_set_ui(a,2);
	mpz_pow_ui(c,a,1000);
	gmp_printf("c = %Zd\n",c);


	// calculate large numbers
	mpz_init_set_str(b,"12345678900987654321",10); //十进制
	mpz_init_set_str(c,"98765432100123456789",10); //十进制
	mpz_mul(d,b,c);
	gmp_printf("c = %Zd\n",d);

	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(c);
	mpz_clear(d);
}
