#ifndef LIBRERIA_H
#define LIBRERIA_H

#include<stdio.h>
#include<stdlib.h>

struct punto 
{
	double x;
	double y;
};
struct recta
{
	double m;
	double b;
	struct punto P1;
	struct punto P2;
};

void crear_puntos(double *arg, struct recta *R1, struct recta *R2);
void encontrar_recta(struct recta *R1, struct recta *R2);
void imprimir_puntos(struct recta R1, struct recta R2);
void imprimir_recta(struct recta R1, struct recta R2);
char cruce_puntos(struct recta R1, struct recta R2);
void encontrar_cruce(struct punto *PC, struct recta R1, struct recta R2);

#endif
