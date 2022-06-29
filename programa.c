#include <stdio.h>

//#define NUMBER_OF_ATTEMPTS 5

int main()
{
    printf("**********************************\n");
    printf("* Welcome to the fortune-telling *\n");
    printf("**********************************\n\n");

    int secretnumber = 42;

    int kick;
    int winner = 0;
    int try = 1;

    // printf("The number %d is secret. Don't tell anyone!\n\n", secretnumber);

    /*for (int i = 1; i <= NUMBER_OF_ATTEMPTS; i++)
    {
        printf("Attempt %d of %d.\n\n", i, NUMBER_OF_ATTEMPTS);
        printf("What is your kick? \n");
        scanf("%d", &kick);
        printf("His kick was %d\n\n", kick);

        if(kick < 0){
            printf("You can not kicker negative numbers!\n\n");
            i--;

            continue;
        }

        int acertou = (kick == secretnumber);
        int largest = (kick > secretnumber);
        int smaller = (kick > secretnumber);

        if (acertou)
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
    }*/

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
    }

    printf("End game!\n");
    printf("You got it right in %d tries!", try);
}
