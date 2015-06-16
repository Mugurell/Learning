#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //necesar pt strcpy

#define RECORDS 6

int main() {
  struct jb {
    char actor[25];
    struct jb *next;
  };

  struct jb *first_item;
  struct jb *current_item;
  struct jb *new_item;

  /*** Create the first structure in the list ***/
  first_item = (struct jb *)malloc(sizeof(struct jb));

  /*** Fill the first structure ***/
  strcpy(first_item->actor, "Sean Connery");
  new_item = (struct jb *)malloc(sizeof(struct jb));
  first_item->next = new_item;
  /*** Fill the second structure ***/
  current_item = new_item;
  strcpy(current_item->actor, "David Niven");
  new_item = (struct jb *)malloc(sizeof(struct jb));
  current_item->next = new_item;

  /*** Display the results ***/
  puts("The first structure:");
  printf("\tfirst_item->actor = %s\n", first_item->actor);
  printf("\tnext structure adress = %p\n", first_item->next);

  puts("\nThe second structure:");
  printf("\tcurrent_item->actor = %s\n", current_item->actor);
  printf("\tnext structure adress = %p\n", current_item->next);

  return 0;
}