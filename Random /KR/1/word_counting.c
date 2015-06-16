#include <stdio.h>

#define IN 1        /*inside a word*/
#define OUT 0       /*outside a word*/

/*count lines, words and characters in input*/

wc_1(void);
wc_2(void);     // varianta mea
wc_3(void);

int main()
{
    wc_1();

    getchar();

    return 0;
}

wc_1(void)
{
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;    // adica este in afara cuvantului
    // state = IN - esti intr-un cuvanth

    printf("Say something %c\n", 42);

    while ((c = getchar()) != '~')
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT)
        {
            state == IN;
            ++nw;
        }
    }
    printf("You had %d words with %d characters, all on %d lines", nw, nc, nl);
}

wc_2(void)
{
    int c, l, w, ch;
    c = l = w = ch = 1;

    printf("Zii bah ceva %c\n", 33);
    while ((c = getchar()) != '~')
    {
        switch (c)
        {
        case '\n':
            l++;
            w++;
            break;
        case ' ':
            w++;
        default:
            ch++;
        }
    }
    while (getchar() != '\n')
        continue;
    printf("Prop ta a avut %d cuvinte cu %i caractere, pe %d linii", w, ch, l);
}

wc_3(void)
{
    /*************************************
    // Varianta mea
    **************************************
    int state, x, ln, cn, wn;
    int c[100];
    x = ln = cn = wn = 0;

    puts("Say something!");
    while ((c[x] = getchar()) != EOF)
    {
        printf("%c\n", c[x++]);
    }
    *************************************/

    /************************************
    // Varianta 'lui'
    ************************************/

    int c, linestarted = 0;

    puts("Say something");
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (!linestarted)   // linestarted = 0
            {
                putchar('\n');
                linestarted = 1;
            }
/**************************************
 * daca am scis ' ' || '\n' || '\t'
 * dar totusi linestarted e 1
 * if-ul ramane fara efect
 * ramane in art
 **************************************/
        }
        else
        {
            putchar(c);
            linestarted = 0;
        }

}
