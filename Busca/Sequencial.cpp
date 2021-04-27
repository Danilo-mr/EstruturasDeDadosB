/*Para a busca Sequencial, são feitas H comparações para um vetor tamanho H
  No caso de um vetor de 1023 posições, são feitos 1023 comparações
  No caso de um vator de 32765 posições, são feitos 32765 comparações
*/
#include <iostream>

using namespace std;

int main() {
  int x, v[1023], i, cont=0;

  for (i=0; i<1023; i++){
    v[i] = i;
  }
  
  cout << "Qual o valor a ser buscado? ";
  cin >> x;

  for (i=0; i<1023; i++){
    cont++;
    if(x==v[i]){
      cout << "Valor encontrado!\n";
      cout << "Numero de comparacoes: " << cont;
    
      return 0;
    }
  }

  cout << "Valor nao encontrado!" << endl;
   
}
