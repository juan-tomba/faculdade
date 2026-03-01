#ifndef RACIONAL_H
	#define RACIONAL_H
	
	typedef struct racional RACIONAL;

	void print_num(RACIONAL *r);
	RACIONAL* criar(int num, int den);
	void apagar(RACIONAL* rac);

	RACIONAL* adicao(RACIONAL* a, RACIONAL* b);
	RACIONAL* multiplicacao(RACIONAL* a, RACIONAL* b);

	void imprimir(RACIONAL* rac);

#endif