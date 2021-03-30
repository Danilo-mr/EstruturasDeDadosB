#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int qtd_comp, qtd_trocas;

#define n 2000

double selection(int v[]){
    clock_t start, finish;
    int i, j, aux, menor, escolhido, flag; 
    menor=v[0], qtd_comp=0, qtd_trocas=0;
    start=clock();
    for(j=0; j<n-1; j++){
        for(i=n-1; i>j; i--){
            qtd_comp++;
            if(v[i]<menor)
            {
                escolhido=i;
                flag=1;
            }
        }
        if(flag==1){
            qtd_trocas++;
            aux=menor;
            menor=v[escolhido];
            v[escolhido]=menor;
        }
    }
    finish=clock();
    return (double)(finish-start)/CLOCKS_PER_SEC; 
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

void impressao(double d){
    cout << "\n\nComparacoes: " << qtd_comp;
    cout << "\nTrocas: " << qtd_trocas;
    cout << "\nTempo de execucao: "  << d << "s"; 
}
int main() {
    int v[n];
    double duracao;

    cout << "\n\nVetor preenchido aleatoriamente";
    vetorAleatorio(v);
    duracao=selection(v);
    impressao(duracao);

    cout << "\n\nVetor Inversamente preenchido";
    vetorInverso(v);
    duracao=selection(v);
    impressao(duracao);

    cout << "\n\nVetor previamente ordenado";
    vetorOrdenado(v);
    duracao=selection(v);
    impressao(duracao);
   
}