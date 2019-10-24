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