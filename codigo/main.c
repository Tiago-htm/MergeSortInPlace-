#include <stdio.h>
#include <stdlib.h>
#include "merge_trabalho_c.h"

int main()
{
    int opcaoVetor, quantidade, semente, opcaoAlgoritmo;
    int *vet;
    double tempos[5] = {0, 0, 0, 0, 0};
    double comparacoes[5] = {0, 0, 0, 0, 0};
    double trocas[5] = {0, 0, 0, 0, 0};
    Analises resultados[5];
    Analises resultado;

    // LER OPÇÃO VETOR
    printf("Escolha uma opcao:\n");
    printf("1 - Numeros aleatorios\n");
    printf("2 - Numeros ordenados\n");
    printf("3 - Numeros decrescentes\n");
    printf("4 - Numeros quase ordenados\n");
    // validação
    if (scanf("%d", &opcaoVetor) != 1 || getchar() != '\n')
    {
        printf("Opcao invalida\n");
        return 1;
    }
    if (opcaoVetor < 1 || opcaoVetor > 4)
    {
        printf("Opcao invalida\n");
        return 1;
    }
    printf("\n");

    // LER TAMANHO VETOR
    printf("Qual a quantidade de valores a serem gerados?\n");
    // validação
    if (scanf("%d", &quantidade) != 1 || getchar() != '\n')
    {
        printf("Quantidade invalida\n");
        return 1;
    }
    if (quantidade < 1)
    {
        printf("Quantidade invalida\n");
        return 1;
    }
    printf("\n");

    // LER SEMENTE
    printf("Qual o valor para a semente?\n");
    // validação
    if (scanf("%d", &semente) != 1 || getchar() != '\n')
    {
        printf("Quantidade invalida\n");
        return 1;
    }
    printf("\n");

    // LER ALGORITMO
    printf("Com qual algoritmo deseja ordenar?\n");
    printf("1 - InsertionSort\n");
    printf("2 - SelectionSort\n");
    printf("3 - MergeSortTradicional\n");
    printf("4 - MergeSortInPlace\n");
    printf("5 - QuickSort\n");
    // validação
    if (scanf("%d", &opcaoAlgoritmo) != 1 || getchar() != '\n')
    {
        printf("Opcao invalida\n");
        return 1;
    }
    if (opcaoAlgoritmo < 1 || opcaoAlgoritmo > 5)
    {
        printf("Opcao invalida\n");
        return 1;
    }
    printf("\n");

    // EXECUTA ALGORITMO
    switch (opcaoAlgoritmo)
    {
    case 1:
        printf("Voce esta em: InsertionSort\n");
        // se opcaoVetor for 1 ou 4 preciso fazer 5 vezes senao 1 vez
        if (opcaoVetor == 1 || opcaoVetor == 4)
        {

            for (int i = 0; i < 5; i++)
            {
                // GERA VETOR
                vet = geraVetor(quantidade, semente + i, opcaoVetor);
                // validação
                if (vet == NULL)
                {
                    printf("Erro ao alocar memoria\n");
                    return 1;
                }
                // imprime vetor
                printf("Vetor gerado:\n");
                imprimeVet(vet, quantidade);

                InsertionSort(vet, quantidade, &resultado);
                printf("Execucao numero %d\n", i);
                imprimeResultado(resultado);
                resultados[i] = resultado;
            }
            // média dos resultados
            imprimeMediaResultados(resultados);
        }
        else
        {
            // GERA VETOR
            vet = geraVetor(quantidade, semente, opcaoVetor);
            // validação
            if (vet == NULL)
            {
                printf("Erro ao alocar memoria\n");
                return 1;
            }
            // imprime vetor
            printf("Vetor gerado:\n");
            imprimeVet(vet, quantidade);

            InsertionSort(vet, quantidade, &resultado);
            imprimeResultado(resultado);
            break;
        }
        break;
    case 2:
        printf("Voce esta em: SelectionSort\n");
        // se opcaoVetor for 1 ou 4 preciso fazer 5 vezes senao 1 vez
        if (opcaoVetor == 1 || opcaoVetor == 4)
        {

            for (int i = 0; i < 5; i++)
            {
                // GERA VETOR
                vet = geraVetor(quantidade, semente + i, opcaoVetor);
                // validação
                if (vet == NULL)
                {
                    printf("Erro ao alocar memoria\n");
                    return 1;
                }
                // imprime vetor
                printf("Vetor gerado:\n");
                imprimeVet(vet, quantidade);

                SelectionSort(vet, quantidade, &resultado);
                printf("\nExecucao numero %d\n", i);
                imprimeResultado(resultado);
                resultados[i] = resultado;
            }
            // média dos resultados
            imprimeMediaResultados(resultados);
        }
        else
        {
            // GERA VETOR
            vet = geraVetor(quantidade, semente, opcaoVetor);
            // validação
            if (vet == NULL)
            {
                printf("Erro ao alocar memoria\n");
                return 1;
            }
            // imprime vetor
            printf("Vetor gerado:\n");
            imprimeVet(vet, quantidade);

            SelectionSort(vet, quantidade, &resultado);
            imprimeResultado(resultado);
        }
        break;

    case 3:
        printf("Voce esta em: MergeSortTradicional\n");
        // se opcaoVetor for 1 ou 4 preciso fazer 5 vezes senao 1 vez
        if (opcaoVetor == 1 || opcaoVetor == 4)
        {

            for (int i = 0; i < 5; i++)
            {
                // GERA VETOR
                vet = geraVetor(quantidade, semente + i, opcaoVetor);
                // validação
                if (vet == NULL)
                {
                    printf("Erro ao alocar memoria\n");
                    return 1;
                }
                // imprime vetor
                printf("Vetor gerado:\n");
                imprimeVet(vet, quantidade);

                MergeSortTradicional(vet, 0, quantidade - 1, &resultado);
                printf("Execucao numero %d\n", i);
                imprimeResultado(resultado);
                resultados[i] = resultado;
            }
            // média dos resultados
            imprimeMediaResultados(resultados);
        }
        else
        {
            // GERA VETOR
            vet = geraVetor(quantidade, semente, opcaoVetor);
            // validação
            if (vet == NULL)
            {
                printf("Erro ao alocar memoria\n");
                return 1;
            }
            // imprime vetor
            printf("Vetor gerado:\n");
            imprimeVet(vet, quantidade);

            MergeSortTradicional(vet, 0, quantidade - 1, &resultado);
            imprimeResultado(resultado);
        }
        break;

    case 4:
        printf("Voce esta em: MergeSortInPlace\n");
        // se opcaoVetor for 1 ou 4 preciso fazer 5 vezes senao 1 vez
        if (opcaoVetor == 1 || opcaoVetor == 4)
        {

            for (int i = 0; i < 5; i++)
            {
                // GERA VETOR
                vet = geraVetor(quantidade, semente + i, opcaoVetor);
                // validação
                if (vet == NULL)
                {
                    printf("Erro ao alocar memoria\n");
                    return 1;
                }
                // imprime vetor
                printf("Vetor gerado:\n");
                imprimeVet(vet, quantidade);

                MergeSortInPlace(vet, 0, quantidade - 1, &resultado);
                printf("Execucao numero %d\n", i);
                imprimeResultado(resultado);
                resultados[i] = resultado;
            }
            // média dos resultados
            imprimeMediaResultados(resultados);
        }
        else
        {
            // GERA VETOR
            vet = geraVetor(quantidade, semente, opcaoVetor);
            // validação
            if (vet == NULL)
            {
                printf("Erro ao alocar memoria\n");
                return 1;
            }
            // imprime vetor
            printf("Vetor gerado:\n");
            imprimeVet(vet, quantidade);

            MergeSortInPlace(vet, 0, quantidade - 1, &resultado);
            imprimeResultado(resultado);
        }
        break;

    case 5:
        printf("Voce esta em: QuickSort\n");
        // se opcaoVetor for 1 ou 4 preciso fazer 5 vezes senao 1 vez
        if (opcaoVetor == 1 || opcaoVetor == 4)
        {

            for (int i = 0; i < 5; i++)
            {
                // GERA VETOR
                vet = geraVetor(quantidade, semente + i, opcaoVetor);
                // validação
                if (vet == NULL)
                {
                    printf("Erro ao alocar memoria\n");
                    return 1;
                }
                // imprime vetor
                printf("Vetor gerado:\n");
                imprimeVet(vet, quantidade);

                QuickSort(vet, 0, quantidade - 1, &resultado);
                printf("Execucao numero %d\n", i);
                imprimeResultado(resultado);
                resultados[i] = resultado;
            }
            // média dos resultados
            imprimeMediaResultados(resultados);
        }
        else
        {
            // GERA VETOR
            vet = geraVetor(quantidade, semente, opcaoVetor);
            // validação
            if (vet == NULL)
            {
                printf("Erro ao alocar memoria\n");
                return 1;
            }
            // imprime vetor
            printf("Vetor gerado:\n");
            imprimeVet(vet, quantidade);

            QuickSort(vet, 0, quantidade - 1, &resultado);
            imprimeResultado(resultado);
        }
        break;

    default:
        printf("Opção de algoritmo inválida.\n");
        return 1;
    }

    return 0;
}