#include <stdio.h>
#include <stdbool.h>

void printaExito(int a, int b, int c, bool exito);
void printaFracaso(int a);
bool loEs(int x, int y, int z);
void buscarPar1(int n);
void buscarPar2(int num, int d1, int* d2, bool* exito);

int main() {

	int num;

	printf_s("introduceun numero o -1 para salir.\n");
	scanf_s("%d", &num);

	while (num != -1) {

		buscarPar1(num);

		printf_s("introduceun numero o -1 para salir.\n");
		scanf_s("%d", &num);

	}

	return 0;
}

void printaExito(int a, int b, int c, bool exito) {

	if (!exito)
	{
		printf_s("El numero: ");
		printf_s("%d", a);
		printf_s(" tiene pares de divisores cuyo producto es igual a el: ");
	}
	else {
		printf_s("Y tambien: ");
	}

	printf_s("Divisor 1: ");
	printf_s("%d", b);
	printf_s(" Divisor 2: ");
	printf_s("%d", c);
}

void printaFracaso(int a) {

	printf_s("el numero es: ");
	printf_s("%d", a);
	printf_s(" no tiene dos divisores diferentes de 1 cuyo producto sea igual a el.");

}

bool loEs(int x, int y, int z) {

	return x == (y * z);
}

void buscarPar1(int n) {

	bool exito = false;
	int d1 = 2;
	int d2 = 2;

	while (d1 <= (n / 2)) {

		buscarPar2(n, d1, &d2, &exito);
		d1 = d1 + 1;
	}

	if (!exito)
	{
		printaFracaso(n);

	}
	else {

		printf_s("*************************************");
	}
}

void buscarPar2(int num, int d1, int* d2, bool* exito) {

	bool encontrado;

	*d2 = d1;

	while (*d2 <= (num / 2)) {

		encontrado = loEs(num, d1, *d2);

		if (encontrado)
		{
			printaExito(num, d1, *d2, *exito);

			*exito = true;
		}

		*d2 = *d2 + 1;
	}


}