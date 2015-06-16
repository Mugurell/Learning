#include <stdio.h>

int del_substr(char *str, char const *substr);

int main(void)
{
	char string [100];
	char substring[10];
	int x = 0;

	puts("\n\tSay something nice");
	fgets(string, 100, stdin);
	puts("\n\tNow what block of letters do you want deleted?\n");
	fgets(substring, 10, stdin);

	while(string[x] != '\0') 
		printf("%p says %c\n", &string[x], string[x++]);

	return (del_substr(string, substring));

}

int del_substr(char *str, char const *substr)
{
	char *temp;
	/*altfel nu puteam reseta substr*/
	if(str != NULL && substr != NULL) 
	{
		for(; *str != '\0'; str++) 
		{
			printf("\nStr este %c\n", *str);
			for(temp = substr; *temp != '\n'; temp++) 
			{
				printf("\tsubstr este %c\n", *temp);
				if(*str == *temp) 
				{
					printf("\nReturned 10\n");
					char *str2 = str;
					char *temp2 = temp;
					if(*(str2 + 1) == *(temp2 + 1)); 
					{
						printf("Am gasit ambelele litere!!\n\n");
						return 10;
					}

				}
				
			}
		}
		printf("\nReturned 21\n");
		return 21;
	}
	return 1;
}