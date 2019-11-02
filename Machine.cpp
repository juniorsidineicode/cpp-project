#include "Machine.h"

Machine::Machine(){
	M25 = 0;
	M50 = 0;
	M100 = 0;
	sel = 0;
	total = 0;
	devolucao = false;
	refri = 0;
}

Machine::~Machine(){


}

void Machine::reset(){
	M25 = 0;
	M50 = 0;
	M100 = 0;
	sel = 0;
	total = 0;
	devolucao = false;
	refri = 0;
}

void Machine::startmachine(){
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
            cin >> option;

            

    	   switch(option){
    		  case 1:
    		  	   Machine::incluiM25();
    	           break;
    		  case 2:
                    Machine::incluiM50();
                    break;
    		  case 3:
                    Machine::incluiM100();
                    break;
    		  default: 
                    cout << "BUGOU";
            }
            
            soma = Machine::acumulado();
            troco = Machine::troco(soma);
	        cout << "total = R$" << soma << "\n"<< endl;

            switch(troco){
                case 25:
                    cout << "Troco R$ 0,25: " << Machine::trocoM25() << endl;
                    break;
                case 50:
                    cout << "Troco R$ 0,50: " << Machine::trocoM50() << endl;
                    break;
                case 75:
                    cout << "Troco R$ 0,25: " << Machine::trocoM25() << endl;
                    cout << "Troco R$ 0,50: " << Machine::trocoM50() << endl;
                    break;
                case 100:
                    cout << "Troco R$ 1,00" << Machine::trocoM100() << endl;
                    break;
                default:
                    break;
                }

            teste_total = Machine::teste(soma);
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
                    escolhido = Machine::setRefri(select);
                    break;
                case 2:
                    escolhido = Machine::setRefri(select);
                    break;
                case 3:
                    button_devolve = Machine::devolve();

            }

            if(escolhido == 1 or button_devolve == 1){
                Machine::reset();
                //cout << "entrou" << endl;
                soma = 0;
                troco = 0;
                select = 0;
            }

	   }  
	   while(!escolhido and !button_devolve);
        

    }

}
void Machine::incluiM25(){
	M25 = M25 + 1;
	//cout << "M25" << M25 << endl;
}

void Machine::incluiM50(){
	M50 = M50 + 1;
}
void Machine::incluiM100(){
	M100 = M100 + 1;
}

bool Machine::trocoM25(){
	return true;
}

bool Machine::trocoM50(){
	return true;
}

bool Machine::trocoM100(){
	return true;
}
bool Machine::devolve(){
	cout << "Troco devolvido!" << endl;
	return true;	
}

int Machine::troco(int total){
	return total - 150;
}

float Machine::acumulado(){
	return 0.25*M25 + 0.50*M50 + 1.00*M100;
}

bool Machine::teste(float total){
	float result = total;
	if(result >= 1.50){
		return true;
	}
	else{
		return false;	
	}
	
}

bool Machine::setRefri(int tipo_refri){
	int escolhido = tipo_refri;

	switch(escolhido){
		case 1:
			cout << "Voce selecionou o refri MEET \n" << endl;
			//return true;
			break;

		case 2:
			cout << "Voce selecionou o refri ETIRPS \n" << endl;
			//return true;
			break;

		default :
			cout << "Marca nao definida";
			//return false;
			break;
	}

	return true;
}