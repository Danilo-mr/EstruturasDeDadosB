#include <iostream>

using namespace std;

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

void inserir(int n, no **raiz){
    if((*raiz)==NULL)
    {
        *raiz = (no*) malloc(sizeof(no));
        (*raiz)->chave=n;
        (*raiz)->esq = (*raiz)->dir =NULL;
    } else 
        if(n < (*raiz)->chave) 
            inserir(n, &(*raiz)->esq);
        else 
            if(n > (*raiz)->chave)
                inserir(n, &(*raiz)->dir);
            else
            cout << "Elemento ja existe!\n";
}

int main() {
    no *raiz=NULL;
    int n;
    char resp;
    do {
        cout << "\nQual valor a ser inserido? ";
        cin >> n;
        inserir(n, &raiz);
        cout << "\n\tInserir mais elementos?[S/N] : ";
        cin >> resp;
        resp=toupper(resp);
    } while (resp!='N');
}