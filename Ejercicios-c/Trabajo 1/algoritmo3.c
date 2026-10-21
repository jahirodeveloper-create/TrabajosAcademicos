#include <stdio.h>
#include <stdbool.h>


int main(){

    const int MESES_EJERCICIO = 12;


    float cuota, descuento, pagoRealizado, ahorroTotal, costeAnualEstimado;
    int meses, edad;
    bool esVip;
    

    printf("introduce el coste de la cuota menssual base: \n");
    scanf("%f", &cuota);
    printf("introduce los meses que llevas apuntando: \n");
    scanf("%d", &meses);
    printf("introduce tu edad: \n");
    scanf("%d", &edad);

    float antiguedadReal;

    antiguedadReal = (float) meses;

    if (edad >= 65){
        descuento = 0.40;
    }else{
        descuento = 0.10;
    }

    pagoRealizado = cuota * antiguedadReal;
    ahorroTotal = pagoRealizado * descuento;
    costeAnualEstimado = cuota * (float)MESES_EJERCICIO;
    esVip = ahorroTotal > costeAnualEstimado;

    if (esVip){
        
        printf("Eres socio VIP. Tu ahorro toatla es %f y supera el coste de un año (%f)\n", ahorroTotal, costeAnualEstimado);

    }else{
        printf("socio estandar. Tus ahorro acumulado es %f\n", ahorroTotal);

    }

    printf("has estado con nosotros %d meses y has invertido %f euros\n", meses , pagoRealizado);
        
    return 0;
}
