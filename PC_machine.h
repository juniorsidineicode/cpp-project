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
          PC_machine();
          ~PC_machine();
          bool trocoM25();
          bool trocoM50();
          bool trocoM100();
          bool devolve();
          bool teste(float total);
          float acumulado();
          int troco(int total);
          void incluiM25();
          void incluiM50();
          void incluiM100();
          void reset();
          
          bool setRefri(int tipo_refri);
          void startmachine() override;

};
#endif