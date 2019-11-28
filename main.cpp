/*
    Projeto da Disciplina de Programação C++ para Sistemas Embarcados
    da Universidade Federal de Santa Catarina.

    Autor: Sidinei Lindomar da Rocha Junior
    Contato: junior.sidinei@gmail.com
    Github: juniorsidineicode

    Com duas opções para compilação 
    #include "PC_machine.h" -> para compilar e utilizar no PC
    #include "SYS_machine.h" -> para compilar e utilizar na placa
*/

#include <iostream>
#include "PC_machine.h"
#include "Machine.h"
//#include "SYS_machine.h" //Descomentar apenas quando for compilar para placa
#include "ClockCalendar.h"
#include "ClockCount.h"
#include <thread>
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    obj_contador ClockCount::takeinstance(); //contar o tempo durante o uso da machine
    
    cout << "\n Bem vindo a maquina de refrigerante! \n" << endl;
    PC_machine obj_machine;
    obj_machine.startmachine();
    

}