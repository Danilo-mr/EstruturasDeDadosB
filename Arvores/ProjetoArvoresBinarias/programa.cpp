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

int mydel(no **x){
    if ((*x)->dir != NULL) 
        return(mydel (&(*x)->dir));
    else {
        int n = (*x)->chave;
        no *aux;
        aux=(*x)->esq;
        (*x)=aux;
        free(aux);
        return n;
    }
}

void remover(no **raiz, int n){
    if((*raiz)!=NULL) {
        if((*raiz)->chave==n) {
            no *aux;
            if((*raiz)->esq==NULL) {
                aux = (*raiz)->dir;
                (*raiz)=aux;
                free(aux);
            }
            else if((*raiz)->dir==NULL){
                aux = (*raiz)->esq;
                (*raiz)=aux;
                free(aux);
            } 
            else
                (*raiz)->chave=mydel(&(*raiz)->esq);
            cout << "\nRemovido com SUCESSO!";  
        }
        else if (n<(*raiz)->chave) remover(&(*raiz)->esq, n);
        else if (n>(*raiz)->chave) remover(&(*raiz)->dir, n);
    } else 
        cout << "\nElemento nao existe";
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
    int opcaoMenu, n;
    char resp;
    do {
        cout << "\n\n\n\t\t=====MENU=DE=OPCOES=DA=ARVORE=====";
        cout << "\n\t\t 1- Inserir"; 
        cout << "\n\t\t 2- Remover"; 
        cout << "\n\t\t 3- Buscar"; 
        cout << "\n\t\t 4- Maior elemento"; //fazer
        cout << "\n\t\t 5- Menor elemento"; //fazer
        cout << "\n\t\t 6- Quantidade de elementos(nos)"; //fazer
        cout << "\n\t\t 7- Altura da arvore(niveis)"; //fazer obs: raiz nivel 0
        cout << "\n\t\t 8- Quantidade de elementos pares e impares"; //fazer
        cout << "\n\t\t 9- Imprimir multiplos de 'k' e quantidade"; //fazer
        cout << "\n\t\t10- Imprimir em ordem crescente"; //fazer
        cout << "\n\t\t11- Imprimir em ordem decrescente"; //fazer
        cout << "\n\t\t12- Imprimir a soma dos valores dos nos"; //fazer
        cout << "\n\t\t13- Imprimir a media dos valores dos nos"; //fazer
        cout << "\n\t\t14- Imprimir o desvio padrao dos valores dos nos"; //fazer
        cout << "\n\t\t15- Imprimir a quantidade de NULLs presente na arvore"; //fazer
        cout << "\n\t\t16- Imprimir a quantidade de nos com dois filhos"; //fazer
        cout << "\n\t\t17- Imprimir a quantidade de nos com um filho"; //fazer
        cout << "\n\t\t18- Imprimir a quantidade de folhas"; //fazer
        cout << "\n\t\t19- Percorrer a arvore em ordem"; //fazer
        cout << "\n\t\t20- Percorrer a arvore em preordem"; //fazer
        cout << "\n\t\t21- Percorrer a arvore em posordem"; //fazer
        cout << "\n\t\t22- Percorrer a arvore em largura"; //fazer
        cout << "\n\t\t23- Salvar a arvore em arquivo"; //fazer
        cout << "\n\t\t24- Recuperar a arvore de arquivo"; //fazer
        cout << "\n\t\t25- Trocar de arvore"; //fazer
        cout << "\n\t\t26- Comparar duas arvores"; //fazer
        cout << "\n\t\t 0- Sair";
        cout << "\n\n\t\tOpcao: ";
        cin >> opcaoMenu;
        switch (opcaoMenu) {
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
                    cout << "\n\n\tQual valor a ser removido? ";
                    cin >> n;
                    remover(&raiz, n);
                    cout << "\n\tRemover mais elementos?[S/N] : ";
                    cin >> resp;
                    resp=toupper(resp);
                } while (resp!='N');
                break;

            case 3:

                do {
                    cout << "\n\n\tConsultar qual numero? ";
                    cin >> n;
                    if(busca(n, raiz)==1) cout << "\tELEMENTO ENCONTRADO !";
                    else cout << "\tELEMENTO NAO ENCONTRADO !";
                    cout << "\n\tConsultar mais numeros?[S/N] ";
                    cin >> resp;
                    resp=toupper(resp);
                } while(resp!='N');
                break;
            
            case 19:
                em(raiz);
                break;

            case 20:
                pre(raiz);
                break;

            case 21:
                pos(raiz);
                break;


                
            default:
            break;
        }

        system("cls");
    } while(opcaoMenu!=0);

}