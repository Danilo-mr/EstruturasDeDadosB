#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

#define qtdArv 10000

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct dado{
    int cod;
    struct dado *prox;
};

void menu(no *raiz[], int atual){
    int nulas=0, i;
    for(i=0; i<qtdArv; i++){
        if(raiz[i]==NULL) nulas++;
        else cout << "Arvore " << i+1;
    }
    
    cout << "\n\n\n";
    cout << "\n\t\t      ####               ####      ############     ####         ###     ###       ###";
    cout << "\n\t\t      #####             #####      ############     #####        ###     ###       ###";
    cout << "\n\t\t      ######           ######      ############     ######       ###     ###       ###            #####";
    cout << "\n\t\t      ### ###         ### ###      ###              ### ###      ###     ###       ###          ##       ########            ";
    cout << "\n\t\t      ###  ###       ###  ###      ###              ###  ###     ###     ###       ###           ##         ##      ###      ";
    cout << "\n\t\t      ###   ###    ###    ###      ############     ###   ###    ###     ###       ###            ###       ##    ##   ##  ###### ";
    cout << "\n\t\t      ###    ###  ###     ###      ############     ###    ###   ###     ###       ###              ###     ##    ##   ##    ##    ##  ##  ";  
    cout << "\n\t\t      ###     ######      ###      ############     ###     ###  ###     ###       ###               ###    ##    #######    ##    ##  ##  ####";
    cout << "\n\t\t      ###      ####       ###      ###              ###      ### ###     ###       ###               ###    ##    ##   ##    ##    ##  ##  ##";
    cout << "\n\t\t      ###                 ###      ###              ###       ######     ###       ###            ####      ##    ##   ##    ##    ##  ##   ###";
    cout << "\n\t\t      ###                 ###      ############     ###        #####     ###       ###         #####        ##    ##   ##    ##     ####  ####";
    cout << "\n\t\t      ###                 ###      ############     ###         ####      ###     ###";
    cout << "\n\t\t      ###                 ###      ############     ###          ###       #########";
    cout << endl;
    cout << left << setw(40) << "\n\t\t\t (1) Inserir" << "(14) Desvio padrao dos valores dos nos" << "       ";
    cout << left << setw(40) << "\n\t\t\t (2) Remover" << "(15) Quantidade de NULLs presente na arvore";
    cout << left << setw(40) << "\n\t\t\t (3) Buscar" << "(16) Quantidade de nos com dois filhos" << right << setw(47) <<"#Arvores Disponiveis: " << qtdArv; 
    cout << left << setw(40) << "\n\t\t\t (4) Maior elemento" << "(17) Quantidade de nos com um filho"; 
    cout << left << setw(40) << "\n\t\t\t (5) Menor elemento" << "(18) Quantidade de folhas" << right << setw(61) << "()Nulas         : " << nulas; 
    cout << left << setw(40) << "\n\t\t\t (6) Quantidade de elementos(nos)" << "(19) Percorrer a arvore em ordem" << right << setw(54) << "()Inicializadas : " << qtdArv-nulas; 
    cout << left << setw(40) << "\n\t\t\t (7) Altura da arvore(niveis)" << "(20) Percorrer a arvore em preordem" << "                                          "; 
    cout << left << setw(40) << "\n\t\t\t (8) Quantidade de pares e impares" << "(21) Percorrer a arvore em posordem" << right << setw(43) << "    #Arvore atual: " << atual+1;
    cout << left << setw(40) << "\n\t\t\t (9) Multiplos de 'k' e quantidade" << "(22) Percorrer a arvore em largura"; 
    cout << left << setw(40) << "\n\t\t\t(10) Ordem crescente" << "(23) Salvar a arvore em arquivo"; 
    cout << left << setw(40) << "\n\t\t\t(11) Ordem decrescente" << "(24) Recuperar a arvore de arquivo"; 
    cout << left << setw(40) << "\n\t\t\t(12) Soma dos valores dos nos" << "(25) Trocar de arvore"; 
    cout << left << setw(40) << "\n\t\t\t(13) Media dos valores dos nos" << "(26) Comparar duas arvores";
    cout << "\n\n\t\t\t\t\t\t(0) Sair";
}

