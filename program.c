#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    // imprime o cabeÃ§alho
    printf("**********************************\n");
    printf("* Bem vindo ao jogo de advinhação *\n");
    printf("**********************************\n\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;
    int nivel;

    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch (nivel)
    {
    case 1:
        numerodetentativas = 20;
        break;

    case 2:
        numerodetentativas = 15;
        break;

    default:
        numerodetentativas = 6;
        break;
    }

    for (int i = 1; i <= numerodetentativas; i++)
    {
        printf("Tentativa %d.\n\n", tentativas);
        printf("Qual é o seu chute? \n");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n\n", chute);

        if (chute < 0)
        {
            printf("Você não pode chutar numeros negativos!\n\n");

            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if (acertou)
        {
            break;
        }

        else if (maior)
        {
            printf("Seu chute foi maior que o número secreto.\n\n");
        }

        else
        {
            printf("Seu chute foi menor que o número secreto.\n\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / 2;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!\n");

    if (acertou)
    {
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Você de pontos: %.1f\n", pontos);
    }
    else
    {
        printf("Você perdeu! Tenta novamente!\n");
    }
}