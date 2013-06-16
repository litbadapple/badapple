#include <stdio.h>
#include <string.h>

#define STRLEN		11
#define MAXNUM		((int) (0x7FFFFFFF))
#define MINNUM		((int) (0x80000000))

int char_to_int(char c)
{
	if (c < '0' || c > '9') {
		return -1;
	} else {
		return (c - '0');
	}
}

int StrToInt(const char *str)
{
	char tmp[16] = {0};
	int flag = 0;
	long long result = 0;
	int i = 0;
	int ret = 0;
	if (NULL == str) {
		return 0;
	}

	
	while (str[i]) {
		if (str[i] == ' ') {
			i++;
			continue;
		}
		if (str[i] == '-') {
			flag = -1;
		} else {
			flag = 1;
		}
		i++;
		break;
	}

	strncpy(tmp, str+i, STRLEN);
	for (i = 0; i < STRLEN && tmp[i]; i++) {
		ret = char_to_int(tmp[i]);
		if (ret < 0) {
			 break;
		}
		result = 10*result + ret;
	}

	result = flag * result;
	if (result > MAXNUM) {
		return MAXNUM;
	} else if (result < MINNUM) {
		return MINNUM;
	} else {
		return (int)result;
	}
}

int main()
{
	char input[32] = {0};	
	int result = 0;

//	printf("max num is %d, min num is %d\n", MAXNUM, MINNUM);
	fflush(stdin);
	
	while (1) {
		printf("Please input a number(exit to stop):\n");
		fgets(input, sizeof(input)-1, stdin);
		if (0 == strncmp(input, "exit", 4)) {
			break;
		}
		result = StrToInt(input);
		printf("The result is %d.\n", result);
	
		fflush(stdin);
	}
	return 0;
}
