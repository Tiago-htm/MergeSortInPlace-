#ifndef MERGE_TRABALHO_C_H
#define MERGE_TRABALHO_C_H

typedef struct
{
    double tempo_execucao;
    int trocas;
    int comparacoes;
} Analises;

Analises *alocaStruct();

int *geraVetor(int quantidade, int semente, int opcaoVetor);

void imprimeVet(int *vet, int tam);

void imprimeResultado(Analises resultado);

void imprimeMediaResultados(Analises resultado[5]);

void InsertionSort(int *vet, int tam, Analises *resultado);

void SelectionSort(int *vet, int tam, Analises *resultado);

void MergeSortTradicional(int *v, int inicio, int fim, Analises *resultado);
void MergeTradicional(int *v, int inicio, int meio, int fim, Analises *resultado);

void MergeSortInPlace(int *v, int inicio, int fim, Analises *resultado);
void MergeInPlace(int *v, int inicio, int meio, int fim, Analises *resultado);

void QuickSort(int *vet, int inicio, int fim, Analises *resultado);

#endif /* MERGE_TRABALHO_C_H */