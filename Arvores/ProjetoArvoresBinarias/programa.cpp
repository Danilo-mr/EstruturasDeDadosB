#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <windows.h>

using namespace std;

#define qtdArv 100

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct dado{
    int cod;
    struct dado *prox;
};

void menu(){
    cout << "\n\n\n\n\t\t=====MENU=DE=OPCOES=DA=ARVORE=====";
    cout << "\n\t\t 1- Inserir"; 
    cout << "\n\t\t 2- Remover"; 
    cout << "\n\t\t 3- Buscar"; 
    cout << "\n\t\t 4- Maior elemento"; 
    cout << "\n\t\t 5- Menor elemento"; 
    cout << "\n\t\t 6- Quantidade de elementos(nos)"; 
    cout << "\n\t\t 7- Altura da arvore(niveis)"; 
    cout << "\n\t\t 8- Quantidade de elementos pares e impares";
    cout << "\n\t\t 9- Imprimir multiplos de 'k' e quantidade"; 
    cout << "\n\t\t10- Ordem crescente"; 
    cout << "\n\t\t11- Ordem decrescente"; 
    cout << "\n\t\t12- Soma dos valores dos nos"; 
    cout << "\n\t\t13- Media dos valores dos nos";
    cout << "\n\t\t14- Desvio padrao dos valores dos nos";
    cout << "\n\t\t15- Quantidade de NULLs presente na arvore";
    cout << "\n\t\t16- Quantidade de nos com dois filhos"; 
    cout << "\n\t\t17- Quantidade de nos com um filho"; 
    cout << "\n\t\t18- Quantidade de folhas";
    cout << "\n\t\t19- Percorrer a arvore em ordem"; 
    cout << "\n\t\t20- Percorrer a arvore em preordem"; 
    cout << "\n\t\t21- Percorrer a arvore em posordem"; 
    cout << "\n\t\t22- Percorrer a arvore em largura";
    cout << "\n\t\t23- Salvar a arvore em arquivo"; 
    cout << "\n\t\t24- Recuperar a arvore de arquivo"; 
    cout << "\n\t\t25- Trocar de arvore";
    cout << "\n\t\t26- Comparar duas arvores"; 
    cout << "\n\t\t 0- Sair";
}

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

