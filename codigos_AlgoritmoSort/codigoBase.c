int bolha (int *vet, int tam) {
//burro

    int cont = 0, i, j, aux;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam - 1; j++) {
            cont++;
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }

    return cont;
}
int BubbleSort (int *vet, int tam) {
//inteligente

    int cont = 0, i, j, aux, troca = 0;

    for (i = 1; i < tam; i++) {
        j = 0;
        troca = 0;

        while (j < (tam - i)) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                troca = 1;
            }
            cont++;
            j++;

        }

        if (troca == 0)
            return cont;
    }

    return cont;
}

//SELETION

void SelectionSort(int *vet, int tam){

    int marcador = 0;
    int menor;
    int aux;

    while (marcador < tam - 1) {
        menor = marcador;
        for (int i = marcador + 1; i < tam; i++) {
            if (vet[i] < vet[menor]) {
                menor = i;
            }
        }
        if (menor != marcador) {
            aux = vet[marcador];
            vet[marcador] = vet[menor];
            vet[menor] = aux;
        }
        marcador++;
    }
}

//INSERTION
void InsertionSort(int *vet, int tam){

    int marcador;
    int aux;
    int pos;

    for(marcador = 1;marcador<tam;marcador++){
        pos = marcador-1;
        aux = vet[marcador];
        while(aux<vet[pos] && pos >= 0){
            vet[pos+1] = vet[pos];
            pos = pos-1;
        }
        vet[pos+1]=aux;
    }
}
// MERGE
void Merge(int *vet, int inicio, int meio, int fim){
    int marcador1 = inicio;
    int marcador2 = meio+1;
    int i = 0;
    int *vetoraux;

    vetoraux = (int *)malloc(((fim-inicio)+1) * sizeof(int));
    if (vetoraux == NULL) {
        printf("ERRO AO ALOCAR MEMÓRIA\n");
        exit(1);
    }

    while(marcador1 <= meio && marcador2 <= fim){

        if (vet[marcador1]<=vet[marcador2])
            vetoraux[i++] = vet[marcador1++];
        else
            vetoraux[i++] = vet[marcador2++];
    }
    while(marcador1 <= meio)
        vetoraux[i++] = vet[marcador1++];

    while(marcador2 <= fim)
        vetoraux[i++]=vet[marcador2++];

    for(marcador1=inicio;marcador1<=fim;marcador1++)
        vet[marcador1] = vetoraux[marcador1-inicio];

    free(vetoraux);
}

void MergeSort(int *vet, int inicio, int fim){
    int meio;
    if(inicio < fim ){
        meio = (inicio+fim)/2;
        MergeSort(vet,inicio, meio);
        MergeSort(vet,meio+1,fim);
        Merge(vet,inicio,meio,fim);
    }
}

//QUICK SORT
int Particiona(int *vet, int inicio, int fim){
    int pivo = vet[inicio];
    int pos = inicio;
    int aux;

    for(int i = inicio+1;i <= fim;i++){
        if(vet[i] < pivo){
            pos++;
            if(i!=pos){
                aux=vet[i];
                vet[i]=vet[pos];
                vet[pos]=aux;
            }
        }
    }

    aux=vet[inicio];
    vet[inicio]=vet[pos];
    vet[pos]=aux;

    return pos;
}

void QuickSort(int *vet, int inicio, int fim){
    int posPivo;

    if(inicio < fim){
        posPivo = Particiona(vet, inicio, fim);
        QuickSort(vet, inicio, posPivo-1);
        QuickSort(vet, posPivo+1, fim);
    }
}

