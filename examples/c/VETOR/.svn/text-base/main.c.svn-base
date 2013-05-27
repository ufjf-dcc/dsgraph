/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Departament - DCC                                                    |
|Project: Visual library to support Data Structures classes                            |
|Professor:Jairo Francisco de Souza    jairo.souza@ufjf.edu.br                         |
|Students......:Thiago Moratori Peixoto     thiagomoratori@gmail.com	               |
|               Sandro Athaide Coelho       sandroacoelho@gmail.com                    |
|Created in......:Abril/23/2011                                                        |
|Objective:                                                                            |
|Este é um programa de exemplo de implementação de Pilhas em C ANSI usando a biblioteca|
|gráfica criada para a apresentação da estrutura na tela.                              |
|A biblioteca foi criada como static library. Sendo assim você deverá utilizar os dois |
|cabeçalhos constantes na mesma, bem como incluir o snippet de código marcado abaixo   |
|Para o processo de compilação, você deverá referenciar a mesma DSGraph_LIB.a.         |
| No Codeblocks:                                                                       |
| Properties(do seu projeto)->Project's build option->Linker Settings->Link libraries  |
|                                                                                      |
| * ATENÇÃO *                                                                          |
| Para o correto funcionamento, será ainda necessário que você tenha a Allegro 5.0 con-|
|figurada no seu sistema operacional                                                   |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF
#include <stdio.h>
#include <stdlib.h>
#include "../lib/DSGraph.h"

#define MAX 30
int main()
{

    //Inicializa a biblioteca gráfica com a estrutura a ser apresentada na tela

    init($VETOR,MAX);

    setDataType(int);

    int vetor[MAX];



    int i = 0;

    setSleepTime(1);


    for(i = 0; i < MAX; i++)
    {
        vetor[i] = 0;
    }

    showComment("Testando...");

    for(i = 0; i < MAX; i++)
    {
        vetor[i] = rand()% MAX;
        showComment("Processando o vetor[i] = %d" , i);
        show(&vetor,0);


    }


    /*for(i = 0; i < MAX; i++)
    {
        printf("Informe o valor do vetor na posição %d:", i);
        scanf("%d", &vetor[i]);
        show(&vetor, 3, &vetor[i], &vetor[i+1], &vetor[i+2]);
    }*/

    setSleepTime(5);
    show(&vetor,0);

    terminateDSGraph();

    return 0;
}


