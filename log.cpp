#include "log.h"

/*
    Classe log para montar o relatório de vendas chamado de log
    utilizado numa FIFO para geração do log do sistema de vendas
    implementamos um log para mostrar o refrigerante vendido
    seu preço e horario de venda.
   Arquivo .cpp com implementação das funções que usaremos.
*/

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

int Log::totalCompras() {
    Node* temp = head;
    Node* temp_delete = head;
    unsigned int compraAno_etirps, compraAno_meet;
    unsigned int compraMes_etirps, compraMes_meet;
    unsigned int compraDia_etirps, compraDia_meet;
    unsigned int compraHora_etirps, compraHora_meet;
    unsigned int compraMin_etirps, compraMin_meet;
    unsigned int compraSeg_etirps, compraSeg_meet;
    bool periodo_etirps, periodo_meet;
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
            compraAno_meet = temp -> compraAno();
            compraMes_meet = temp -> compraMes();
            compraDia_meet = temp -> compraDia();
            compraHora_meet = temp -> compraHora();
            compraMin_meet = temp -> compraMin();
            compraSeg_meet = temp -> compraSeg();
        }

        if(temp->getRefri() == 2){ 
            cout <<"Refrigerante: ETIRPS" << endl;
            num_etirps++;
            cout <<"Valor: " << temp->getValrefri() << endl;
            val_etirps += temp->getValrefri();
            compraAno_etirps = temp -> compraAno();
            compraMes_etirps = temp -> compraMes();
            compraDia_etirps = temp -> compraDia();
            compraHora_etirps = temp -> compraHora();
            compraMin_etirps = temp -> compraMin();
            compraSeg_etirps = temp -> compraSeg();
        }
        
        
        temp = temp->getNext();
    }

    val_total = val_etirps + val_meet;
    num_total = num_meet + num_etirps;

    cout << " \n Quantidade total de compras MEET: " << num_meet << endl;
    cout << " \n Valor total de compras MEET: R$ " << val_meet << endl;
    cout << setw(4) << setfill('0') << compraAno_meet;
    cout << "/";
    cout << setw(2) << setfill('0') << compraMes_meet;
    cout << "/";
    cout << setw(2) << setfill('0') << compraDia_meet;
    cout << " - ";
    cout << setw(2) << setfill('0') << compraHora_meet;
    cout << ":";
    cout << setw(2) << setfill('0') << compraMin_meet;
    cout << ":";
    cout << setw(2) << setfill('0') << compraSeg_meet;
    cout << (periodo_meet ? " pm" : " am") << endl;



    cout << " \n Quantidade total de compras ETIRPS: " << num_etirps << endl;
	cout << " \n Valor total de compras ETIRPS: R$ " << val_etirps << endl;
    cout << setw(4) << setfill('0') << compraAno_etirps;
    cout << "/";
    cout << setw(2) << setfill('0') << compraMes_etirps;
    cout << "/";
    cout << setw(2) << setfill('0') << compraDia_etirps;
    cout << " - ";
    cout << setw(2) << setfill('0') << compraHora_etirps;
    cout << ":";
    cout << setw(2) << setfill('0') << compraMin_etirps;
    cout << ":";
    cout << setw(2) << setfill('0') << compraSeg_etirps;
    cout << (periodo_etirps ? " pm" : " am") << endl;


	cout << " \n Quantidade total de compras: " << num_total << endl;
	cout << " \n Valor total de compras: R$ " << val_total << endl;
	cout << "\n" << endl;

    while(temp_delete != 0){
        removeFirst();
    }
    return 0;

}
