#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int conteudo;
    struct No *esq;
    struct No *dir;
} Arv;

Arv *iniciarArvore()
{
    return NULL;
}

Arv *criarNo(int conteudo)
{
    Arv *novoNo = (Arv *)malloc(sizeof(Arv));
    if (novoNo == NULL)
    {
        return NULL;
    }
    novoNo->conteudo = conteudo;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

Arv *inserirNo(Arv *arv, int conteudo)
{
    if (arv == NULL)
    {
        return criarNo(conteudo);
    }
    if (conteudo < arv->conteudo)
    {
        arv->esq = inserirNo(arv->esq, conteudo);
    }
    else
    {
        arv->dir = inserirNo(arv->dir, conteudo);
    }
    return arv;
}

void preOrdem(Arv *arv)
{
    if (arv != NULL)
    {
        printf('%d ', arv->conteudo);
        preOrdem(arv->esq);
        preOrdem(arv->dir);
    }
}

void inOrdem(Arv *arv)
{
    if (arv != NULL)
    {
        inOrdem(arv->esq);
        printf('%d ', arv->conteudo);
        inOrdem(arv->dir);
    }
}

void posOrdem(Arv *arv)
{
    if (arv != NULL)
    {
        posOrdem(arv->esq);
        posOrdem(arv->dir);
        printf('%d ', arv->conteudo);
    }
}

int quantidadeNos(Arv *arv)
{
    if (arv == NULL)
    {
        return 0;
    }
    return 1 + quantidadeNos(arv->esq) + quantidadeNos(arv->dir);
}

int quantidadeFolhas(Arv *arv)
{
    if (arv == NULL)
    {
        return 0;
    }
    if (arv->esq == NULL && arv->dir == NULL)
    {
        return 1;
    }
    return quantidadeFolhas(arv->esq) + quantidadeFolhas(arv->dir);
}

int tamanhoArvore(Arv *arv)
{
    if (arv == NULL)
    {
        return -1;
    }

    alturaEsquerda = tamanhoArvore(arv->esq);
    alturaDireita = tamanhoArvore(arv->dir);

    if (alturaEsquerda > alturaDireita)
    {
        return 1 + alturaEsquerda;
    }
    else
    {
        return 1 + alturaDireita;
    }
}

Arv *maiorNo(Arv *arv)
{
    if (arv == NULL)
    {
        return NULL;
    }
    Arv *corredor = arv;
    while (corredor != NULL && corredor->dir != NULL)
    {
        corredor = corredor->dir;
    }
    return corredor;
}

Arv *menorNo(Arv *arv)
{
    if (arv == NULL)
    {
        return NULL;
    }
    Arv *corredor = arv;
    while (corredor != NULL && corredor->esq != NULL)
    {
        corredor = corredor->esq;
    }
    return corredor;
}

Arv *buscarNo(Arv *arv, int valorBuscado)
{
    if (arv == NULL)
    {
        return NULL;
    }
    if (arv->conteudo == valorBuscado)
    {
        return arv;
    }
    if (valorBuscado < arv->conteudo)
    {
        arv->esq = buscarNo(arv->esq, valorBuscado);
    }
    else
    {
        arv->dir = buscarNo(arv->dir, valorBuscado);
    }
}

Arv *removerNo(Arv *arv, int valorBuscado)
{
    if (arv == NULL)
    {
        return NULL;
    }
    if (valorBuscado < arv->conteudo)
    {
        arv->esq = removerNo(arv->esq, valorBuscado);
    }
    else if (valorBuscado >= arv->conteudo)
    {
        arv->dir = removerNo(arv->dir, valorBuscado);
    }
    else
    {
        if (arv->esq == NULL && arv->dir == NULL)
        {
            free(arv);
            return NULL;
        }
        if (arv->esq == NULL || arv->dir == NULL)
        {
            Arv *temp;
            if (arv->esq == NULL)
            {
                temp = arv->dir;
            }
            else
            {
                temp = arv->esq;
            }
            free(arv);
            return temp;
        }
        else
        {
            Arv *temp = arv->dir;
            while (temp->esq != NULL)
            {
                temp = temp->esq;
            }
            arv->conteudo = temp->conteudo;
            arv->dir = removerNo(arv->dir, temp->conteudo);
        }
    }
    return arv;
}