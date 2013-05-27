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
#define MAX 20
int main()
{
    init($VETOR_MULTIDIMENSIONAL, MAX, MAX);

    int matriz[MAX][MAX];

    setDataType(int);

    int i=0;
    int j=0;
    int v=0;

    setSleepTime(5);

    for(i=0;i<MAX;i++){
        for (j=0;j<MAX;j++){
          matriz[i][j] = 0;
        }
    }

    for(i=0;i<MAX;i++){
        for (j=0;j<MAX;j++){
          matriz[i][j]= v++;
        }
    }

    show(&matriz, 3, &matriz[0][0],  &matriz[1][1], &matriz[2][2]);

    terminateDSGraph();

    return 0;
}

//EOF
