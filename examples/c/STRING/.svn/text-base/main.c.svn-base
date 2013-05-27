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
|Este é um programa de exemplo de implementação de Cadeis de caracteres em C ANSI      |
|usando a biblioteca gráfica criada para a apresentação da estrutura na tela.          |
|A biblioteca foi criada como static library. Sendo assim você deverá utilizar os dois |
|cabeçalhos constantes na mesma, bem como incluir o snippet de código marcado abaixo   |
|Para o processo de compilação, você deverá referenciar a mesma DSGraph_LIB.a.         |
| No Codeblocks:                                                                       |
| Properties(do seu projeto)->Project's build option->Linker Settings->Link libraries  |
|                                                                                      |
| * ATENÇÃO *                                                                          |
| Para o correto funcionamento, será ainda necessário que você tenha a Allegro 4.0 con-|
|figurada no seu sistema operacional                                                   |
|                                                                                      |
|--------------------------------------------------------------------------------------+
*/
//BOF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/DSGraph.h"

#define TAM 50
int main()
{
    //Inicializa a biblioteca gráfica com a estrutura a ser apresentada na tela
    init($STRING, TAM);

    setDataType(char);

    char string[TAM];

    strcpy(string,"Funciona! Será mesmo?!");

    setSleepTime(5);

    show(&string, 2, &string[0], &string[4]);

    terminateDSGraph();

    return 0;
}
