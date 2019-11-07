#ifndef NODE_H
#define NODE_H

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