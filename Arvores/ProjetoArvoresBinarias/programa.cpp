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
        }
        (*raiz)->chave=n;
        cout << "\n\t\tElemento inserido com SUCESSO!";
        (*raiz)->esq = (*raiz)->dir =NULL;
        return;
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
        aux=(*x);
        (*x)=(*x)->esq;
        free(aux);
        return n;
    }
}

void remover(no **raiz, int n){
    if((*raiz)!=NULL) {
        if((*raiz)->chave==n) {
            no *aux;
            if((*raiz)->esq==NULL) {
                aux = (*raiz);
                (*raiz)=(*raiz)->dir;
                free(aux);
            }
            else if((*raiz)->dir==NULL){
                aux = (*raiz);
                (*raiz)=(*raiz)->esq;
                free(aux);
            } 
            else
                (*raiz)->chave=mydel(&(*raiz)->esq);
            cout << "\nRemovido com SUCESSO!";
            return;  
        }
        else if (n<(*raiz)->chave) remover(&(*raiz)->esq, n);
        else if (n>(*raiz)->chave) remover(&(*raiz)->dir, n);
    } else 
        cout << "\nElemento nao existe";
}

int maiorElem(no *raiz){
    if(raiz!=NULL)
        if(raiz->dir!=NULL) maiorElem(raiz->dir);
        else return raiz->chave;
    else {
        cout << "\n\tArvore vazia";
        return -1;
    }
}

int menorElem(no *raiz){
    if(raiz!=NULL)
        if(raiz->esq!=NULL) menorElem(raiz->esq);
        else return raiz->chave;
    else {
        cout << "\n\tArvore vazia";
        return -1;
    }
}

unsigned int qtdElem(no *raiz){
    unsigned int cont=0;
    if(raiz!=NULL){
        cont++;
        if(raiz->esq!=NULL)
            cont+=qtdElem(raiz->esq);
        if(raiz->dir!=NULL)
            cont+=qtdElem(raiz->dir);
        return cont;
    } 
    return cont;
}

unsigned int altura(no *raiz){
    unsigned int cont=0;
    unsigned int altE=0;
    unsigned int altD=0;
    if(raiz!=NULL){
        cont++;
        if(raiz->esq!=NULL) altE=altura(raiz->esq);
        if(raiz->dir!=NULL) altD=altura(raiz->dir);
        if(altE>altD) cont+=altE;
        else cont+=altD;
        return cont;
    }
    return cont;
}

unsigned int qtdPar(no *raiz){
    unsigned int cont=0;
    if(raiz!=NULL){
        if(raiz->chave%2==0) cont++;
        if(raiz->esq!=NULL) cont+=qtdPar(raiz->esq);
        if(raiz->dir!=NULL) cont+=qtdPar(raiz->dir);
        return cont;
    } else 
        cout << "\n\tArvore vazia!";
    return cont;
}

unsigned int qtdImpar(no *raiz){
    unsigned int cont=0;
    if(raiz!=NULL){
        if(raiz->chave%2!=0) cont++;
        if(raiz->esq!=NULL) cont+=qtdImpar(raiz->esq);
        if(raiz->dir!=NULL) cont+=qtdImpar(raiz->dir);
        return cont;
    } else 
        cout << "\n\tArvore vazia!";
    return cont;
}

int multiplos(no *raiz, int k){
    unsigned int cont=0;
    if(raiz!=NULL){
        if(raiz->esq!=NULL) cont+=multiplos(raiz->esq, k);
        if(raiz->chave%k==0){
            cont++;
            cout << raiz->chave << " ";
        } 
        if(raiz->dir!=NULL) cont+=multiplos(raiz->dir, k);
        return cont;
    } else 
        cout << "Arvore vazia ";
    return cont;
}

void decrescente(no *raiz){
    if(raiz!=NULL) {
        decrescente(raiz->dir);
        cout << raiz->chave << " ";
        decrescente(raiz->esq);
    }
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
        cout << "\n\t\t 4- Maior elemento"; 
        cout << "\n\t\t 5- Menor elemento"; 
        cout << "\n\t\t 6- Quantidade de elementos(nos)"; 
        cout << "\n\t\t 7- Altura da arvore(niveis)"; 
        cout << "\n\t\t 8- Quantidade de elementos pares e impares";
        cout << "\n\t\t 9- Imprimir multiplos de 'k' e quantidade"; 
        cout << "\n\t\t10- Imprimir em ordem crescente"; 
        cout << "\n\t\t11- Imprimir em ordem decrescente"; 
        cout << "\n\t\t12- Imprimir a soma dos valores dos nos"; 
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
            
            case 4:
                cout << "\n\tMAIOR ELEMENTO: " << maiorElem(raiz);
                break;

            case 5:
                cout << "\n\tMENOR ELEMENTO: " << menorElem(raiz);
                break;

            case 6:
                cout << "\n\tQUANTIDADE DE ELEMENTOS: " << qtdElem(raiz);
                break;
            
            case 7:
                cout << "\n\tALTURA DA ARVORE: " << altura(raiz) << " niveis";
                break;

            case 8:
                cout << "\n\t" << qtdPar(raiz) << " pares e " << qtdImpar(raiz) << " impares";
                break;

            case 9:
                int k, qtd;
                cout << "\n\tValor de 'K' :";
                cin >> k; 
                cout << "\n\t" << k << " = { ";
                qtd=multiplos(raiz, k);
                cout << "}";
                cout << "\n\t" << qtd << " multiplos de " << k;
                break;

            case 10:
                em(raiz);
                break;
            
            case 11:
                decrescente(raiz);
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
    } while(opcaoMenu!=0);

}