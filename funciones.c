#include "libreria.h"

void crear_puntos(double *arg, struct recta *R1, struct recta *R2) //Ingresar puntos a las variables tipo struct recta
{
	R1->P1.x = arg[0];
	R1->P1.y = arg[1];

	R1->P2.x = arg[2];
	R1->P2.y = arg[3];

	R2->P1.x = arg[4];
	R2->P1.y = arg[5];

	R2->P2.x = arg[6];
	R2->P2.y = arg[7];
}

void encontrar_recta(struct recta *R1, struct recta *R2)
{
	R1->m = (R1->P2.y - R1->P1.y)/(R1->P2.x - R1->P1.x);  //Pendiente recta 1

	R2->m = (R2->P2.y - R2->P1.y)/(R2->P2.x - R2->P1.x);  //Pendiente recta 2

	R1->b = -(R1->m * R1->P1.x) + R1->P1.y;  //Punto de corte recta 1
	
	R2->b = -(R2->m * R2->P1.x) + R2->P1.y;	 //Punto de corte recta 2
}

void imprimir_puntos(struct recta R1, struct recta R2)
{
	printf("\n\n\tpuntos R1: (%.2f,%.2f) (%.2f,%.2f)\n\n", R1.P1.x, R1.P1.y, R1.P2.x, R1.P2.y);
	printf("\tpuntos R2: (%.2f,%.2f) (%.2f,%.2f)\n\n", R2.P1.x, R2.P1.y, R2.P2.x, R2.P2.y);
}

void imprimir_recta(struct recta R1, struct recta R2)
{
	if(R1.P1.x == R1.P2.x)
	{
		printf("\tR1: X = %.2f\n", R1.P1.x);
	}
	else if(R1.P1.y == R1.P2.y)
	{
		printf("\tR1: Y = %.2f\n", R1.P1.y);
	}
	else if(R1.b > 0)
	{
		printf("\tR1: Y = %.2fX + %.2f\n", R1.m, R1.b);
	}
	else if(R1.b < 0)
	{
		printf("\tR1: Y = %.2fX %.2f\n", R1.m, R1.b);
	}
	else
	{
		printf("\tR1: Y = %.2fX\n", R1.m);
	}
	if(R2.P1.x == R2.P2.x)
	{
		printf("\tR2: X = %.2f\n", R2.P1.x);
	}
	else if(R2.P1.y == R2.P2.y)
	{
		printf("\tR2: Y = %.2f\n", R2.P1.y);
	}
	else if(R2.b > 0)
	{
		printf("\tR2: Y = %.2fX + %.2f\n", R2.m, R2.b);
	}
	else if(R2.b < 0)
	{
		printf("\tR2: Y = %.2fX %.2f\n", R2.m, R2.b);
	}
	else
	{
		printf("\tR2: Y = %.2fX\n", R2.m);
	}
}
char cruce_puntos(struct recta R1, struct recta R2)
{
	char temp;

	if((R1.m * R2.m) == -1)
	{
		temp = -1;
	}
	else if(R1.m == R2.m)
	{
		temp = 0;
	}
	else
	{
		temp = 1;
	}
	if((R1.m == 0) && (R2.P1.x == R2.P2.x))
	{
		temp = -1;
	}
	else if((R2.m == 0) && (R1.P1.x == R1.P2.x))
	{
		temp = -1;
	}
	return temp;
}
void encontrar_cruce(struct punto *PC, struct recta R1, struct recta R2)
{
	PC->x = (R1.b - R2.b)/(R2.m - R1.m);

	PC->y = ((R2.m * R1.b) - (R1.m * R2.b))/(R2.m - R1.m);
}
