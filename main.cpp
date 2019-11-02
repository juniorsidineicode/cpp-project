#include <iostream>
#include "Machine.h"
#include "ClockCalendar.h"
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

int main(){
/*
	bool teste_total;
    int troco = 0, option = 0, select = 0;
    float soma = 0;
    teste_total = false;
    bool escolhido = false;
    bool alive = true;
    //inserido = false;
    bool button_devolve = false; 

	Machine obj_machine;

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
    		  	   obj_machine.incluiM25();
    	           break;
    		  case 2:
                    obj_machine.incluiM50();
                    break;
    		  case 3:
                    obj_machine.incluiM100();
                    break;
    		  default: 
                    cout << "BUGOU";
            }
            
            soma = obj_machine.acumulado();
            troco = obj_machine.troco(soma);
	        cout << "total = R$" << soma << "\n"<< endl;

            switch(troco){
                case 25:
                    cout << "Troco R$ 0,25: " << obj_machine.trocoM25() << endl;
                    break;
                case 50:
                    cout << "Troco R$ 0,50: " << obj_machine.trocoM50() << endl;
                    break;
                case 75:
                    cout << "Troco R$ 0,25: " << obj_machine.trocoM25() << endl;
                    cout << "Troco R$ 0,50: " << obj_machine.trocoM50() << endl;
                    break;
                case 100:
                    cout << "Troco R$ 1,00" << obj_machine.trocoM100() << endl;
                    break;
                default:
                    break;
                }

            teste_total = obj_machine.teste(soma);
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
                    escolhido = obj_machine.setRefri(select);
                    break;
                case 2:
                    escolhido = obj_machine.setRefri(select);
                    break;
                case 3:
                    button_devolve = obj_machine.devolve();

            }

            if(escolhido == 1 or button_devolve == 1){
                obj_machine.reset();
                //cout << "entrou" << endl;
                soma = 0;
                troco = 0;
                select = 0;
            }

	   }  
	   while(!escolhido and !button_devolve);
        

    }
    */
    Machine obj_machine;
    cout << "Bem vindo a maquina de refrigerante! \n" << endl;
    obj_machine.startmachine();

}