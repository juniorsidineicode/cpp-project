#ifndef PC_MACHINE_H
#define PC_MACHINE_H

#include <iostream>
#include <stdlib.h>
#include "Machine.h"

using namespace std;

class PC_machine: public Machine{
          int M25, M50, M100;
          int total;
          bool devolucao;
          int refri, sel;
     public:
          PC_machine(void);
          ~PC_machine(void);
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
};
#endif