#include <stdio.h>

int severse(int num)
{
	int flag = 0;
	int tmp = 0;
	int result = 0;
	
	if (num > 0) {
		flag = 1;
	} else if (num < 0) {
		flag = -1;
	}
	tmp = flag * num;
	
	while (tmp) {
		result = result * 10 + tmp % 10;
		tmp /= 10;
	}
	
	result *= flag;
	return result;
}

int main(int argc, char *argv[]) 
{
	int a = -123;
	
	printf("reverse=%d\n", severse(a));
	
	return 0;
}
