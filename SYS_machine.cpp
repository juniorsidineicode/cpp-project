#include "SYS_machine.h"

/*VARIAVEIS GLOBAIS PARA ACESSOS AS CHAVES/SAIDAS*/

volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;
/*													*/

SYS_machine::SYS_machine(){
	// Enable all Outputs
	*direction = 0xffffffff;
	// Assign value to output registers ("escreve" 000000 nos LEDs)
	*output = 0x00000000;
}

SYS_machine::~SYS_machine(){
	
}