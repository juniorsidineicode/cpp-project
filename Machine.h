#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <stdlib.h>

using namespace std;
 
class Machine{
	private:
		int soma;		
		int Prod;
		int valor_Prod;	
	
	public:   	
		Machine(void);
		~Machine(void);
		virtual void startmachine() = 0;

};
#endif