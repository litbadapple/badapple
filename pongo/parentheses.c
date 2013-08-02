#include <stdio.h>

int longestValidParentheses(const char *s)
{
	int left = 0;
	int n = 0;
	
	int i = 0;
	
	if (NULL == s) {
		return 0;
	}
	
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(') {
			left++;
		} else if (s[i] == ')' && left > 0) {
			left--;
			n++;
		}
	}
	return n*2;
}

int main(int argc, char *argv[])
{
	int len = 0;
	
	len = longestValidParentheses("()()((()()()()");
	
	printf("() length is %d\n", len);
	return 0;
}