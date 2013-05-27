#include <iostream>
#include "../lib/DSGraph.h"

using namespace std;

int main()
{
    //DSGRAPH
    init($PONTEIRO);
    setDataType(float);
    //DSGRAPH

	float number = 15.00;
	float* pnumber;

	pnumber = &number;

	std::cout << "Valor da variavel number  : " << number << std::endl
			  << "Endereco da variavel number: " << pnumber << std::endl
			  << "Valor de pnumber variavel : " << pnumber << std::endl
		      << "Valor do ponteiro pnumber  : " << *pnumber << std::endl;

   //DSGRAPH
   setSleepTime(5);
   show(pnumber, 0);
   terminateDSGraph();
   //DSGRAPH

	return 0;
}
