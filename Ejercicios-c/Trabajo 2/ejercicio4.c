#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	int a, n;
	a = 1;
	bool primo = false;

	printf_s("introduce un numero:\n");
	scanf_s("%d", &n);

	if (n % 2 == 0 && n != 2)
	{
		primo = false;

	}else
	{
		primo = true;
	
	
	}

	if (primo)
	{
		printf_s("El numero %d es primo.\n", n);

	}
	else
	{
		printf_s("El numero %d no es primo y sus divisores son: ", n);

		while (a < n)
		{
			if (n % a == 0)
			{
				printf_s("%d ", a);

			}

			a = a + 1;

		}


	}

	return 0;
}