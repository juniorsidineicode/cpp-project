#ifndef NODE_H
#define NODE_H

/*
    Classe node para montar o relatório de vendas chamado de log
    utilizado numa FIFO para extração do log do sistema de vendas
    implementamos um node para setar o refrigerante vendido
    seu preço e horario de venda.
    Arquivo .h com definições de variáveis que usaremos assim como
    funções e suas classificações como públicas e privadas.
*/


#include <iostream>

using namespace std;

class Node {

    float valor_refri;
    int refrigerante;
    Node* next;

  public:
         
    Node(int refri, float valor, Node* nxt);
    ~Node();
    Node* getNext();
    void setNext(Node* nxt);
    int getRefri();
    float getValrefri();

};
#endif