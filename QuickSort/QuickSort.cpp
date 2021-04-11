#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

#define n 200000

long long int qtd_comp=0, qtd_trocas=0;
double duracao;

void quick(int v[], int Esq, int Dir){
    clock_t start, finish;
    int i, j, pivo, aux;

    i=Esq;      
    j=Dir;
    pivo=v[(Esq+Dir)/2];

    start=clock();

    do {
        while(v[i]<pivo) i++;
        while(v[j]>pivo) j--;
        qtd_comp++;
        if (i<=j) {
            qtd_trocas++;
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        }
    } while (i<j);
    if(Esq<j) quick (v, Esq, j);
    if(i<Dir) quick (v, i, Dir);
    finish=clock();
    duracao = (double)(finish-start)/CLOCKS_PER_SEC;
}

void imprimir (int v[]){
    int i;
    for(i=0; i<n; i++)
        cout << v[i] << " ";
}

void resultado(){
    cout << "\n\nComparacoes: " << qtd_comp;
    cout << "\nTrocas: " << qtd_trocas;
    cout << "\nTempo de execucao: "  << duracao << "s"; 
    cout << "\n\n\n";
}

void vetorAleatorio(int v[]){
    int i;
    for(i=0; i<n; i++)
        v[i]=rand()%100;
}

void vetorOrdenado(int v[]){
    int i;
    for(i=0; i<n; i++)
        v[i]=i;
}

void vetorInverso(int v[]){
    int i;
    for(i=0; i<n; i++)
        v[i] = n-i;
}

int main() {

    int v[n];

    cout << "\n\n\n\t\t\tVETOR ALEATORIO...";
    vetorAleatorio(v);
    quick(v, 0, n-1);
    resultado();
    
    cout << "\n\n\n\t\t\tVETOR ORDENADO...";
    vetorOrdenado(v);
    quick(v, 0, n-1);
    resultado();

    cout << "\n\n\n\t\t\tVETOR INVERSO...";
    vetorInverso(v);
    quick(v, 0, n-1);
    resultado();

}
