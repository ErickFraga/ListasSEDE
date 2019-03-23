#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAX 100

/** pListaNoSE = É a estrutura do Nó da RODOVIA!!! que é um ponteiro **/
/** SE = significa que é simplemente encadeada as RODOVIAS são simplesmente encadeadas**/
/** DE = dignifica que é duplamente encadeada as CIDADES são duplamente encadeadas**/
/** ListaSE = É a estrutura da Lista da RODOVIA ou a estrutura de controle da RODOVIA **/
/** lst = abreviatura para lista que varia para rodovia e cidade dependento do complemento "SE" ou "DE" **/

/* ========= INFO DA RODOVIA ======= */


typedef struct TListaNoDE{
    char info[MAX];
    struct TListaNoDE *prox;
    struct TListaNoDE *ante;
}*pListaNoDE;

typedef struct TListaDE{
   pListaNoDE iterador, primeiro, ultimo;
   int longitude;
}*ListaDE;

typedef struct TinfoRodovia{
    char rodovia[MAX];
    ListaDE CidadesED;
}*InfoRodovia;

typedef struct ListaNoSE
{
    InfoRodovia info;
    struct ListaNoSE * prox;
}*pListaNoSE;


typedef struct TListaSE
{
    pListaNoSE iterador, ultimo, primeiro;
    int longitude;

}*ListaSE;

ListaSE inicListaSE () // INICIA UMA LISTA DO TIPO RODOVIA
{
    ListaSE lstSE = (ListaSE) malloc(sizeof(struct TListaSE)); // alocando a struct lista para rodovia
    /*Setando as variaveis da lista de rodovia*/
    lstSE->iterador = NULL;
    lstSE->ultimo = NULL;
    lstSE->primeiro = NULL;
    lstSE->longitude = 0;

    return lstSE;
}

void anxListaSE(ListaSE lstSE, InfoRodovia nomeRodovia) // Cria um Nó para rodovia e colocar esse Nó na rodovia e retornar a rodovia já com o nó
{
    // tratamento de erro
    if(lstSE->iterador == NULL && lstSE->longitude > 0)
        printf("\nErro: iterador com valor nulo sendo que lista esta cheia!\n");
    else
    {
        /*Criando um novo Nó para a rodovia*/
        pListaNoSE novoNoSE = (pListaNoSE) malloc(sizeof(struct ListaNoSE));
        novoNoSE->info = nomeRodovia;
        novoNoSE->prox = NULL; // atribuir NULL para deixar o novoNo preparado
        if(lstSE->longitude == 0) // Lista vazia, ou seja o novo Nó vai ser o primeiro
        {
            lstSE->primeiro = novoNoSE;
            lstSE->ultimo = novoNoSE;
            lstSE->iterador = novoNoSE;
            lstSE->longitude ++;
        }
        else if(lstSE->longitude > 0){
            novoNoSE->prox = lstSE->iterador->prox;
            lstSE->iterador->prox = novoNoSE;
            lstSE->iterador = novoNoSE;
            lstSE->longitude ++;

            if(lstSE->iterador->prox == NULL) {
                lstSE->ultimo = novoNoSE;
            }
        }
    }

}

void insListaSE(ListaSE lstSE, InfoRodovia nomeRodovia)
{
    if(lstSE->iterador == NULL && lstSE->longitude > 0)
        printf("\nErro: iterador com valor nulo sendo que lista esta cheia!\n");
    else
    {
        pListaNoSE novoNoSE = (pListaNoSE) malloc(sizeof(struct ListaNoSE));
        novoNoSE->info = nomeRodovia;
        novoNoSE->prox = NULL; // atribuir NULL para deixar o novoNo preparado
        if(lstSE->longitude == 0) // Lista vazia, ou seja o novo Nó vai ser o primeiro
        {
            lstSE->primeiro = novoNoSE;
            lstSE->ultimo = novoNoSE;
            lstSE->iterador = novoNoSE;
            lstSE->longitude ++;
        }
        else if( lstSE->primeiro == lstSE->iterador)
        {
            novoNoSE->prox = lstSE->primeiro;
            lstSE->primeiro = novoNoSE;

            lstSE->iterador = novoNoSE;
            lstSE->longitude++;
        }
        else if(lstSE->longitude > 0){
            pListaNoSE p = (pListaNoSE) malloc(sizeof(struct ListaNoSE));

            for(p = lstSE->primeiro; p->prox != lstSE->iterador; p = p->prox){}
            novoNoSE->prox = lstSE->iterador;
            p->prox = novoNoSE;
            lstSE->iterador = novoNoSE;
            lstSE->longitude ++;

            free(p);
        }
    }
}

void elimListaSE(ListaSE lstSE)
{
 if(lstSE->iterador != NULL)
    {
        pListaNoSE noAserDesalocado;
        if (lstSE->iterador == lstSE->primeiro)  // se o iterador estiver sobre o primeiro elemento
        {
            if (lstSE->longitude == 1){

                noAserDesalocado = lstSE->iterador;
                lstSE->iterador = NULL;
                lstSE->primeiro = NULL;
                lstSE->ultimo = NULL;
                lstSE->longitude--;
                free(noAserDesalocado);
            }
            else{
                noAserDesalocado = lstSE->iterador;
                lstSE->iterador = lstSE->iterador->prox;
                lstSE->primeiro = lstSE->iterador;
                lstSE->longitude--;
                free(noAserDesalocado);
            }
        }
        else  // iterador esta sobre qualquer outro no que nao o primeiro no
        {
            //iterador sobre no intermediario ou o ultimo no
            pListaNoSE p;
            for(p = lstSE->primeiro; p->prox != lstSE->iterador; p = p->prox)
            {
            }
            noAserDesalocado = lstSE->iterador;
            p->prox = lstSE->iterador->prox;

            if( lstSE->iterador == lstSE->ultimo) // se o iterador estiver sobre o utlimo no
                lstSE->ultimo = p;

            lstSE->iterador = lstSE->iterador->prox;
            free(noAserDesalocado);
            lstSE->longitude--;
        }
    }
    else
    {
        printf("\n erro: iterador indefinido \n");
    }
}

void primListaSE(ListaSE lstSE)
{
    lstSE->iterador = lstSE->primeiro;
}


void ultiListaSE(ListaSE lstSE)
{
    lstSE->iterador = lstSE->ultimo;
}

void segListaSE(ListaSE lstSE)
{
    lstSE->iterador = lstSE->iterador->prox;
}

void posListaSE(ListaSE lstSE, int pos)
{
    if(pos > lstSE->longitude || pos <= 0 || lstSE->longitude < 0){
        printf("\n- Posicao fora da lista");
    }
    else{
            int i;
        for(i = 1, lstSE->iterador = lstSE->primeiro; i < pos; i++, lstSE->iterador = lstSE->iterador->prox){}

    }
}

InfoRodovia infoListaSE(ListaSE lstSE)
{
    if(lstSE->iterador == NULL)
    {
        printf("\n erro: iterador indefinido \n");
        return NULL;
    }
    else
        return lstSE->iterador->info;
}

 int LongListaSE(ListaSE lstSE)
 {
     return lstSE->longitude;
 }

int fimListaSE(ListaSE lstSE)
{

    return (lstSE->iterador == NULL);

}

int main()
{
    printf("Hyello Word !!!");
    ListaSE lst = inicListaSE();

/*
    printf("%i", lst->iterador->info );
    insListaSE(lst, 24);
    printf("\n%i", lst->iterador->info );
    */
    printf("\n%i", lst->iterador->info);
    return 0;
}
