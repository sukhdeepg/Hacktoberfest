#include <stdio.h>
#include <math.h>

int is_prime (int n);
int is_prime_aux (int n, int floor);

int x = 11;

int main ()
{
	printf("Is %d a prime number?\n", x);
	
	if (is_prime(x))
		printf("Yes, %d is a prime number.\n", x);

	else
		printf("No, %d is not a prime number.\n", x);

	return 0;
}

int is_prime (int n)
{
    if (n == 0) {
        return 0;
    }

    if (n == 1|| n == 2) {
        return 1;
    }

    int floor = sqrt (n);

    return (is_prime_aux (n, floor) == 0) ? 0 : 1;
}

int is_prime_aux (int n, int floor)
{

    if (floor == 0 || floor == 1) {
        return 1;
    }

    if (n % floor == 0) {
        return 0;
    }

    return is_prime_aux (n, floor - 1);
}
