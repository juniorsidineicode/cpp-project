#include "Node.h"

//refrigerante = 1 MEET
//refrigerante = 2 ETIRPS

Node::Node(int s, float p, Node* nxt){
       refrigerante = s;
       valor_refri = p;
       next = nxt;
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