void removerArv(no **raiz, int n){
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
        else if (n<(*raiz)->chave) removerArv(&(*raiz)->esq, n);
        else if (n>(*raiz)->chave) removerArv(&(*raiz)->dir, n);
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

unsigned int soma(no *raiz){
    unsigned int s=0;
    if(raiz!=NULL){
        s=raiz->chave;
        if(raiz->esq!=NULL) s+=soma(raiz->esq);
        if(raiz->dir!=NULL) s+=soma(raiz->dir);
        return s;
    } else 
        cout << "\n\tArvore vazia";
    return s;
}

float desvioPadrao(no *raiz, float media){
    float des=0.0;
    if(raiz!=NULL){
        des=pow((float)raiz->chave-media, 2);
        if(raiz->esq!=NULL) des+=desvioPadrao(raiz->esq, media);
        if(raiz->dir!=NULL) des+=desvioPadrao(raiz->dir, media);
        return des;
    } else
        cout << "\n\tArvore vazia";
    return des;
}

unsigned int qtd2Filhos(no *raiz){
    unsigned int cont=0;
    if(raiz!=NULL){
        if(raiz->esq!=NULL){
            if(raiz->dir!=NULL) cont++;
            cont+=qtd2Filhos(raiz->esq);
        } 
        if(raiz->dir!=NULL) cont+=qtd2Filhos(raiz->dir);
        return cont;
    } else 
        cout << "\n\tArvore Vazia";
    return cont;
}

unsigned int qtd1Filho(no *raiz){
    unsigned int cont=0;
    if(raiz!=NULL){
        if(raiz->esq!=NULL){
            if(raiz->dir==NULL) cont++;
            cont+=qtd1Filho(raiz->esq);
        }
        if(raiz->dir!=NULL){
            if(raiz->esq==NULL) cont++;
            cont+=qtd1Filho(raiz->dir);
        }
        return cont;
    } else  
        cout << "\n\tArvore Vazia";
    return cont;
}

unsigned int qtdNull(no *raiz){
    unsigned int cont=0;
    if(raiz!=NULL){
        if(raiz->esq==NULL) cont++;
        else cont+=qtdNull(raiz->esq);
        if(raiz->dir==NULL) cont++;
        else cont+=qtdNull(raiz->dir);
        return cont;
    } else cout << "\n\tArvore vazia";
    return cont;
}

unsigned int qtdFolhas(no *raiz){
    unsigned int cont=0;
    if(raiz!=NULL){
        if(raiz->esq==NULL && raiz->dir==NULL) cont++;
        if(raiz->esq!=NULL) cont+=qtdFolhas(raiz->esq);
        if(raiz->dir!=NULL) cont+=qtdFolhas(raiz->dir);
        return cont;
    } else cout << "\n\tArvore vazia";
    return cont;
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

void removerFila(dado **fila){
    if((*fila)!=NULL){
        dado *aux=(*fila);
        (*fila)=(*fila)->prox;
        free(aux);
    }
}

int encontrar(int x, no **raiz){
    if((*raiz)!=NULL){
        if((*raiz)->chave==x) return 1;
        else if(x<(*raiz)->chave){
            if(encontrar(x, &(*raiz)->esq)==1) (*raiz)=(*raiz)->esq;
        }
        else if(x>(*raiz)->chave){
            if(encontrar(x, &(*raiz)->dir)==1) (*raiz)=(*raiz)->dir;
        }
        return 1;
    }
}

void inserirFila(dado **fila, no *raiz){
    dado *aux, *aux2;
    encontrar((*fila)->cod, &raiz);
    if(raiz->esq!=NULL) {
        aux2=(*fila);
        while(aux2->prox!=NULL) aux2=aux2->prox;
        aux = (dado*) malloc(sizeof(dado));
        aux->cod=raiz->esq->chave;
        aux->prox=NULL;
        aux2->prox=aux;
    }
    if(raiz->dir!=NULL) {
        aux2=(*fila);
        while(aux2->prox!=NULL) aux2=aux2->prox;
        aux = (dado*) malloc(sizeof(dado));
        aux->cod=raiz->dir->chave;
        aux->prox=NULL; 
        aux2->prox=aux;
    }
}

void largura(no *raiz, dado **fila){
    if(raiz!=NULL){
        *fila = (dado*) malloc(sizeof(dado));
        (*fila)->cod=raiz->chave;
        (*fila)->prox=NULL;
        while((*fila)!=NULL){
            inserirFila(&(*fila), raiz);
            cout << (*fila)->cod << " ";
            removerFila(fila);
        }
    } else 
        cout << "\n\tArvore vazia";
}

void salvar(no *raiz, ofstream *arquivoS){
    if(raiz!=NULL) {
        *arquivoS << raiz->chave << endl;
        if(raiz->esq!=NULL) salvar(raiz->esq, arquivoS);
        if(raiz->dir!=NULL) salvar(raiz->dir, arquivoS);
    } else {
        cout << "\n\tArvore Vazia";
        return;
    }
}

int iguais(no *raiz1, no *raiz2){
    if(raiz1==NULL && raiz2==NULL) return 1;
    if(raiz1==NULL || raiz2==NULL) return 0;
    if(raiz1->chave!=raiz2->chave) return 0;
    return(iguais(raiz1->esq, raiz2->esq) && iguais(raiz1->dir, raiz2->dir));
}

int mesmaEstrutura(no *raiz1, no *raiz2){
    if(raiz1==NULL && raiz2==NULL) return 1;
    if(raiz1==NULL || raiz2==NULL) return 0;
    return(mesmaEstrutura(raiz1->esq, raiz2->esq) && mesmaEstrutura(raiz1->dir, raiz2->dir));
}

int valoresIguais(no *raiz1, no *raiz2){
    if(raiz1!=NULL){
        if(busca(raiz1->chave, raiz2)){
            if(raiz1->esq!=NULL) return(valoresIguais(raiz1->esq, raiz2));
            if(raiz1->dir!=NULL) return(valoresIguais(raiz1->dir, raiz2));
            return 1;
        } else return 0;
    } else return 1;
}

int main() {
    no *raiz[qtdArv];
    no *raizAtual=NULL;
    no *raizAux=NULL;
    dado *fila=NULL;
  
    int opcaoMenu, n, qtd, k, atual=0, linha;
    float media;
    char resp;

    string nomeArq;
    ofstream arquivoS;
    ifstream arquivoE;

    keybd_event ( VK_MENU, 0x36, 0, 0 ); 
    keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );

    for(int i=0; i<qtdArv; i++) raiz[i]=NULL;

    do {

        menu();
        cout << "\n\n\t\tOpcao: ";
        cin >> opcaoMenu;
        switch (opcaoMenu) {
            case 1:
                do {
                    cout << "\n\n\tInserir valor.... ";
                    cin >> n;
                    inserir(n, &raizAtual);
                    cout << "\n\tInserir mais elementos?[S/N] : ";
                    cin >> resp;
                    resp=toupper(resp);
                } while (resp!='N');
                break;

            case 2:

                do {
                    cout << "\n\n\tQual valor a ser removido? ";
                    cin >> n;
                    removerArv(&raizAtual, n);
                    cout << "\n\tRemover mais elementos?[S/N] : ";
                    cin >> resp;
                    resp=toupper(resp);
                } while (resp!='N');
                break;

            case 3:

                do {
                    cout << "\n\n\tConsultar qual numero? ";
                    cin >> n;
                    if(busca(n, raizAtual)==1) cout << "\tELEMENTO ENCONTRADO !";
                    else cout << "\tELEMENTO NAO ENCONTRADO !";
                    cout << "\n\tConsultar mais numeros?[S/N] ";
                    cin >> resp;
                    resp=toupper(resp);
                } while(resp!='N');
                break;
            
            case 4:
                cout << "\n\tMAIOR ELEMENTO: " << maiorElem(raizAtual);
                break;

            case 5:
                cout << "\n\tMENOR ELEMENTO: " << menorElem(raizAtual);
                break;

            case 6:
                cout << "\n\tQUANTIDADE DE ELEMENTOS: " << qtdElem(raizAtual);
                break;
            
            case 7:
                cout << "\n\tALTURA DA ARVORE: " << altura(raizAtual) << " niveis";
                break;

            case 8:
                cout << "\n\t" << qtdPar(raizAtual) << " pares e " << qtdImpar(raizAtual) << " impares";
                break;

            case 9:
                cout << "\n\tValor de 'K' :";
                cin >> k; 
                cout << "\n\t" << k << " = { ";
                qtd=multiplos(raizAtual, k);
                cout << "}";
                cout << "\n\t" << qtd << " multiplos de " << k;
                break;

            case 10:
                em(raizAtual);
                break;
            
            case 11:
                decrescente(raizAtual);
                break;

            case 12:
                cout << "\n\tSoma dos valores dos nos: " << soma(raizAtual);
                break;
            
            case 13:
                cout << "\n\tMedia dos valores dos nos: " << (float)soma(raizAtual)/qtdElem(raizAtual);
                break;

            case 14:
                media=(float)soma(raizAtual)/qtdElem(raizAtual);
                qtd = qtdElem(raizAtual);
                cout << "\n\tDesvio padrao: " << sqrt(desvioPadrao(raizAtual, media)/qtd);
                break;
            
            case 15:
                cout << "\n\tQuantidade de NULLs: " << qtdNull(raizAtual);
                break;

            case 16:
                cout << "\n\tQuantidade de nos com dois filhos: " << qtd2Filhos(raizAtual);
                break;

            case 17:
                cout << "\n\tQuantidade de nos com um filho: " << qtd1Filho(raizAtual);
                break;

            case 18:
                cout << "\n\tQuantidade de folhas: " << qtdFolhas(raizAtual);
                break;
            
            case 19:
                em(raizAtual);
                break;

            case 20:
                pre(raizAtual);
                break;

            case 21:
                pos(raizAtual);
                break;
            
            case 22:
                largura(raizAtual, &fila);
                break;

            case 23:
                cout << "\n\tNome do arquivo a ser salvo: ";
                cin >> nomeArq;

                arquivoS.open(nomeArq);
                if(arquivoS.is_open() && arquivoS.good()){
                    salvar(raizAtual, &arquivoS);
                    arquivoS.close();
                    cout << "\n\tARVORE SALVA COM SUCESSO!";
                } else 
                    cout << "\n\tNao foi possivel abrir arquivo ou criar um arquivo com este nome";
                break;

            case 24:
                if(raizAtual!=NULL) raiz[atual]=raizAtual;
                cout << "\n\tNome do arquivo: ";
                cin >> nomeArq;
                arquivoE.open(nomeArq);
                if(arquivoE.is_open() && arquivoE.good()){
                    while(arquivoE >> linha)
                        inserir(linha, &raizAtual);
                } else
                    cout << "\n\tArquivo nao existe!";
                break;

            case 25:
                raiz[atual]=raizAtual;
                //menu da qtd. de arv. inicializadas e quais
                cout << "\n\tQuer trocar por qual arvore? [1," << qtdArv << "]....:Arvore ";
                cin >> atual;
                atual--;
                raizAtual=raiz[atual];
                cout << "\n\tTrocado!";
                break;

            case 26:
                cout << "\n\tComparar com qual arvore? [1," << qtdArv << "]....:Arvore ";
                cin >> n;
                raizAux=raiz[n-1];
                if(iguais(raizAtual, raizAux)) cout << "\n\tSao iguais!";
                else if(mesmaEstrutura(raizAtual, raizAux)) cout << "\n\tPossuem a mesma estrutura com valores diferente";
                else if(qtdElem(raizAtual)==qtdElem(raizAux) && valoresIguais(raizAtual, raizAux)) cout << "\n\tPossuem os mesmos valores com estruturas diferentes";
                else cout << "\n\tSao totalmente diferentes";               
                break;                
            default:
            break;
        }
    } while(opcaoMenu!=0);

}