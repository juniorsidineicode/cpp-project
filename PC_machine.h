#ifndef PC_MACHINE_H
#define PC_MACHINE_H

/*
     Classe PC_machine responsável pelo funcionamento do projeto
     utilizando o computador, interface de comunicação o terminal
     onde o cliente pode escolher os produtos e os valores de entrada
     recebendo o troco.
     Arquivo .h onde definimos todos os componentes da classe, como
     variáveis, funções, heranças e classificação de publico e privado.
     startmachine é uma função virtual da classe Machine que será escri-
     ta pela PC_machine.
*/

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