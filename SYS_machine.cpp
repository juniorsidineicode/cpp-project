#include "SYS_machine.h"
#include "log.h"

/*VARIAVEIS GLOBAIS PARA ACESSOS AS CHAVES/SAIDAS*/
volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;
/*													*/

Log obj_lista;


SYS_machine::SYS_machine(){
	// Enable all Outputs
	*direction = 0xffffffff;
	// Assign value to output registers ("escreve" 000000 nos LEDs)
	*output = 0x00000000;
}

SYS_machine::~SYS_machine(){
}

void SYS_machine::reset(){
	M25 = 0;
	M50 = 0;
	M100 = 0;
	sel = 0;
	total = 0;
	devolucao = false;
	refri = 0;
}


void SYS_machine::startmachine(){
	bool teste_total;
    int troco = 0, option = 0, select = 0, espera_botao = 0;
    volatile unsigned int temp{};
    temp = *data >>8;
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
            espera_botao = delay(0x10000);
            option = temp;

    	   switch(option){
    		  case 1:
    		  	   SYS_machine::incluiM25();
    	           break;
    		  case 2:
                    SYS_machine::incluiM50();
                    break;
    		  case 3:
                    SYS_machine::incluiM100();
                    break;
              case 4:
                    obj_lista.totalCompras();
                    break;
    		  default: 
                    cout << "BUGOU";
        	}

        	soma = SYS_machine::acumulado();
            troco = SYS_machine::troco(soma);

            switch(troco){
            	case 25:
                    cout << "Troco R$ 0,25: " << SYS_machine::trocoM25() << endl;
                    break;
                case 50:
                    cout << "Troco R$ 0,50: " << SYS_machine::trocoM50() << endl;
                    break;
                case 75:
                    cout << "Troco R$ 0,25: " << SYS_machine::trocoM25() << endl;
                    cout << "Troco R$ 0,50: " << SYS_machine::trocoM50() << endl;
                    break;
                case 100:
                    cout << "Troco R$ 1,00" << SYS_machine::trocoM100() << endl;
                    break;
                default:
                    break;
                }

                teste_total = SYS_machine::teste(soma);
            }while(!teste_total);

           
            do{
            	cout << "Selecione a opcao desejada:" << endl;
            	cout << "1 - MEET" << endl;
            	cout << "2 - ETIRPS" << endl;
            	cout << "3 - Devolucao" << endl;
            	espera_botao = delay(0x10000);
            	select = temp;

            	switch(select){
            		case 1:
                    	escolhido = SYS_machine::setRefri(select);
                    	break;
                	case 2:
                    	escolhido = SYS_machine::setRefri(select);
                    	break;
                	case 3:
                    	button_devolve = SYS_machine::devolve();
					
				}

				if(escolhido == 1 or button_devolve == 1){
					SYS_machine::reset();
                	//cout << "entrou" << endl;
                	soma = 0;
                	troco = 0;
                	select = 0;
            	}
           	}while(!escolhido and !button_devolve);
	
	}
}


int SYS_machine::delay(int lim){
	int count=0;
		while (count==0){
			count=(*data&lim)>>16;
			if (count>0) for (int i=0;i<200;i++);  //atraso
			while ((*data&lim)>0);			
		}
		return count;

}

void SYS_machine::incluiM25(){
	M25 = M25 + 1;
}

void SYS_machine::incluiM50(){
	M50 = M50 + 1;
}
void SYS_machine::incluiM100(){
	M100 = M100 + 1;
}

bool SYS_machine::trocoM25(){
	return true;
}

bool SYS_machine::trocoM50(){
	return true;
}

bool SYS_machine::trocoM100(){
	return true;
}

bool SYS_machine::devolve(){
	cout << "Troco devolvido!" << endl;
	return true;	
}

int SYS_machine::troco(int total){
	return total - 150;
}

float SYS_machine::acumulado(){
	return 0.25*M25 + 0.50*M50 + 1.00*M100;
}

bool SYS_machine::teste(float total){
	float result = total;
	if(result >= 1.50){
		return true;
	}
	else{
		return false;	
	}
	
}

bool SYS_machine::setRefri(int tipo_refri){
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