#include <iostream>
#include <locale.h>
#include <ctime>
#include <iomanip>

using namespace std;

#define n 200000

int main() {
  setlocale(LC_ALL,"PORTUGUESE");
  
  clock_t start, finish;

  int i, v[n], aux, stop=0, j, opc;
  long long int qtd_comp=0, qtd_trocas=0;
  double duracao;
  cout << "\tComo vai querer o vetor?";
  cout << "\n(1)Vetor preenchido com números aleatórios";
  cout << "\n(2)Vetor previamente ordenado";
  cout << "\n(3)Vetor inversamente ordenado";
  cout << "\n\n\tOpção...";
  
  cin >> opc;
  switch (opc){
    case 1:
      //Preenchido c/ números aleatórios
      for(i=0; i<n; i++)
        v[i]=rand()%100;
      break;
    case 2:
      //Previamente ordenado
      for(i=0; i<n; i++)
        v[i]=i;
      break;
    case 3:
      //Inversamente ordenado
      for(i=0; i<n; i++)
        v[i] = n-i;
      break;
    default:
      break;
  }
  cout << "\n\n\t\t\t\t\t\tOrdenando...";
  
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
  cout << "Pronto!";

  finish=clock();
  duracao = (double)(finish-start)/CLOCKS_PER_SEC;

  cout << "\n\n\nComparacoes: " << qtd_comp;
  cout << "\nTrocas: " << qtd_trocas;
  cout << "\nTempo de execucao: "  << duracao << "s"; 
  cout << "\n\n\n";
}