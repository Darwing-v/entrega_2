#include "libreria.h"

int main(int argc, char* argv[])
{
	struct recta R1;
	struct recta R2;

	double vals[8];
	char comp;
	struct punto PC;

	if(argc != 9)
	{
		printf("\n\n\tError en la cantidad de argumentos\n\tPor favor ingrese 9 argumentos de la forma:\n\t ./Nombre_programa.bin X1 Y1 X2 Y2 X3 Y3 X4 Y4\n\n\t");
		exit(1);
	}
	vals[0] = atof(argv[1]);
	vals[1] = atof(argv[2]);
	vals[2] = atof(argv[3]);
	vals[3] = atof(argv[4]);
	vals[4] = atof(argv[5]);
	vals[5] = atof(argv[6]);
	vals[6] = atof(argv[7]);
	vals[7] = atof(argv[8]);

	if((vals[0] == vals[2]) && (vals[1] == vals[3]))
	{
		printf("\n\n\tIngreso dos puntos iguales para una misma recta, por favor verifique sus datos.\n\n");
		exit(1);
	}
	else if((vals[4] == vals[6]) && (vals[5] == vals[7]))
	{
		printf("\n\n\tIngreso dos puntos iguales para una misma recta, por favor verifique sus datos.\n\n");
		exit(1);
	}


	crear_puntos(&vals[0], &R1, &R2);

	encontrar_recta(&R1, &R2);

	imprimir_puntos(R1, R2);	

	imprimir_recta(R1, R2);

	comp = cruce_puntos(R1, R2);

	encontrar_cruce(&PC, R1, R2);

	if(comp == -1)
	{
		printf("\n\tLas rectas son perpendiculares\n\n");
	}
	else if(comp == 0)
	{
		printf("\n\tLas rectas son paralelas\n\n");
	}
	else
	{
		printf("\n\tLas rectas no son ni paralelas ni perpendiculares\n\n");
	}

	if(R1.m == R2.m)
	{
		if(R1.b == R2.b)
		{
			printf("\tNo se puede determinar el punto de corte ya que las dos rectas son la misma.\n\n");
		}
	}
	else
	{
	printf("\tEl punto de corte entre entre las dos rectas es: (%.2f,%.2f)\n\n", PC.x, PC.y);
	}
}
