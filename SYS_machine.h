#ifndef SYS_MACHINE_H
#define SYS_MACHINE_H

/*
     Classe SYS_machine responsável pelo funcionamento do projeto
     utilizando a placa, interface de comunicação os botões e a 
     interface com o pc onde o cliente pode escolher os produtos 
     e os valores de entrada como as moedas a se pagar são recebidas
     pelos botões da placa recebendo o troco.
     Arquivo .h onde definimos todos os componentes da classe, como
     variáveis, funções, heranças e classificação de publico e privado.
     startmachine é uma função virtual da classe Machine que será escri-
     ta pela SYS_machine.
*/


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