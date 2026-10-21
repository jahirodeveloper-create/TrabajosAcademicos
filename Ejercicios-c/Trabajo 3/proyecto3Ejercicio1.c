#include <stdio.h>
#define MAXnumeros 15

void imprimirArray(int imprimir[], int contadorFunciones);
void sumaArray(int imprimir[], int contadorFunciones);
int mediaArray(int imprimir[], int contadorFunciones, int* media);
void mayorYmenorArray(int imprimir[], int contadorfunciones);
void paresYimpareArray(int* imprimir, int contadorfunciones);
void numerosfiltradosArray(int* imprimir, int contadorFuciones, int* segundoArray, int* mediaCalculo);

int main() {

	int numeros[MAXnumeros];
	int numerosFiltrados[MAXnumeros];
	int numInput;
	int contador = 0;
	int media = 0;


	printf_s("introduce %d numeros:\n", MAXnumeros);


	while (contador < MAXnumeros) {

		printf_s("ingrese el %d numero o un -1 para finalizar:\n", contador + 1);

		scanf_s("%d", &numInput);

		if (numInput == -1)
		{
			break;
		}

		numeros[contador] = numInput;

		contador++;


	}

	if (contador > 0)
	{

		imprimirArray(numeros, contador);
		sumaArray(numeros, contador);
		mediaArray(numeros, contador, &media);
		mayorYmenorArray(numeros, contador);
		paresYimpareArray(numeros, contador);
		numerosfiltradosArray(numeros, contador, numerosFiltrados, &media);

	}
	else {
		printf_s("programa finalizado");
	}

	return 0;
}

void imprimirArray(int imprimir[], int contadorFunciones) {

	for (int i = 0; i < contadorFunciones; i++)
	{
		printf_s("el numero %d es: %d\n", i + 1, imprimir[i]);
	}
}

void sumaArray(int imprimir[], int contadorFunciones) {

	int sumaNumeros = 0;

	for (int i = 0; i < contadorFunciones; i++)
	{
		sumaNumeros += imprimir[i];

	}

	printf_s("la suma de los numeros es: %d\n", sumaNumeros);
}

int mediaArray(int imprimir[], int contadorFunciones, int* media) {

	int sumaNumeros = 0;
	int mediaNumeros = 0;

	for (int i = 0; i < contadorFunciones; i++)
	{
		sumaNumeros += imprimir[i];
	}

	mediaNumeros = sumaNumeros / contadorFunciones;

	printf_s("la media de la sumatoria es: %d\n", mediaNumeros);

	*media = mediaNumeros;

	
}

void mayorYmenorArray(int imprimir[], int contadorfunciones) {

	int mayor = imprimir[0];
	int menor = imprimir[0];

	for (int i = 0; i < contadorfunciones; i++)

	{
		if (mayor < imprimir[i])
		{
			mayor = imprimir[i];

		}


		if (imprimir[i] < menor)
		{
			menor = imprimir[i];
		}
	
	}

	printf_s("el numero menor es: %d y el mayor es: %d \n", menor, mayor);

}

void paresYimpareArray(int* imprimir, int contadorfunciones) {

	printf_s("los numeros pares son:");

	for (int i = 0; i < contadorfunciones; i++) {

		if (imprimir[i] % 2 == 0)
		{
			printf_s(" %d", imprimir[i]);
		}
	}

	printf_s("\nlos numeros impares son:");

	for (int i = 0; i < contadorfunciones; i++)
	{
		if (imprimir[i] % 2 != 0)
		{
			printf_s(" %d", imprimir[i]);
		}

	}

	printf_s("\n");
}

void numerosfiltradosArray(int* imprimir, int contadorFuciones, int* segundoArray, int* mediaCalculo) {

	for (int i = 0; i < contadorFuciones; i++)
	{
		if (imprimir[i] >= *mediaCalculo) {

			segundoArray[i] = imprimir[i];

		}
		else {

			segundoArray[i] = 0;
		}

	}

	printf_s("  posicion   |  numero array   |  numero filtrado\n");

	for (int i = 0; i < contadorFuciones; i++)
	{
		
		printf_s(" %d  |  %d |  %d \n", i+1, imprimir[i], segundoArray[i]);
	}

}