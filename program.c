#include <stdio.h>
#include <stdlib.h>
#include  <time.h>

int main()
{
    printf("**********************************\n");
    printf("* Welcome to the fortune-telling *\n");
    printf("**********************************\n\n");

    int seconds = time(0);
    srand(seconds);

    int bignumber = rand();

    int secretnumber = bignumber % 100;

    int kick;
    int winner = 0;
    int try = 1;

    double points = 1000;

    while (1)
    {
        printf("Attempt %d.\n\n", try);
        printf("What is your kick? \n");

        scanf("%d", &kick);
        printf("His kick was %d\n\n", kick);

        if (kick < 0)
        {
            printf("You can not kicker negative numbers!\n\n");

            continue;
        }

        int hit = (kick == secretnumber);
        int largest = (kick > secretnumber);

        if (hit)
        {
            printf("You Win! Congratulations.\n\n");

            break;
        }

        else if (largest)
        {
            printf("Your number is largest than the secret number.\n\n");
        }

        else
        {
            printf("Your number is smaller than the secret number.\n\n");
        }

        try++;

        double lostpoints = abs(kick - secretnumber) / 2;
        points = points - lostpoints;
    }

    printf("End game!\n");
    printf("You got it right in %d tries!\n", try);
    printf("Total points: %.1f\n", points);
}
