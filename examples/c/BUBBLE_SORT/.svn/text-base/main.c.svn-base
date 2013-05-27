#include <stdio.h>
#include <stdlib.h>
#include "../lib/DSGraph.h"

#define MAX 10
float vetor[MAX];

void bubblesort()
{
    int j= 0 ;
    int i=0;
    int k = MAX - 1 ;
    for(i = 0; i<MAX; i++)
    {
        for(j= 0 ; j<k; j++)
        {
            if(vetor[j+1] < vetor[j])
            {

               float aux = vetor[j];
               show(&vetor,2,&vetor[j],&vetor[j+1]);
               vetor[j] = vetor[j+1];
               vetor[j+1]= aux;
               show(&vetor,2,&vetor[j+1],&vetor[j]);

            }
        }

        k--;
    }
}

int main()
{

    //Inicializa a biblioteca gráfica com a estrutura a ser apresentada na tela
    init($VETOR,MAX,1);

    setDataType(float);

    int i = 0;

    setSleepTime(1);

    for(i = 0; i < MAX; i++)
    {
        vetor[i] = rand()%100;
    }

    setSleepTime(2);
    show(&vetor,0);



    setSleepTime(1);
    bubblesort();
    setSleepTime(10);
    show(&vetor,0);

    terminateDSGraph();

    return 0;
}
