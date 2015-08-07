/*******************************
* program to count
* digits, white spaces, others..
*******************************/

#include <stdio.h>

#define OUT 0
#define IN 1

count_1(void);      // count .. things - varianta originala
count_2(void);      // histograma orizontala pentru numere
count_3(void);      // histograma verticala pentru numere
count_4(void);      // histograma verticala pentru numarul de litere
count_5(void);      // histograma verticala pentru lungimea cuvintelor

int main()
{
    count_4();

    while (getchar() != '\n')
        continue;
    getchar();

    return 0;
}

//! Varianta originala
count_1(void)
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != '~')
    {
        if (c >= '0' && c <= '9')
        {
            ndigit[c - '0']++;
            /*****************************************
            * caracterul respectiv - 0-9 (in ASCII 48-57)
            * - 0 (in ASCII e 48)
            * = 0-9 - pozitia din array
            ******************************************/
        }
        else if ( c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

//! histograma orizontala pentru cate int-uri de-un fel (<10) sunt in prop
count_2(void)
{
    int c, i, ws, cn;
    c = i = ws = cn = 0;

    int nre[10];

    while (i < 10)
        nre[i++] = 0;
    //! puteam mai simplu sa pun direct nre[10] = {0}
    //! => initializa primul element cu 0
    //! dar toate celelalte, pentru care nu am dat
    //! deasemenea valori vor fi "din oficiu" initlizate tot cu 0 !!!
    while ((c = getchar()) != '~')
    {
        if (c >= '0' && c <= '9')
            nre[c - '0']++;
        else if (c == ' ' || c == '\t' || c == '/n')
            ws++;
        else
            cn++;
    }

    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", nre[i]);
    printf(", white spaces = %d, chars = %d\n\n", ws, cn);

    for (i = 0; i < 10; i++)
    {
        if (nre[i]>0)
        {
            printf("  Nr %d : ", i);
            while (nre[i] > 0)
            {
                printf(" * ");
                nre[i] -= 1;
            }
            putchar('\n');
        }
        else //if(nre[i] == 0)
        {
            printf("  Nr %d : ", i);
            putchar('\n');
        }
        printf("------------------------------------\n");
    }
    printf("Times x| ");
    for(i=0; i<9; i++)
        printf(" %d ", i+1);
}

//! histograma verticala pentru cate int-uri de-un fel (<10) sunt in prop
count_3(void)
{
    int nre[10] = {0};

    /*****************************************************************
    * primul element e initializat la 0
    * (dar odata ce ai inceput sa initializezi si nu ai terminat
    * toate cele ramase sunt din oficiu initializate la 0)
    ******************************************************************/

    int i, x, c, char_nr, space_nr, nr_maxim;
    i = char_nr = space_nr = nr_maxim = 0;

    puts("If you've got something to say, say it!");
    puts("Just put \" ~ \" when you've finished..\n");
    while((c=getchar()) != '~')
    {
        if(c>='0' && c<= '9')
            nre[c - '0'] ++;
        else if(c == ' ' || c == '\t' || c == '\n')
            space_nr++;
        else
            char_nr++;
    }
    puts("\nFinished? Ok...\n");
    printf("In all you mambo-jumbo you had %d letters and %d white spaces\n", char_nr, space_nr);
//  puts("\nOhh, and some numbers [0-9]...");
//  for(x=0; x<10; x++)
//      printf("%d ", nre[x]);
    puts("\n\nAlso, heres a vertical histogram of how many 0-9 numbers you've said:\n");

    for(x=0; x<10; x++)
        if(nr_maxim < nre[x])
            nr_maxim = nre[x];

    for(x=nr_maxim; x>=0; x--)
    {
        while(x<=nr_maxim)
        {
            printf("times x %d|", x+1);
            break;
        }
        for(i=0; i<10; i++)
        {
            if(nre[i] >= x)
                printf(" * ");
            else
                printf("   ");
        }
        putchar('\n');
        puts("----------------------------------------");
    }
    printf("  Number |");
    for(x=0; x<10; x++)
        printf(" %d ", x);
}

//! histograma verticala pentru litere
count_4(void)
{
    int x, c, nr_maxim, state, lit, nre, words;
    nr_maxim=lit=nre=words=0;
    int litere[27] = {0};
    /*!
        for(x='a'; x<='z'; x++)
        printf("%d|", x-96);
    => de la a la z sunt 26 caractere
    */

    state = OUT;
    while((c=getchar()) != '~')
    {
        if(c>='A' && c<='z')
        {
            c = toupper(c);
            litere[c-'A']++;
//! c - toupper(litera citita) <=> 65-90
//! -
//! 'A' - valoarea 65 in ASCII
//!-------------------------------------
//! 0-25
            lit++;
            state = IN;
        }
        else if(c>= '0' && c<= '9')
        {
            nre++;
            state = IN;
        }
        else if (c==' ' || c=='\t' || c=='\n')
            state = OUT;
        if(state == OUT)
        {
            words++;
            state = IN;
        }
    }

    printf("So you had %d words with %d letters and %d numbers\n\n\n", words, lit, nre);

    for(x=0; x<26; x++)
    {
        if(nr_maxim < litere[x])
        {
            nr_maxim = litere[x];
        }
    }

    for(x=nr_maxim; x>=0; x--)
    {
        while(x<=nr_maxim)
        {
            printf("Times x %d|", x+1);
            break;
        }
        for(c=0; c<26; c++)
        {
            if(litere[c] >= x)
                printf(" * ");
            else
                printf(" - ");
        }

        putchar('\n');
        puts("----------------------------------------------------------------------------------------");
    }

    printf("  Letter |");
    for(x=65; x<91; x++)
        printf(" %c ", x);
}

count_5(void)
{

}
