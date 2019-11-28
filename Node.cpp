/*
    Classe node para montar o relatório de vendas chamado de log
    utilizado numa FIFO para extração do log do sistema de vendas
    implementamos um node para setar o refrigerante vendido
    seu preço e horario de venda.
    Arquivo .cpp com implementação das funções que usaremos.
*/

#include "Node.h"

//refrigerante = 1 MEET
//refrigerante = 2 ETIRPS

Node::Node(int s, float p, Node* nxt){
  refrigerante = s;
  valor_refri = p;
  next = nxt;

  ClockCount::takeinstance()->Calendar->readClock(var_compraHora, var_compraMin, var_compraSeg, var_periodo);
  ClockCount::takeinstance()->Calendar->readCalendar(var_compraAno, var_compraMes, var_compraDia);
}

Node::~Node(){

}

float Node::getValrefri(){
     return valor_refri;
}

int Node::getRefri(){
     return refrigerante;
}

Node* Node::getNext(){
     return next;
}

void Node::setNext(Node* nxt){
       next = nxt;
}

unsigned int Node::compraAno(){
    return var_compraAno;
}

unsigned int Node::compraMes(){
    return var_compraMes;
}

unsigned int Node::compraDia(){
    return var_compraDia;
}

unsigned int Node::compraHora(){
    return var_compraHora;
}

unsigned int Node::compraMin(){
    return var_compraMin;
}

unsigned int Node::compraSeg(){
    return var_compraSeg;
}

bool Node::periodo(){
    return var_periodo;
}