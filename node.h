#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;


class Node {

    int valor_refri;
    string nome_refri;
    //data
    Node* next;

  public:
         
    Node(int valor, string nome, Node* nxt);
    Node* getNext();
    int getTimer();
    int setTimer();
    void setValrefri(int valor, string nome);
    void getValrefri();
    void setNome(string nome);
    void getNome();
    void setNext(Node* nxt);
};
#endif