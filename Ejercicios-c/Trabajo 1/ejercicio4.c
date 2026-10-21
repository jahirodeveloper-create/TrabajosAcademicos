#include <stdio.h>

int main (){

    const float DESCUENTO_PROMO = 0.05;

    int id, id_caro, contador;
    float precio, precio_caro, suma_total, promedio;

    suma_total = 0.0;
    precio_caro = 0.0;
    id_caro = 0;
    contador = 0;

    /*inicio variables acuario*/
    float total_acuario, media_acuario;
    int contador_acuario = 0;
    total_acuario = 0.0;
    media_acuario = 0.0;
    /*fin variables acuario*/

    printf("escribe el id: \n");

    scanf("%d", & id);
    
    while (id > 0){

        printf("escriba el precio: \n");
        scanf("%f", & precio);
        suma_total = suma_total + precio;
        contador = contador + 1;

        if (precio > precio_caro)
            {
                precio_caro = precio;
                id_caro = id;
            }

        
        /*inicio acuario calculo*/
        if (id >= 500 && id <= 600)
        {
            
            total_acuario = total_acuario + precio;
            contador_acuario = contador_acuario + 1;
        }
        /*fin acuario calculo*/

        

        printf("escriba el id: \n");
        scanf("%d", & id);
        
    }

    if (contador > 0)
    {
        promedio = suma_total / (float)contador;

    }else{

        promedio = 0.0;
    }

    /*inicio calculo media acuario*/
        if (contador_acuario > 0)
    {
        media_acuario = total_acuario / (float)contador_acuario;

    }else{

        media_acuario = 0.0;
    }
    /*fin calculo media acuario*/

    printf("suma total: %.2f\n", suma_total);
    printf("el promedio es: %.2f\n", promedio);
    printf("el id es: %d\n", id_caro);
    printf("suma total es: %.2f\n", suma_total * DESCUENTO_PROMO);
    /*inicio imprimir acuario*/
    printf("el total de acurio es: %.2f\n", total_acuario);
    printf("la media de acurio es: %.2f\n", media_acuario);
    /*sin imprimir acuario */
    
    return 0;
}