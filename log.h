#ifndef LOG_H
#define LOG_H

/*
    Classe log para montar o relatório de vendas chamado de log
    utilizado numa FIFO para geração do log do sistema de vendas
    implementamos um log para mostrar o refrigerante vendido
    seu preço e horario de venda.
    Arquivo .h com definições de variáveis que usaremos assim como
    funções e suas classificações como públicas e privadas.
*/

#include "Node.h"
#include <iostream>

using namespace std;

class Log{
	Node* head;

  public:
  	Log();
  	~Log();
  	void  insertBeforeFirst(int refri, float valor);
  	void  insertAfterLast(int refri, float valor);
  	int   readFirstVal();
  	int  readFirstRefri();
  	void  removeFirst();


    int totalCompras();

};
#endif