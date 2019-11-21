#ifndef SYS_MACHINE_H
#define SYS_MACHINE_H

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <math.h>
#include <iomanip>

using namespace std;

class SYS_machine: public Machine{
	int M25, M50, M100;
	int total;
	bool devolucao;
	int refri, sel;

   public:
	SYS_machine(void);
	~SYS_machine(void);
    bool trocoM25();
    bool trocoM50();
    bool trocoM100();
    bool devolve();
    bool teste(float total);
    bool setRefri(int tipo_refri);
    float acumulado();
    int troco(int total);
    void startmachine();
    void incluiM25();
    void incluiM50();
    void incluiM100();
    void reset();
    int delay(int lim);
    
};
#endif