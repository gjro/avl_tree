#include <stdio.h>
#include <stdlib.h>

struct no
{
    int chave;
    struct no *esq, *dir;
};

typedef struct no No;

void preordem(No *pt)
{
    printf("%d ", pt->chave);

    if (pt->esq != NULL)
    {
        preordem(pt->esq);
    }
    if (pt->dir != NULL)
    {
        preordem(pt->dir);
    }
}

void buscar(int x, No ***pt, int *f)
{
    if ((*(*pt)) == NULL)
    {
        *f = 0;
    }
    else
    {
        if (x == (*(*pt))->chave)
        {
            *f = 1;
        }
        else
        {
            if (x < (*(*pt))->chave)
            {
                if ((*(*pt))->esq == NULL)
                {
                    *f = 2;
                }
                else
                {
                    *pt = &(*(*pt))->esq;
                    buscar(x, pt, f);
                }
            }
            else
            {
                if ((*(*pt))->dir == NULL)
                {
                    *f = 3;
                }
                else
                {
                    *pt = &(*(*pt))->dir;
                    buscar(x, pt, f);
                }
            }
        }
    }
}

void inserir(int x, No **ptraiz)
{
    int f;
    No **pt = ptraiz;

    buscar(x, &pt, &f);

    if (f == 1)
    {
        printf("\n [Error - Elemento encontrado] \n");
    }
    else
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->chave = x;
        novo->dir = novo->esq = NULL;

        if (f == 0)
        {

            *ptraiz = novo;
        }
        if (f == 2)
        {
            *pt->esq = novo;
        }
        if (f == 3)
        {
            **pt->dir = novo;
        }
    }
}

void remover(int x, No **ptraiz)
{
    int f;
    No **pt = ptraiz;
    buscar(x, &pt, &f);

    if (f != 1)
    {
        printf("\n [Error - Elemento não encontrado] \n");
    }
    else
    {
        No *aux = *pt;
        if (*pt->esq == NULL)
        {
            *pt = *pt->dir;
        }
        else
        {
            if (*pt->dir = NULL)
            {
                *pt = *pt->esq;
            }
            else
            {
                No *s = *pt->dir;
                if (s->esq != NULL)
                {
                    No *paiS = s;
                    while (s->esq != NULL)
                    {
                        paiS = s;
                        s = s->esq;
                    }
                    paiS->esq = s->dir;
                    s->dir = *pt->dir;
                }
                s->esq = *pt->esq;
                *pt = s;
            }
        }
        free(aux);
    }
}

int main()
{
    No *ptraiz = NULL, A, B, C;
    No **pt = &ptraiz;
    int f;

    if (ptraiz != NULL)
    {
        preordem(ptraiz);
    }
    else
    {
        printf("\n [Error - Árvore vazia] \n");
    }

    buscar(50, &pt, &f);
    printf("F = %d", f);

    buscar(24, &pt, &f);
    printf("F = %d", f);

    buscar(26, &pt, &f);
    printf("F = %d", f);

    A.chave = 50;
    B.chave = 25;
    C.chave = 75;

    ptraiz = &A;
    A.esq = &B;
    A.dir = &C;

    B.dir = B.esq = C.dir = C.esq = NULL;

    if (ptraiz != NULL)
    {
        preordem(ptraiz);
    }
    else
    {
        printf("\n [Error - Árvore vazia] \n");
    }

    return 0;
}
