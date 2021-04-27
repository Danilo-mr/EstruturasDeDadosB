include <iostream>


Struct no {
    int chave;
    *raiz prox;
}

void pre(no *raiz) {
    if(raiz!=null) {
        cout << raiz->chave;
        pre(raiz->esq);
        pre(raiz->dir);
    }
}

int Main() {
    no *raiz;
    pre(&raiz); 
}