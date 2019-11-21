#include "PC_machine.h"
#include "log.h"


using namespace std;

Log obj_lista;


PC_machine::PC_machine(){
	M25 = 0;
	M50 = 0;
	M100 = 0;
	sel = 0;
	total = 0;
	devolucao = false;
	refri = 0;
}

PC_machine::~PC_machine(){

}

void PC_machine::reset(){
	M25 = 0;
	M50 = 0;
	M100 = 0;
	sel = 0;
	total = 0;
	devolucao = false;
	refri = 0;
}

void PC_machine::startmachine(){

	bool teste_total;
    int troco = 0, option = 0, select = 0;
    float soma = 0;
    teste_total = false;
    bool escolhido = false;
    bool alive = true;
    //inserido = false;
    bool button_devolve = false; 

    while(alive){
	   do{
            cout << "Para escolher o refrigerante insira a soma R$ 1,50 \n" << endl;
            cout << "Insira:" << endl;
            cout << "1 - R$ 0,25" << endl;
            cout << "2 - R$ 0,50" << endl;
            cout << "3 - R$ 1,00" << endl;
            cout << "4 - ADM" << endl;
            cin >> option;

            

    	   switch(option){
    		  case 1:
    		  	   PC_machine::incluiM25();
    	           break;
    		  case 2:
                    PC_machine::incluiM50();
                    break;
    		  case 3:
                    PC_machine::incluiM100();
                    break;
              case 4:
                    obj_lista.totalCompras();
                    break;
    		  default: 
                    cout << "BUGOU";
            }
            
            soma = PC_machine::acumulado();
            troco = PC_machine::troco(soma);
	        //cout << "total = R$" << soma << "\n"<< endl;

            switch(troco){
                case 25:
                    cout << "Troco R$ 0,25: " << PC_machine::trocoM25() << endl;
                    break;
                case 50:
                    cout << "Troco R$ 0,50: " << PC_machine::trocoM50() << endl;
                    break;
                case 75:
                    cout << "Troco R$ 0,25: " << PC_machine::trocoM25() << endl;
                    cout << "Troco R$ 0,50: " << PC_machine::trocoM50() << endl;
                    break;
                case 100:
                    cout << "Troco R$ 1,00" << PC_machine::trocoM100() << endl;
                    break;
                default:
                    break;
                }

            teste_total = PC_machine::teste(soma);
            //button_devolve = obj_machine.devolve();

        }
        while(!teste_total);

	   do{
            cout << "Selecione a opcao desejada:" << endl;
            cout << "1 - MEET" << endl;
            cout << "2 - ETIRPS" << endl;
            cout << "3 - Devolucao" << endl;
            cin >> select;

            switch(select){
                case 1:
                    escolhido = PC_machine::setRefri(select);
                    break;
                case 2:
                    escolhido = PC_machine::setRefri(select);
                    break;
                case 3:
                    button_devolve = PC_machine::devolve();

            }

            if(escolhido == 1 or button_devolve == 1){
                PC_machine::reset();
                //cout << "entrou" << endl;
                soma = 0;
                troco = 0;
                select = 0;
            }

	   }  
	   while(!escolhido and !button_devolve);
        

    }

}

void PC_machine::incluiM25(){
	M25 = M25 + 1;
}

void PC_machine::incluiM50(){
	M50 = M50 + 1;
}
void PC_machine::incluiM100(){
	M100 = M100 + 1;
}

bool PC_machine::trocoM25(){
	return true;
}

bool PC_machine::trocoM50(){
	return true;
}

bool PC_machine::trocoM100(){
	return true;
}
bool PC_machine::devolve(){
	cout << "Troco devolvido!" << endl;
	return true;	
}

int PC_machine::troco(int total){
	return total - 150;
}

float PC_machine::acumulado(){
	return 0.25*M25 + 0.50*M50 + 1.00*M100;
}

bool PC_machine::teste(float total){
	float result = total;
	if(result >= 1.50){
		return true;
	}
	else{
		return false;	
	}	
}

bool PC_machine::setRefri(int tipo_refri){
	int escolhido = tipo_refri;

	switch(escolhido){
		case 1:
			cout << "Voce selecionou o refri MEET \n" << endl;
            obj_lista.insertAfterLast(1, 1.50);
			//return true;
			break;

		case 2:
			cout << "Voce selecionou o refri ETIRPS \n" << endl;
			obj_lista.insertAfterLast(2, 1.50);
            //return true;
			break;

		default :
			cout << "Marca nao definida";
			break;
	}

	return true;
}