#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

#define n 100000

int main () {
    int v[n], i, x, qtd_comp=0, esq, dir, pivo;
    bool flag;
    clock_t start, finish;
    double duracao;
    char resp;

    for(i=0; i<100000; i++){
        v[i]=i;
    }
    
    do {
        flag=false;
        qtd_comp=0;
        system("cls");
        cout << "\n\n\t\tQual o valor que quer encontrar?";
        cout << "\n\n\t\t\tDigite: ";
        cin >> x;

        //BUSCA SEQUENCIAL
        cout << "\n\n\n\t\t---------BUSCA SEQUENCIAL---------";
        start=clock();

        for(i=0; i<n; i++){
            qtd_comp++;
            if(v[i]==x)
            {
                flag=true;
                break;
            }
        }
        finish=clock();

        duracao = (double)(finish-start)/CLOCKS_PER_SEC;
        if(flag){
            cout << "\n\t\tElemento Encontrado";
        } else 
            cout << "\n\t\tElemento NAO Encontrado";
        cout << "\n\n\t\tNumero de comparacoes: " << qtd_comp; 
        cout << "\n\t\tTempo de busca: " << duracao << "s";

        //BUSCA BINARIA
        cout << "\n\n\n\t\t---------BUSCA BINARIA---------";
        flag=false;
        qtd_comp=0;

        start=clock();
        esq=0;
        dir=n-1;

        do {
            pivo=(esq+dir)/2;
            qtd_comp++;
            if(pivo==x) {
                flag=true;
                break;
            }
            if(x<pivo) dir=pivo-1;
            else esq=pivo+1;
        }while(esq<=dir);
        
        finish=clock();

        duracao = (double)(finish-start)/CLOCKS_PER_SEC;

        if(flag){
            cout << "\n\t\tElemento Encontrado";
        } else 
            cout << "\n\t\tElemento NAO Encontrado";
        cout << "\n\n\t\tNumero de comparacoes: " << qtd_comp; 
        cout << "\n\t\tTempo de busca: " << duracao << "s";



        cout << "\n\n\t\tRepitir? [S/N]: ";
        cin >> resp;
        resp=toupper(resp);
    } while (resp!='N');
        

} 