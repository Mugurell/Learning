

#define JUST_TESTS	0



int main(void)
{
	char strlit[] = "Gheorghe";
	char *ptr2str = strlit;
	char **ptr2str2 = &ptr2str;
	char ***ptr2str3 = &ptr2str2;
	int gogu = 3;

	printf("ptr2str e %s\n *ptr2str e %c\n", ptr2str, *ptr2str);

	ptr2str[1] = 'x';
	
	puts(**ptr2str3);

	ptr2str2[0][1] = 'z';

	printf("second element os ptr2str3 is %c\n\n", ptr2str3[0][0][1]);

#ifdef JUST_TEST
//	#if 0
Daca #if e true (non 0) - se compileaza cu tot ce e inclus aici
Daca #if e 0 ce e inclus aici e deletat de compilator
	(to better understand this pointer shit..)
	ptr2str3[0][0][1]
	ptr2str2[0][1]
	ptr2str [1]
	strlit;
//	#endif	/* 0 */
#endif 	/* JUST_TESTS */



	return 0;
}