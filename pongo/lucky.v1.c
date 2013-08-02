#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINNUM		1
#define MAXNUM		1000000000

/* 	MAXNUM - 1 = 999999999
 *	9 * 9 * 9 = 729
 */
#define MAXRANGE	729

static int isprime[MAXRANGE + 1] = {0};
static int prime[MAXRANGE + 1] = {0};
static int prime_num = 0;


void initmap(int maxrange)
{
	int i = 0;
	int j = 0;
	int flag = 1;
	
	prime[0] = 2;
	isprime[2] = 1;
	prime_num = 1;
	
	for (i = 3; i < maxrange; i++) {
		j = 0;
		flag = 1;
		prime[prime_num] = i;
		while (prime[j] <= (i/2 + 1)) {
			if (i % prime[j] == 0) {
				flag = 0;
				break;
			}
			j++;
		}
		if (flag) {
			prime[prime_num] = i;
			isprime[i] = 1;
			prime_num++;
		}
	}
}

inline int is_prime(int num) 
{
	return isprime[num];
}

int islucky(int num)
{
	int sum = 0;
	int sum2 = 0;
	int a = 0;
	while (num > 0) {
		a = num % 10;
		sum += a;
		sum2 += a*a;
		num /= 10;
	}
	
	if (is_prime(sum) && is_prime(sum2)) {
		return 1;
	} else {
		return 0;
	}
}

int lucky(int min, int max) {
	int i = 0;
	int n = 0;
	
	initmap(MAXRANGE + 1);
	
	for (i = min; i <= max; i++) {
		if (islucky(i)) {
			//printf("lucky is %d\n", i);
			n++;
		}
	}
	return n;
}

int main(int argc, char *argv)
{
	int i = 0;
	int m = 0;
	
	m = lucky(1, MAXNUM);
	
	printf("lucky num is %d\n", m);
	
	
	//initmap(MAXRANGE + 1);
	#if 0
	printf("prime num is %d\n", prime_num);
	for (i = 1; i <= MAXRANGE; i++) {
		if (isprime[i] == 1) {
			m++;
			printf("prime id=%d, value=%d\n", m, i);
		}
	}
	#endif
	return 0;
}
