#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


int perfect(const string &s) {
    int ia = (int)'a';    // 97
    int iA = (int)'A';    // 65

    int perfectNum = 0;
    string content = s;

    int config[26] = {0};
    
    //  获取字符的记录个数
    while (content.size())
    {
        char ch = content[0];
        while (true)
        {
            int index = content.find(content[0]);
            if (index < 0) break;
            if ((int)content[0] < ia)
            {
                // 大写内容
                config[(int)content[0] - iA] ++;
            }
            else
            {
                config[(int)content[0] - ia] ++;
            }
            
            content.erase(index, 1);
        }
    }
    
    // 将个数进行排序
    int i,j,t;
    for(i=0;i<25;i++)
    {
        for(j=0;j<25-i;j++)
        {
            if(config[j+1]>config[j])
            {
                t=config[j+1];
                config[j+1]=config[j];
                config[j]=t;
            }
        }
    }

    // 开始进行最大幸福数计算
    for(int i = 0, momey = 26; i < 26; i ++, momey --)
    {
        perfectNum += config[i]*momey;
    }
    
    return perfectNum;
}


//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
    printf("perfect num is %d\n", perfect("ucDFYDbVzJKtBJzWhjbHodOIgRkVhZdvfmrKpfTWQbQTOtAojOZhIsjtKFSPecWqdIvbVZTdqmtEFcTQlyAdwldjspoPxhKCrNhHssjNxGOyDKdZNWIrrzFkvwgkIivVglJcembtXMZjymarUkqJDUMrZEeUxlsaFjMqkwBYZTosnpIopqBUKggsOXMbvGMGfQxYphNdWnWItNItTahiNVuZtygsnjZzXdIdnzamEscJEGxTwmEGrySloybPDvayPBTfdkabbDVysPXIeoaHwiqVPtYHVeCWzDfjODeZEaFWydiqhXcrYjOKotBHDDRBkxjVixFYgNWnsaJMcqzmqyYgPdWdBXhrNefnPqTvPGYlGPPBoByztIOzuYOJFEijQSLKHKOHsXCqOwOjNaFWZRPjiqwviMlFlTLRNWZedMtjixWaiealEjJZpHQVGyhxPalGWJBmsCXhIDkbTiKcJOUqeCybbbUHkCXRUNkcsrjGzXlBwkdjtPfWzkRfsNbXpjSXOsErIIjjpGDAuiISizVdAbVsWOZhLkinpHibsiLKrdMowZRAYsiShBbfTwgkQyzcVxWGCLXvedrAhxJJqHoAYRaCTsuAUnmTaEWvbHDuoThRrTTApTgZlwOJvtjEaxSHcwKAuynzDnwnEioADwpSxELlIgwyNyTtggSdLbMycSsuegZhMIpLchozmnsIbLfvzbQMYBikJUaxMrjXZzVqfKYBSMTeOpXstNbVeONNuJBTlqWldWXXHOdZmmmatUiafKLQizsRJYzAngnHyCtyWXnWqTKCoHyXJzlaGHsLMUUyLDdBQJltqWjJrSpZbUjkxRMamOlmNjRGpdsNgWBBLnqEsEhvwFiIHsMCHkcIhQxNlPuDwNJUCiyzfNOrRHuzZeFaMigKkbitSpSLZyOSsUHFIRJFUPLNFsAFHmAVBGGwVwGyILQujgQepZbvowpROrQBOkdrnSEpfvwKZcvTgwyzAzwRiQJWKzrD"));
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。   