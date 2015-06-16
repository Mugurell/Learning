#include <stdio.h>
#include <stdlib.h> /*for malloc*/
#include <string.h> /*for strcpy*/
#include <ctype.h>	/*for toupper*/

void clear_input(void);
void add_new_account(void);

struct account {
  int number;
  char lastname[15];
  char firstname[15];
  float balance;
  struct account *next;
};
struct account *firsta, *currenta, *newa;
int anum = 0;

int main (void){
  char ch;
  firsta = NULL;

  do {
    clear_input();
    puts("\nA - Add a new account");
    puts("Q - Quit this program\n");
    ch = toupper(getchar());
    switch (ch) {
      case 'A':
        puts("Add a new account\n");
        clear_input();
        add_new_account();
        break;
      case 'Q':
        puts("Quit\n");
      default:
        break;
    }
  } while (ch != 'Q');

  return 0;
}

/*
 * This function clears any text from the input stream
 */
void clear_input(void) {
	fflush(stdin);
}

void add_new_account(void) {
	newa = (struct account *)malloc(sizeof(struct account));

/*
 * Check to see if this is the first record.
 * If so, then initialize all the pointers to this
 * first structure in the database
 */
 	if(firsta == NULL) firsta = currenta = newa;

 /*
  * Otherwise, you must find the end of the structure list
  * (easily spotted by the NULL pointer) and add on the
  * new structure you just allocated memory for
  */
	else {
		currenta = firsta;	/* make first record current */
							/* loop through all records */
		while(currenta->next != NULL)
			currenta = currenta->next;
				/* the last record is fount */
		currenta->next = newa;	/* save the adress of new */
		currenta = newa; 		/* make current record new */
	} 

/* Now, you just fill in the new strucure */
	anum++;
	printf("%27s: %5i\n", "Account number", anum);
	currenta->number = anum;

	printf("%27s: ", "Enter customer's last name");
	gets(currenta->lastname);

	printf("%27s: ", "Enter customer's first name");
	gets(currenta->firstname);

	printf("%27s: ", "Enter account balance");
	scanf("%f", &currenta->balance);

/*
 * Finally, cap the new record with a NULL pointer
 * so that you know it's the last record
 */
 	currenta->next = NULL;
}