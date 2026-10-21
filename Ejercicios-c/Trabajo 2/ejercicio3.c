#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int a, b, axb_usuario, axb, i, resultado;
	i = 0;
	axb = 0;
	bool correcto = false;

	printf_s("introduce un primer numero del 1 al 10: \n");
	scanf_s("%d", &a);

	while ( !(a > 0 && a <= 10))
	{
		if (!(a > 0 && a <= 10))
		{
			printf_s("numero invalido\n");

			printf_s("introduce un primer numero del 1 al 10: \n");
			scanf_s("%d", &a);
		}
	}

	printf_s("Introduce un segundo numero del 1 al 10: \n");
	scanf_s("%d", &b);

	while (!(b > 0 && b <= 10))
	{
		if (!(b > 0 && b <= 10))
		{
			printf_s("numero invalido\n");

			printf_s("introduce un segundo numero del 1 al 10: \n");
			scanf_s("%d", &b);
		}

	}

	printf_s("cuanto crees que es el resultado de multiplicar %d por %d ?\n" ,a,b);

	scanf_s("%d", &axb_usuario);

	while(i <= 10)
	{

		if (i >= 1) {
			
			axb = axb + a;

			printf_s("%d multiplicado por %d es: %d\n", a, i, axb);

		}else
		{
			printf_s("%d multiplicado por 0 es: 0\n" , a);
		
		}

		if (i == b)
		{
			resultado = axb;
		}

		i = i + 1;
	}

	if (resultado == axb_usuario)
	{
		correcto = true;
	}

	if (correcto)
	{
		printf_s("%d multiplicado por %d es %d, como has indicado.\n", a, b, resultado);
	}else
	{
		printf_s("%d multiplicado por %d no es %d, como has indicado.\n", a, b, axb_usuario);
	}

	return 0;
}