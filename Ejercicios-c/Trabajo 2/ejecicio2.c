#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {

	//variables

	int n1, n2, mayor, menor, i;
	int sumaPares = 0;

	mayor = 0;
	menor = 0;

	printf_s("introduce el primer numero entero: \n");
	scanf_s("%d", &n1);

	printf_s("introduce el segundo numero entero : \n");
	scanf_s("%d", &n2);

	if (n1 > n2)
	{
		mayor = n1;
		menor = n2;
	}
	else
	{
		mayor = n2;
		menor = n1;
	}

	printf_s("Orden: El mayor es %d y el menor es %d.\n", mayor, menor);

	printf_s("los numeros PARES entre %d y %d son: \n", menor, mayor);

	for(i = menor; i <= mayor; i++)
	{
		if (i % 2 == 0)
		{
			printf_s("%d \n", i);

			sumaPares = sumaPares + i;
		}

	}

	printf_s("La suma de los numeros pares mostrados es: %d \n", sumaPares);

	return 0;
}