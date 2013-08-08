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
    
    //  ��ȡ�ַ��ļ�¼����
    while (content.size())
    {
        char ch = content[0];
        while (true)
        {
            int index = content.find(content[0]);
            if (index < 0) break;
            if ((int)content[0] < ia)
            {
                // ��д����
                config[(int)content[0] - iA] ++;
            }
            else
            {
                config[(int)content[0] - ia] ++;
            }
            
            content.erase(index, 1);
        }
    }
    
    // ��������������
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

    // ��ʼ��������Ҹ�������
    for(int i = 0, momey = 26; i < 26; i ++, momey --)
    {
        perfectNum += config[i]*momey;
    }
    
    return perfectNum;
}


//start ��ʾ���Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
int main()
{   
    printf("perfect num is %d\n", perfect("ucDFYDbVzJKtBJzWhjbHodOIgRkVhZdvfmrKpfTWQbQTOtAojOZhIsjtKFSPecWqdIvbVZTdqmtEFcTQlyAdwldjspoPxhKCrNhHssjNxGOyDKdZNWIrrzFkvwgkIivVglJcembtXMZjymarUkqJDUMrZEeUxlsaFjMqkwBYZTosnpIopqBUKggsOXMbvGMGfQxYphNdWnWItNItTahiNVuZtygsnjZzXdIdnzamEscJEGxTwmEGrySloybPDvayPBTfdkabbDVysPXIeoaHwiqVPtYHVeCWzDfjODeZEaFWydiqhXcrYjOKotBHDDRBkxjVixFYgNWnsaJMcqzmqyYgPdWdBXhrNefnPqTvPGYlGPPBoByztIOzuYOJFEijQSLKHKOHsXCqOwOjNaFWZRPjiqwviMlFlTLRNWZedMtjixWaiealEjJZpHQVGyhxPalGWJBmsCXhIDkbTiKcJOUqeCybbbUHkCXRUNkcsrjGzXlBwkdjtPfWzkRfsNbXpjSXOsErIIjjpGDAuiISizVdAbVsWOZhLkinpHibsiLKrdMowZRAYsiShBbfTwgkQyzcVxWGCLXvedrAhxJJqHoAYRaCTsuAUnmTaEWvbHDuoThRrTTApTgZlwOJvtjEaxSHcwKAuynzDnwnEioADwpSxELlIgwyNyTtggSdLbMycSsuegZhMIpLchozmnsIbLfvzbQMYBikJUaxMrjXZzVqfKYBSMTeOpXstNbVeONNuJBTlqWldWXXHOdZmmmatUiafKLQizsRJYzAngnHyCtyWXnWqTKCoHyXJzlaGHsLMUUyLDdBQJltqWjJrSpZbUjkxRMamOlmNjRGpdsNgWBBLnqEsEhvwFiIHsMCHkcIhQxNlPuDwNJUCiyzfNOrRHuzZeFaMigKkbitSpSLZyOSsUHFIRJFUPLNFsAFHmAVBGGwVwGyILQujgQepZbvowpROrQBOkdrnSEpfvwKZcvTgwyzAzwRiQJWKzrD"));
} 
//end //��ʾ���Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�   