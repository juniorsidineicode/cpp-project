#include "log.h"

//refrigerante = 1 MEET
//refrigerante = 2 ETIRPS

Log::Log(){
	head = 0;
}

Log::~Log(){
	Node* cursor = head;
    while(head) {
        cursor = cursor->getNext();
        delete head;
        head = cursor;
    }
    head = 0;
}

void Log::insertBeforeFirst(int refri, float valor) {
    head = new Node(refri, valor, head);
}

void Log::insertAfterLast(int refri, float valor) {
    Node* p = head;
    Node* q = head;

    if (head == 0)
        head = new Node(refri, valor, head);
    else {
        while (q != 0) {
            p = q;
            q = p->getNext();
        }
        p->setNext(new Node(refri, valor, 0));
    }
}

int Log::readFirstRefri() {
    if(head == 0)
        return -1;
    else
        return head->getRefri(); 
}

int Log::readFirstVal() {
    if(head == 0)
        return -1;
    else
        return head->getValrefri(); 
}

void Log::removeFirst() {
    //int retval = 0;
    if (head != 0){
        //retval = head->getVal();
        Node* oldHead = head;
        head = head->getNext();
        delete oldHead;
    }
}

void Log::totalCompras() {
    Node* temp = head;
    int i = 0;
    float val_meet = 0;
    int num_meet = 0;
	float val_etirps = 0;
	int num_etirps = 0;
	float val_total = 0;
	int num_total = 0;

    while (temp != 0){
        i++;
        //cout <<"\n Compras: (" << i << ")" << endl;
        
        if(temp->getRefri() == 1){
            cout <<"Refrigerante: MEET" << endl;
            num_meet++;
            cout <<"Valor: " << temp->getValrefri() << endl;
            val_meet += temp->getValrefri();

        }

        if(temp->getRefri() == 2){ 
            cout <<"Refrigerante: ETIRPS" << endl;
            num_etirps++;
            cout <<"Valor: " << temp->getValrefri() << endl;
            val_etirps += temp->getValrefri();
        }
        
        
        temp = temp->getNext();
    }

    val_total = val_etirps + val_meet;
    num_total = num_meet + num_etirps;

    cout << " \n Quantidade total de compras MEET: " << num_meet << endl;
    cout << " \n Valor total de compras MEET: R$ " << val_meet << endl;
    cout << " \n Quantidade total de compras ETIRPS: " << num_etirps << endl;
	cout << " \n Valor total de compras ETIRPS: R$ " << val_etirps << endl;
	cout << " \n Quantidade total de compras: " << num_total << endl;
	cout << " \n Valor total de compras: R$ " << val_total << endl;
	cout << "\n" << endl;
}
