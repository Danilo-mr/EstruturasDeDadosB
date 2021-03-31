#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

#define n 100000

long long int qtd_comp=0, qtd_trocas=0;
double duracao;

void imprimir (int v[]){
    int i;
    for(i=0; i<n; i++)
        cout << v[i] << " ";
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

void selection(int v[]){
    qtd_comp=0, qtd_trocas=0;
    clock_t start, finish;
    int i, j, pos, aux;


    start=clock();
    for(i=0; i<n-1; i++)
    {
        pos=i;
        for(j=i+1; j<n; j++)
        {
            qtd_comp++;
            if(v[j]<v[pos])
                pos=j;
        }
        if(pos!=i){
            qtd_trocas++;
            aux=v[pos];
            v[pos]=v[i];
            v[i]=aux;
        }
    }
    finish=clock();
    duracao = (double)(finish-start)/CLOCKS_PER_SEC; 
}

void resultado(){
    cout << "\n\nComparacoes: " << qtd_comp;
    cout << "\nTrocas: " << qtd_trocas;
    cout << "\nTempo de execucao: "  << duracao << "s"; 
    cout << "\n\n\n";
}

void bubbleSort(int v[]){
    qtd_comp=0, qtd_trocas=0;
    clock_t start, finish;
    int stop, i, aux;

    start=clock();
    for(stop=0; stop<n-1; stop++){
        for(i=n-1; i>stop; i--){
            qtd_comp++;
            if(v[i]<v[i-1]){ 
                qtd_trocas++;
                aux=v[i];
                v[i]=v[i-1];
                v[i-1]=aux;
            }
        }
    }
    finish=clock();
    duracao = (double)(finish-start)/CLOCKS_PER_SEC;
}

int main() {


    int v[n];

    cout << "\n\n\n\t\t\tVETOR ALEATORIO...";
    vetorAleatorio(v);
    selection(v);
    
    cout << "\n\n---------SELECT-SORT-------";
    resultado();    
    vetorAleatorio(v);
    bubbleSort(v);
    cout << "\n\n---------BUBBLE-SORT-------";
    resultado();

    cout << "\n\n\n\t\t\tVETOR ORDENADO...";
    vetorOrdenado(v);
    selection(v);
    cout << "\n\n---------SELECT-SORT-------";
    resultado();
    vetorOrdenado(v);
    bubbleSort(v);
    cout << "\n\n---------BUBBLE-SORT-------";
    resultado();

    cout << "\n\n\n\t\t\tVETOR INVERSO...";
    vetorInverso(v);
    selection(v);
    cout << "\n\n---------SELECT-SORT-------";
    resultado();
    vetorInverso(v);
    bubbleSort(v);
    cout << "\n\n---------BUBBLE-SORT-------";
    resultado();
}
