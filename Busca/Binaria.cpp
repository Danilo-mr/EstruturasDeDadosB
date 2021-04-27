/*Na sequencia Binaria, para um vetor de 1023, o pior caso ficou como 10 comparacoes
e no vetor de 32765 o pior caso foi de 15 comparacoes
*/

#include <iostream>

using namespace std;

int main() {
  int x, dir, esq, pivo, n, i, cont=0;

  cout << "Qual o tamanho do vetor? ";
  cin >> n;
  int v[n];

  cout << "Qual o valor a ser buscado? ";
  cin >> x;

  for (i=0; i<n; i++)
    v[i]=i;
  
  esq=0;
  dir=n-1;
  
  while(dir>=esq){
    cont++;
    pivo=v[(dir+esq)/2];
    //cout << "\npivo: "<< pivo << "\n";
    if(pivo==x){
      cout << "Valor encontrado!" << endl;
      cout << "Numero de comparacoes: " << cont;
      return 0;
    } else if(pivo>x){
      dir=((dir+esq)/2)-1;
    
    } else 
      esq=((esq+dir)/2)+1;
  }
  cout << "Valor nao encontrado!" << endl;
  cout << "Numero de comparacoes: " << cont;

}