#ifndef LOG_H
#define LOG_H

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


    void totalCompras();

};
#endif