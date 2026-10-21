#include <stdio.h>
#include <stdbool.h>
#define Max_Vehiculos 100

void mediaVehiculos( float velocidad[], int contador);
void registroVehiculos(float velocidad[], int contador, bool* encontrado);
void resultados(float velocidad[], int contador, bool* encontrado);
bool superado(int contadorVehiculo160, int contadorVehiculo180, bool* encontrado);
void imprimirResultados(bool* encontrado, float vehiculo120[], int contador120, int contadorVehiculo160, int contadorVehiculo180);


int main() {
	int tiempo[Max_Vehiculos];
	float velocidad[Max_Vehiculos];
	int contador = 0;
	int t;
	float v;
	bool turnoTerminado = false;

	printf_s("ingrese el tiempo de inicio o -1 para finalizar:\n");
	scanf_s("%d", &t);
	if (t != -1) {
		printf_s("ingrese la velocidad del vehiculo registrado.\n");
		scanf_s("%f", &v);
	}

	if (t != -1)
	{
		while (t != -1) {
			
			tiempo[contador] = t;
			velocidad[contador] = v;

			contador++;

			printf_s("ingrese el tiempo de inicio o -1 para finalizar:\n");
			scanf_s("%d", &t);



			if (t == -1){break;}

			printf_s("ingrese la velocidad del vehiculo registrado.\n");
			scanf_s("%f", &v);

			

		}

	}
	else { printf_s("turno terminado"); }

	if (contador > 0)
	{
		resultados(velocidad, contador, &turnoTerminado);
	}


	return 0;
	}

void resultados(float velocidad[], int contador, bool* encontrado) {
	
	registroVehiculos(velocidad, contador, &encontrado);
}




	void mediaVehiculos(float velocidad[], int contador){

		float sumaVelocidad = 0;
		float media = 0;

		for (int i = 0; i < contador; i++)
		{
			sumaVelocidad += velocidad[i];

		}

		media = sumaVelocidad / contador;


		printf_s("la velocidad media registrada durante el turno: %.2f km\n", media);

	}


	void registroVehiculos(float velocidad[], int contador, bool* encontrado) {

		float Vehiculo120[Max_Vehiculos];
		int contadorVehiculo120 = 0;
		int contadorVehiculo160 = 0;
		int contadorVehiculo180 = 0;
		bool encontradoLocal = true;

		for (int i = 0; i < contador; i++)
		{
			if (velocidad[i] >= 120) {

				Vehiculo120[contadorVehiculo120] = velocidad[i];
				contadorVehiculo120++;

			}

		    if (velocidad[i] >= 180) {

				contadorVehiculo180++;

				if (contadorVehiculo180 == 2) {
				
					break;
				
				}
			}
			if (velocidad[i] >= 160)
			{
				contadorVehiculo160++;

				if (contadorVehiculo160 == 3)
				{
					break;
				}
			}

		}

		superado(contadorVehiculo160, contadorVehiculo180, &encontrado);

		encontradoLocal= superado(contadorVehiculo160, contadorVehiculo180, &encontrado);

		if (encontradoLocal == true)
		{
			mediaVehiculos(velocidad, contador);

			imprimirResultados(&encontradoLocal, Vehiculo120, contadorVehiculo120, contadorVehiculo160, contadorVehiculo180);
		}
		else { imprimirResultados(&encontradoLocal, Vehiculo120, contadorVehiculo120, contadorVehiculo160, contadorVehiculo180); }

		
		

	}

	bool superado(int contadorVehiculo160, int contadorVehiculo180, bool* encontrado){
		
		bool sentencia = true;
		
		if (contadorVehiculo180 == 2)
		{
			sentencia = false;
		}else if (contadorVehiculo160 >= 3)
		{
			sentencia = false;
		}
	
		*encontrado = sentencia;

		return *encontrado;

	}


	void imprimirResultados(bool* encontrado, float vehiculo120[], int contador120, int contadorVehiculo160, int contadorVehiculo180) {

		float subida = vehiculo120[0];
		float bajada = vehiculo120[0];
		int contadorSubida = 0;
		int contadorBajada = 0;

		if (*encontrado == true) {

			printf_s("Se han registrado 1 vehiculo por encima de 120km/h\n");

			for (int i = 0; i < contador120; i++)
			{
				if (subida < vehiculo120[i]) {

					subida = vehiculo120[i];

					contadorSubida++;

				}

				if (bajada > vehiculo120[i]){

					bajada = vehiculo120[i];
				
					contadorBajada++;
				}
			}

			if (contadorSubida > contadorBajada)
			{
				printf_s("La tendencia de la velocidad durante el turno va a la alza.\n");
			}
			else { printf_s("La tendencia de la velocidad durante el turno va a la baja o se mantiene./n"); }
		}

		if (*encontrado == false)
		{
			if (contadorVehiculo160 == 3)
			{
				printf_s("Se han registrado 3 o mas lecturas de 160km/h o superior\n");
			}
			else if (contadorVehiculo180 == 2)
			{
				printf_s("Se han registrado 2 lecturas consecutivas de 180km/h\n");
			}

		}

	}
