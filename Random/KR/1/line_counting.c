#include <stdio.h>

void ln_1(void);
void ln_2(void);
void ln_3(void);

int main()
{
    ln_3();

    getchar();

    return 0;
}

ln_1(void)
{
    int c, nl = 1, tabs = 0, blanks = 0;

    while ((c = getchar()) != '~')
        switch (c)
        {
        case ' ':
            blanks++;
            break;
        case '\t':
            tabs++;
            break;
        case'\n':
            nl++;
            break;
        default:
            continue;
        }

    printf("Tabs = %d\nBlaks = %d\nNl = %i", tabs, blanks, nl);
    while (c = getchar() != '10') // 10 in ascii e newline -'/n'
        continue;
}

ln_2(void)
{
    int c, am_primit_deja_spatiu;
    am_primit_deja_spatiu = 0;
    printf("Input some characters, when you finishes, press Ctrl+D.\n");
    while ((c = getchar()) != EOF)
        if (c == ' ')
        {
            if (!am_primit_deja_spatiu )
            {
                am_primit_deja_spatiu = 1;
                putchar(c);
            }
        }
        else
        {
            am_primit_deja_spatiu = 0;
            putchar(c);
        }
}

ln_3(void)
{
	char c;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\t':
            printf("\\t");
            break;
        case '\b':
            printf("\\b");
            break;
        case '\\':
            printf("\\\\");
            break;
        default:
            putchar(c);

        }
    }
}
