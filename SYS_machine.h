#ifndef SYS_MACHINE_H
#define SYS_MACHINE_H

using namespace std;

class SYS_machine: public Machine{
	int M25, M50, M100;
	int total;
	bool devolucao;
	int refri, sel;

   public:
	SYS_machine(void);
	~SYS_machine(void);
	void start();

};
#endif