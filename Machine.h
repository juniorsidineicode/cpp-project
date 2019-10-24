#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Machine{
          int M25, M50, M100;
          int total;
          bool devolucao;
          int refri, sel;
     public:
          Machine();
          ~Machine();
          void incluiM25();
          void incluiM50();
          void incluiM100();
          int troco(int total);
          bool trocoM25();
          bool trocoM50();
          bool trocoM100();
          bool devolve();
          float acumulado();
          bool teste(float total);
          bool setRefri(int tipo_refri);
          void reset();
};
#endif