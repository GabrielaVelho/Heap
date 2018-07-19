#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    Heap *h = novoHeap();
    insercao(h, 4);
    insercao(h, 2);
    insercao(h, 6);
    insercao(h, 1);
    insercao(h, 5);
    insercao(h, 8);
    insercao(h, 10);
    insercao(h, 5);
    insercao(h, 3);
    impressao(h);
    exclusao(h);
    exclusao(h);
    exclusao(h);
    impressao(h);
    return 0;
}
