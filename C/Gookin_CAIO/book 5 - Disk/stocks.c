#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FALSE 0
#define TRUE !FALSE

struct stock_data {
  char name[30];
  float buy_price;
  float current_price;
};

void write_info(void);
void read_info(void);
void replace_info(void);

int main() {
  char c;
  int done = FALSE;

  while (!done) {
    puts("\n\t** Stock Portfolio Thing **\n\n");
    puts("A - Add new stock\n");
    puts("R - Replace stock\n");
    puts("L - List Stocks\n");
    puts("Q - Quit\n");
    printf("  Your choice %c ", 16);

    c = toupper(getchar());
    while (getchar() != '\n') continue;

    switch (c) {
      case 'A':
        puts("Add new stock\n");
        write_info();
        break;
      case 'R':
        puts("Replace stock");
        replace_info();
        break;
      case 'L':
        puts("List stocks\n");
        read_info();
        break;
      case 'Q':
        puts("Quit\n");
        done = TRUE;
        break;
      default:
        puts("?");
        break;
    }
  }
  return 0;
}

void write_info(void) {
  FILE *stocks;
  struct stock_data stock;

  printf("Enter stock name: ");
  gets(stock.name);
  printf("how much did you pay for it? $");
  scanf("%f", &stock.buy_price);
  stock.current_price = stock.buy_price / 1.1;

  stocks = fopen("stock.dat", "a");
  if (stocks == NULL) {
    puts("Error opening file");
    exit(1);
  }
  /*fwrite (unlike printf) scrie datele in binar,
   * asa cum sunt in blocul de memorie
   */
  fwrite(&stock, sizeof(stock), 1, stocks);
  /* - "buffer" - locatia blocului de memorie ce-l vrei scris pe disc
   * - "size" - size of "buffer" in bytes. constanta /variabila
   * - "items" - cate item-uri de la locatia "buffer" si de marimea "size"
                    vrei sa scrii. De obicei valoarea e 1
   * - "handle" - file handle-ul (variabila de tip FILE) returnata
                    de un fisier deschis pt w/r/a etc
                    == unde vrei sa scrii pe disc
  */

  fclose(stocks);
  puts("Stock added!");
  fflush(stdin);
}

void read_info(void) {
  FILE *stocks;
  struct stock_data stock;
  int x;

  stocks = fopen("stock.dat", "r");
  if (!stocks) {
    puts("No data in file");
    return;
  }
  while (TRUE) {
    x = fread(&stock, sizeof(stock), 1, stocks);

    if (x == 0) break;

    printf("\nStock name: %s\n", stock.name);
    printf("Purchased for: $%.2f\n", stock.buy_price);
    printf("Current price: $%.2f\n", stock.current_price);
  }

  fclose(stocks);
}

void replace_info(void) {
  FILE *stocks;
  struct stock_data stock;
  int record, x;
  int offset;

  printf("Which record number do you want to find? ");
  scanf("%d", &record);
  printf("**Record = %d***", record);

  stocks = fopen("stock.dat", "r");
  if (stocks == NULL) {
    puts("Error opening file");
    return;
  }

  offset = (long)(record - 1) * sizeof(stock);
  x = fseek(stocks, offset, SEEK_SET);
  if (x != 0) {
    puts("Error reading from file");
    return;
  }

  x = fread(&stock, sizeof(stock), 1, stocks);
  if (x == 0) {
    puts("Error reading record");
    return;
  }

  printf("\nRecord: %d\n", record);
  printf("Stock name: %s\n", stock.name);
  printf("Purchased for $%.2f\n", stock.buy_price);
  printf("Current price: $%.2f\n", stock.current_price);
  fclose(stocks);
  fflush(stdin); 

/***write a new structure at the selected location - record***/
  /******* TO BE CONTINUED *********/
  if(!(stocks = fopen("stock.dat", "r+"))) {
  	puts("Error reading file");
  	return;
  }

  offset = (long)(record - 1) * sizeof(stock);
  x = fseek(stocks, offset, SEEK_SET);
  if (x != 0) {
    puts("Error reading from file");
    return;
  }


}