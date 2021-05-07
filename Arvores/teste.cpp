/*Implementar um programa para manipulação de árvores binárias de busca.

O programa deve ter como base um menu de opções com pelo menos as seguintes funções:

- Inserção de um elemento N na árvore;

- Consulta (verifica se um número está armazenado na árvores);

- Percursos preordem, em ordem e posordem.

*/
#include <iostream>
#include <stdlib.h>

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
        if((*raiz)==NULL){
            cout << "\n\t\tHeap Overflow";
            return;
        }
        (*raiz)->chave=n;
        cout << "\n\t\tElemento inserido com SUCESSO!";
        (*raiz)->esq = (*raiz)->dir =NULL;
    } else {
        if(n < (*raiz)->chave) 
            inserir(n, &(*raiz)->esq);
        else {
            if(n > (*raiz)->chave)
                inserir(n, &(*raiz)->dir);
            else
                cout << "Elemento ja existe!\n";
        }
    }
}

int busca(int n, no *raiz){
    if(raiz==NULL) return 0;
    else if(raiz->chave==n) return 1;
    else if(n<raiz->chave) return(busca(n, raiz->esq));
    else return(busca(n, raiz->dir));
}

void em(no *raiz) {
    if(raiz!=NULL){
        em(raiz->esq);
        cout << raiz->chave << " ";
        em(raiz->dir);
    }
}
void pre(no *raiz) {
    if(raiz!=NULL){
        cout << raiz->chave << " ";
        pre(raiz->esq);
        pre(raiz->dir);
    }
}
void pos(no *raiz) {
    if(raiz!=NULL){
        pos(raiz->esq);
        pos(raiz->dir);
        cout << raiz->chave << " ";
    }
}

int main() {
    no *raiz=NULL;
    int opc, opc2, n;
    char resp;
    do {
        cout << "\n\n\n\t\t=====MENU=====";
        cout << "\n\t\t1 - Inserir";
        cout << "\n\t\t2 - Buscar";
        cout << "\n\t\t3 - Percursos";
        cout << "\n\t\t0 - Sair";
        cout << "\n\n\t\tOpcao: ";
        cin >> opc;
        switch (opc) {
            case 1:
            do {
                cout << "\n\n\tQual valor a ser inserido? ";
                cin >> n;
                inserir(n, &raiz);
                cout << "\n\tInserir mais elementos?[S/N] : ";
                cin >> resp;
                resp=toupper(resp);
            } while (resp!='N');
            break;
            case 2:
            do {
                cout << "\n\n\tConsultar qual numero? ";
                cin >> n;
                if(busca(n, raiz)==1) cout << "\tTem";
                else cout << "\tNao tem";
                cout << "\n\tConsultar mais numeros?[S/N] ";
                cin >> resp;
                resp=toupper(resp);
            } while(resp!='N');
            break;
            case 3:
            do {
                cout << "\n\n\t\t1- Em Ordem\n\t\t2- Pre Ordem\n\t\t3- Pos Ordem\n\n";
                cin >> opc2;
                if(opc2==1) em(raiz);
                if(opc2==2) pre(raiz);
                if(opc2==3) pos(raiz);
                cout << "\n\tPrintar mais percursos?[S/N] ";
                cin >> resp;
            } while(resp!='N');
            break;
            default:
            break;
        }
        system("cls");
    } while(opc!=0);

}