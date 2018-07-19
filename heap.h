#define MAX 20
/*Como eu tenho que fazer as divis�es por 2 (defini��o do heap), vou come�ar meu vetor pelo �ndice 1*/
typedef struct Heap
{
    int prioridade[MAX];
    int quantidade; //quantidade atual do MAX
}Heap;

Heap * novoHeap()
{
    Heap *novo = (Heap *)malloc(sizeof(Heap));
    novo->quantidade = 0;
    return novo;
}

void insercao(Heap *h, int x)
{
    if(h->quantidade < MAX-1) //usando somente a partir da posi��o 1, por isso descarta 1
    {
        int aux;
        int i = ++h->quantidade; //+1 porque eu n�o vou usar o �ndice zero do vetor (por causa das divis�es por 2)
        //++h->quantidade: primeiro ele incrementa e depois ele atualiza o i.
        h->prioridade[i] = x; //colocando o elemento na primeira posic�o v�lida.

        //troca entre os elementos = "subir"
        while(i > 1 && h->prioridade[i] > h->prioridade[i/2]) //caso o ancestral seja menor que o n�mero atualmente verificado.
        {
            aux = h->prioridade[i];
            h->prioridade[i] = h->prioridade[i/2];
            h->prioridade[i/2] = aux;
            i = i/2;
        }
    }
}

void exclusao(Heap *h)
{
    if(h->quantidade != 0) //quando h� elementos presentes no vetor
    {
        h->prioridade[1] = h->prioridade[h->quantidade]; //coloca o �ltimo elemento no lugar do primeiro.
        h->quantidade--; //desconsidera o elemento que era o primeiro da lista, porque foi "exclu�do"
        //"descer"
        int i = 1;
        int aux;
        int posicaoMaior;
        int continuar = 1; //booleana
        while(continuar) //enquanto o continuar for verdadeiro (ou seja, igual a 1) ele vai continuar fazendo o while
        {
            if(2 * i > h->quantidade) //i n�o tem descendentes(ou seja, i � uma folha)
                continuar = 0; //vira falso
            else if(2 * i + 1 > h->quantidade) //possu� somente o descendente da esquerda (o 2 * i)
            {
                if(h->prioridade[i] < h->prioridade[2*i]) //viola a regra do heap (o descendente do i � maior que ele)
                {
                    //fazendo a troca do i com o seu descendente da esquerda ("descer")
                    aux = h->prioridade[i];
                    h->prioridade[i] = h->prioridade [2*i];
                    h->prioridade[2*i] = aux;
                }
                continuar = 0; //n�o precisa testar de novo, porque ele s� tinha um descendente a esquerda
            }
            else //ele tem os dois descendentes
            {
                //achar onde est� o maior descendente
                if(h->prioridade[2*i] >= h->prioridade[2*i+1]) //descendente da esquerda � maior ou igual ao da direita
                    posicaoMaior = 2*i;
                else
                    posicaoMaior = 2*i+1;
                if(h->prioridade[i] < h->prioridade[posicaoMaior]) //viola regra do Heap
                {
                    aux = h->prioridade[i];
                    h->prioridade[i] = h->prioridade[posicaoMaior];
                    h->prioridade[posicaoMaior] = aux;
                    i = posicaoMaior;
                }
            }
        }
    }
}

void impressao(Heap *h)
{
    int i;
    for(i = 1; i <= h->quantidade; i++)
        printf("%d ", h->prioridade[i]);
    printf("\n");
}
