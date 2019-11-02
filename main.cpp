/*
    Projeto da Disciplina de Programação C++ para Sistemas Embarcados
    da Universidade Federal de Santa Catarina.

    Autor: Sidinei Lindomar da Rocha Junior
    Contato: junior.sidinei@gmail.com
    Github: juniorsidineicode
*/

#include <iostream>
#include "PC_machine.h"
#include "ClockCalendar.h"
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    PC_machine obj_machine;
    cout << "\n Bem vindo a maquina de refrigerante! \n" << endl;
    obj_machine.startmachine();

}