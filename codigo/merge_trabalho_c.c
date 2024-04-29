#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_trabalho_c.h"

Analises *alocaStruct()
{
    Analises *resultado = (Analises *)malloc(sizeof(Analises));
    if (resultado == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    resultado->tempo_execucao = 0;
    resultado->trocas = 0;
    resultado->comparacoes = 0;

    return resultado;
}

int *geraVetor(int quantidade, int semente, int opcaoVetor)
{
    srand(semente);
    int *vetor = (int *)malloc(quantidade * sizeof(int));

    switch (opcaoVetor)
    {
    case 1:
        for (int i = 0; i < quantidade; i++)
        {
            vetor[i] = rand();
        }
        break;
    case 2:
        for (int i = 0; i < quantidade; i++)
        {
            vetor[i] = i;
        }
        break;
    case 3:
        for (int i = 0; i < quantidade; i++)
        {
            vetor[i] = quantidade - i;
        }
        break;
    case 4:
        for (int i = 0; i < quantidade; i++)
        {
            vetor[i] = i;
        }

        for (int i = 0; i < quantidade / 2; i++)
        {
            int j = rand() % quantidade;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
        break;
    default:
        printf("Opção de vetor inválida.\n");
        free(vetor);
        return NULL;
    }
    return vetor;
}

void imprimeVet(int *vet, int tam)
{
    if (vet == NULL)
    {
        printf("Vetor inválido.\n");
        return;
    }

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void imprimeResultado(Analises resultado)
{
    printf("Tempo de execucao: %.15f\n", resultado.tempo_execucao);
    printf("Trocas: %d\n", resultado.trocas);
    printf("Comparacoes: %d\n", resultado.comparacoes);
}

void imprimeMediaResultados(Analises resultado[5])
{
    double media_tempo_execucao = 0;
    double media_trocas = 0;
    double media_comparacoes = 0;

    for (int i = 0; i < 5; i++)
    {
        media_tempo_execucao += (double)resultado[i].tempo_execucao;
        media_trocas += (double)resultado[i].trocas;
        media_comparacoes += (double)resultado[i].comparacoes;
        // imprimeResultado(resultado[i]);
        // printf("\nTESTEmedia_tempo_execucao: %d", media_tempo_execucao);
        // printf("\nTESTEmedia_trocas: %d", media_trocas);
        // printf("\nTESTEmedia_comparacoes: %d", media_comparacoes);
    }
    media_tempo_execucao = media_tempo_execucao / 5;
    media_trocas = media_trocas / 5;
    media_comparacoes = media_comparacoes / 5;

    printf("Media tempo de execucao: %.15f\n", media_tempo_execucao);
    printf("Media trocas: %d\n", (int)media_trocas);
    printf("Media comparacoes: %d\n", (int)media_comparacoes);
}

void InsertionSort(int *vet, int tam, Analises *resultado)
{

    int i, j, aux, comparacoes = 0, trocas = 0;
    clock_t inicio, fim;

    inicio = clock();

    for (i = 1; i < tam; i++)
    {
        aux = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > aux)
        {
            comparacoes++;
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
        trocas++;
    }

    fim = clock();

    resultado->comparacoes = comparacoes;
    resultado->trocas = trocas;
    resultado->tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void SelectionSort(int *vet, int tam, Analises *resultado)
{
    clock_t inicio, fim;
    inicio = clock();

    int comparacoes = 0;
    int trocas = 0;

    for (int i = 0; i < tam - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < tam; j++)
        {
            comparacoes++;
            if (vet[j] < vet[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = vet[i];
            vet[i] = vet[min];
            vet[min] = temp;
            trocas++;
        }
    }

    fim = clock();

    resultado->comparacoes = comparacoes;
    resultado->trocas = trocas;
    resultado->tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void MergeSortTradicional(int *v, int inicio, int fim, Analises *resultado)
{

    clock_t inicio_clock = clock();

    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        MergeSortTradicional(v, inicio, meio, resultado);
        MergeSortTradicional(v, meio + 1, fim, resultado);
        MergeTradicional(v, inicio, meio, fim, resultado);
    }

    clock_t fim_clock = clock();
    resultado->tempo_execucao += (double)(fim_clock - inicio_clock) / CLOCKS_PER_SEC;
}

void MergeTradicional(int *v, int inicio, int meio, int fim, Analises *resultado)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
        resultado->comparacoes++;
        resultado->trocas++;
    }

    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
        resultado->trocas++;
    }

    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
        resultado->trocas++;
    }

    free(L);
    free(R);
}

void MergeSortInPlace(int *v, int inicio, int fim, Analises *resultado)
{
    clock_t inicio_clock = clock();

    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        MergeSortInPlace(v, inicio, meio, resultado);
        MergeSortInPlace(v, meio + 1, fim, resultado);

        if (v[meio] <= v[meio + 1])
        {
            return;
        }

        MergeInPlace(v, inicio, meio, fim, resultado);
    }

    clock_t fim_clock = clock();
    resultado->tempo_execucao += (double)(fim_clock - inicio_clock) / CLOCKS_PER_SEC;
}

void MergeInPlace(int *vetor, int inicio, int meio, int fim, Analises *resultado)
{
    int i = inicio, j = meio + 1;

    while (i <= meio && j <= fim)
    {
        if (vetor[i] <= vetor[j])
        {
            i++;
        }
        else
        {
            int temp = vetor[j];

            for (int k = j; k > i; k--)
            {
                vetor[k] = vetor[k - 1];
            }

            vetor[i] = temp;
            i++;
            j++;
            meio++;
            resultado->trocas++;
        }
        resultado->comparacoes++;
    }
}

void QuickSort(int *vet, int inicio, int fim, Analises *resultado)
{
    clock_t inicio_clock = clock();

    int i, j, pivo, aux;
    i = inicio;
    j = fim;
    pivo = vet[(inicio + fim) / 2];

    while (i <= j)
    {
        while (vet[i] < pivo)
        {
            i++;
            resultado->comparacoes++;
        }
        while (vet[j] > pivo)
        {
            j--;
            resultado->comparacoes++;
        }

        if (i <= j)
        {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
            resultado->trocas++;
        }
    }

    if (j > inicio)
        QuickSort(vet, inicio, j, resultado);
    if (i < fim)
        QuickSort(vet, i, fim, resultado);

    clock_t fim_clock = clock();
    resultado->tempo_execucao += (double)(fim_clock - inicio_clock) / CLOCKS_PER_SEC;
}
