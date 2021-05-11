/* 
                            ORDEM DOS ELEMENTOS
    # emOrdem   ERD     Esquerda -> Raiz -> Direita
    # preOrdem  RED     Raiz -> Esquerda -> Direita
    # posOrdem  EDR     Esquerda -> Direita -> Raiz
*/

#include <iostream>

using namespace std;

typedef tno no;
struct tno{
    int chave;
    tno *esq;
    tno *dir;
};

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
    
    em(raiz);
    pre(raiz);
    pos(raiz);
}