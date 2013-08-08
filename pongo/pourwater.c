#include <stdio.h>

/* a should bigger than b : a > b */
int gcd(int a, int b)
{
	int temp = 0;

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int can(int a, int b, int c)
{
	int tmp = 0;
	
	if (a > b) {
		tmp = gcd(a, b);
	} else {
		tmp = gcd(b, a);
	}

	return (c % tmp) ? 0 : 1;
}

int main(int argc, char *argv[])
{
	if (argc != 4) {
		return 0;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);	
	int c = atoi(argv[3]);	

	printf("result is %s\n", (can(a, b, c) ? "true" : "false"));	
	//printf("Greatest Common Divisor is %d\n", gcd(a, b));
}
