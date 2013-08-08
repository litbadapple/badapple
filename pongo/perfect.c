#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int letter[26] = {0};

int char2array(char ch) {
	if (ch >= 'a' && ch <= 'z') {
		letter[ch-'a']++;
	} else if (ch >= 'A' && ch <= 'Z') {
		letter[ch-'A']++;
	}
	return 0;
}

void order_letter(void) {
	int i, j, t;  
	for(i = 0; i < 25; i++) {  
		for(j = 0; j < 25 - i; j++) {  
			if(letter[j + 1] > letter[j]) {  
				t = letter[j + 1];  
				letter[j + 1] = letter[j];  
				letter[j] = t;  
			}  
		}  
	}
}

int perfect(const char *s) {
	if (NULL == s) {
		return 0;
	}
	int leng = strlen(s);
	int i = 0;
	int num = 0;
	
	for (i = 0; i < leng; i++) {
		char2array(s[i]);
	}
	printf("length=%d\n", leng);
	int tmp = 0;
	for (i = 0; i < 26; i++) {
		printf("[%c %d]", 'a'+i, letter[i]);
		tmp += letter[i];
	}
	printf("\ntmp = %d\n", tmp);
	order_letter();
	
	for(i = 0; i < 26; i++) {
		num += (26 - i) * letter[i];
	}
	
	return num;
}

int main()
{
	printf("perfect num is %d\n", perfect("ucDFYDbVzJKtBJzWhjbHodOIgRkVhZdvfmrKpfTWQbQTOtAojOZhIsjtKFSPecWqdIvbVZTdqmtEFcTQlyAdwldjspoPxhKCrNhHssjNxGOyDKdZNWIrrzFkvwgkIivVglJcembtXMZjymarUkqJDUMrZEeUxlsaFjMqkwBYZTosnpIopqBUKggsOXMbvGMGfQxYphNdWnWItNItTahiNVuZtygsnjZzXdIdnzamEscJEGxTwmEGrySloybPDvayPBTfdkabbDVysPXIeoaHwiqVPtYHVeCWzDfjODeZEaFWydiqhXcrYjOKotBHDDRBkxjVixFYgNWnsaJMcqzmqyYgPdWdBXhrNefnPqTvPGYlGPPBoByztIOzuYOJFEijQSLKHKOHsXCqOwOjNaFWZRPjiqwviMlFlTLRNWZedMtjixWaiealEjJZpHQVGyhxPalGWJBmsCXhIDkbTiKcJOUqeCybbbUHkCXRUNkcsrjGzXlBwkdjtPfWzkRfsNbXpjSXOsErIIjjpGDAuiISizVdAbVsWOZhLkinpHibsiLKrdMowZRAYsiShBbfTwgkQyzcVxWGCLXvedrAhxJJqHoAYRaCTsuAUnmTaEWvbHDuoThRrTTApTgZlwOJvtjEaxSHcwKAuynzDnwnEioADwpSxELlIgwyNyTtggSdLbMycSsuegZhMIpLchozmnsIbLfvzbQMYBikJUaxMrjXZzVqfKYBSMTeOpXstNbVeONNuJBTlqWldWXXHOdZmmmatUiafKLQizsRJYzAngnHyCtyWXnWqTKCoHyXJzlaGHsLMUUyLDdBQJltqWjJrSpZbUjkxRMamOlmNjRGpdsNgWBBLnqEsEhvwFiIHsMCHkcIhQxNlPuDwNJUCiyzfNOrRHuzZeFaMigKkbitSpSLZyOSsUHFIRJFUPLNFsAFHmAVBGGwVwGyILQujgQepZbvowpROrQBOkdrnSEpfvwKZcvTgwyzAzwRiQJWKzrD"));
}