int inserir(int n, no **raiz){
    if((*raiz)==NULL)
    {
        *raiz = (no*) malloc(sizeof(no));
        if((*raiz)==NULL) return -1;
        (*raiz)->chave=n;
        (*raiz)->esq = (*raiz)->dir =NULL;
        return 1; 
    } else {
        if(n < (*raiz)->chave) 
            inserir(n, &(*raiz)->esq);
        else {
            if(n > (*raiz)->chave)
                inserir(n, &(*raiz)->dir);
            else
                return 0;
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
            cout << "\n\tRemovido com SUCESSO!";
            return;  
        }
        else if (n<(*raiz)->chave) removerArv(&(*raiz)->esq, n);
        else if (n>(*raiz)->chave) removerArv(&(*raiz)->dir, n);
    } else 
        cout << "\n\tElemento nao existe";
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

no* encontrar(int x, no **raiz){
    if((*raiz)==NULL) return NULL;
    else if((*raiz)->chave==x) return (*raiz);
    else if(x<(*raiz)->chave) return(encontrar(x, &(*raiz)->esq));
    else return(encontrar(x, &(*raiz)->dir));
}

void inserirFila(dado **fila, no *raiz){
    dado *aux, *aux2;
    no *raizAux=raiz;
    raiz=encontrar((*fila)->cod, &raizAux);
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

void uniao(no *r1, no *r2, no **r3){
    if(r1!=NULL){
        inserir(r1->chave, r3);
        if(r1->esq!=NULL) uniao(r1->esq, r2, r3);
        if(r2->dir!=NULL) uniao(r1->dir, r2, r3);
        r1=NULL;
    }
    if(r2!=NULL){
        inserir(r2->chave, r3);
        if(r2->esq!=NULL) uniao(r1, r2->esq, r3);
        if(r2->dir!=NULL) uniao(r1, r2->dir, r3);
    }
}

void interseccao (no *r1, no *r2, no **r3){
    if(r1!=NULL){
        if(busca(r1->chave, r2)==1) inserir(r1->chave, r3);
        if(r1->esq!=NULL) interseccao(r1->esq, r2, r3);
        if(r1->dir!=NULL) interseccao(r1->dir, r2, r3);
    }
}


int main() {
    no *raiz[qtdArv];
    no *raizAux=NULL;
    no *raizAux2=NULL;
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
        cout << "\n\n\t\t\t\t\t\t\t[PRESS ENTER]";
        cin.ignore();
        cin.get();
        system("cls");
        menu(raiz, atual);
        cout << "\n\n\t\tOpcao: ";
        cin >> opcaoMenu;
        switch (opcaoMenu) {
            case 1:
                do {
                    cout << "\n\n\tInserir valor.... ";
                    cin >> n;
                    n=inserir(n, &raiz[atual]);
                    if(n==1) cout << "\n\tElemento inserido com SUCESSO!";
                    else if(n==0) cout << "\n\tElemento ja existe!";
                    else cout << "\n\t\tHeap Overflow";
                    cout << "\n\tInserir mais elementos?[S/N] : ";
                    cin >> resp;
                    resp=toupper(resp);
                } while (resp!='N');
                break;

            case 2:

                do {
                    cout << "\n\n\tQual valor a ser removido? ";
                    cin >> n;
                    removerArv(&raiz[atual], n);
                    cout << "\n\tRemover mais elementos?[S/N] : ";
                    cin >> resp;
                    resp=toupper(resp);
                } while (resp!='N');
                break;

            case 3:

                do {
                    cout << "\n\n\tConsultar qual numero? ";
                    cin >> n;
                    if(busca(n, raiz[atual])==1) cout << "\tELEMENTO ENCONTRADO !";
                    else cout << "\tELEMENTO NAO ENCONTRADO !";
                    cout << "\n\tConsultar mais numeros?[S/N] ";
                    cin >> resp;
                    resp=toupper(resp);
                } while(resp!='N');
                break;
            
            case 4:
                
                cout << "\n\tMAIOR ELEMENTO: " << maiorElem(raiz[atual]);
                break;

            case 5:
                cout << "\n\tMENOR ELEMENTO: " << menorElem(raiz[atual]);
                break;

            case 6:
                cout << "\n\tQUANTIDADE DE ELEMENTOS: " << qtdElem(raiz[atual]);
                break;
            
            case 7:
                cout << "\n\tALTURA DA ARVORE: " << altura(raiz[atual]) << " niveis";
                break;

            case 8:
                cout << "\n\t" << qtdPar(raiz[atual]) << " pares e " << qtdImpar(raiz[atual]) << " impares";
                break;

            case 9:
                do{
                    cout << "\n\tValor de 'K' :";
                    cin >> k; 
                    cout << "\n\t" << k << " = { ";
                    qtd=multiplos(raiz[atual], k);
                    cout << "}";
                    cout << "\n\t" << qtd << " multiplos de " << k;
                    cout << "\n\n\tInserir outro valor de 'k'?[S/N] ";
                    cin >> resp;
                    resp=toupper(resp);
                } while(resp!='N');
                break;

            case 10:
                cout << "\n\t";
                em(raiz[atual]);
                break;
            
            case 11:
                cout << "\n\t";
                decrescente(raiz[atual]);
                break;

            case 12:
                cout << "\n\tSoma dos valores dos nos: " << soma(raiz[atual]);
                break;
            
            case 13:
                cout << "\n\tMedia dos valores dos nos: " << (float)soma(raiz[atual])/qtdElem(raiz[atual]);
                break;

            case 14:
                media=(float)soma(raiz[atual])/qtdElem(raiz[atual]);
                qtd = qtdElem(raiz[atual]);
                cout << "\n\tDesvio padrao: " << sqrt(desvioPadrao(raiz[atual], media)/qtd);
                break;
            
            case 15:
                cout << "\n\tQuantidade de NULLs: " << qtdNull(raiz[atual]);
                break;

            case 16:
                cout << "\n\tQuantidade de nos com dois filhos: " << qtd2Filhos(raiz[atual]);
                break;

            case 17:
                cout << "\n\tQuantidade de nos com um filho: " << qtd1Filho(raiz[atual]);
                break;

            case 18:
                cout << "\n\tQuantidade de folhas: " << qtdFolhas(raiz[atual]);
                break;
            
            case 19:
                cout << "\n\t";
                if(raiz[atual]==NULL) cout << "\n\tArvore vazia";
                else em(raiz[atual]);
                break;

            case 20:
                cout << "\n\t";
                if(raiz[atual]==NULL) cout << "\n\tArvore vazia";
                else pre(raiz[atual]);
                break;

            case 21:
                cout << "\n\t";
                if(raiz[atual]==NULL) cout << "\n\tArvore vazia";
                else pos(raiz[atual]);
                break;
            
            case 22:
                cout << "\n\t";
                fila=NULL;
                largura(raiz[atual], &fila);
                break;

            case 23:
                cout << "\n\tNome do arquivo a ser salvo: ";
                cin >> nomeArq;

                arquivoS.open(nomeArq);
                if(arquivoS.is_open() && arquivoS.good()){
                    salvar(raiz[atual], &arquivoS);
                    arquivoS.close();
                    cout << "\n\tARVORE SALVA COM SUCESSO!";
                } else 
                    cout << "\n\tNao foi possivel abrir arquivo ou criar um arquivo com este nome";
                break;

            case 24:
                cout << "\n\tNome do arquivo: ";
                cin >> nomeArq;
                arquivoE.open(nomeArq);
                raiz[atual]=NULL;
                if(arquivoE.is_open() && arquivoE.good()){
                    while(arquivoE >> linha)
                        inserir(linha, &raiz[atual]);
                } else
                    cout << "\n\tArquivo nao existe!";
                arquivoE.close();
                break;

            case 25:
                cout << "\n\tQuer trocar por qual arvore? [1," << qtdArv << "]....:Arvore ";
                cin >> atual;
                atual--;
                cout << "\n\tTrocado!";
                break;

            case 26:
                cout << "\n\tComparar com qual arvore? [1," << qtdArv << "]....:Arvore ";
                cin >> n;
                raizAux=raiz[n-1];
                if(iguais(raiz[atual], raizAux)) cout << "\n\tSao iguais!";
                else if(mesmaEstrutura(raiz[atual], raizAux)) cout << "\n\tPossuem a mesma estrutura com valores diferente";
                else if(qtdElem(raiz[atual])==qtdElem(raizAux) && valoresIguais(raiz[atual], raizAux)) cout << "\n\tPossuem os mesmos valores com estruturas diferentes";
                else cout << "\n\tSao totalmente diferentes";               
                break;

            case 27:
                cout << "\n\tUniao da arvore ";
                cin >> n;
                raizAux=raiz[n-1];
                cout << "\n\tcom arvore ";
                cin >> n;
                raizAux2=raiz[n-1];
                uniao(raizAux, raizAux2, &raiz[atual]);
                break;

            case 28:
                cout << "\n\tInterseccao da arvore ";
                cin >> n;
                raizAux=raiz[n-1];
                cout << "\n\tcom a arvore ";
                cin >> n;
                raizAux2=raiz[n-1];
                interseccao(raizAux, raizAux2, &raiz[atual]);
                break;
            
            default:
            break;
        }
    } while(opcaoMenu!=0);

}