#include <stdio.h>
#include <stdbool.h>

 typedef enum{
    MANZANA,
    PERA,
    PLATANO,
    FRESA,
    PINA,
    CEREZA
}fruta;

typedef enum{
    MADURO,
    VERDE,
    PASADO,
    COSECHADO
}estado;



const int maxUnidades = 12;
const float precioBase = 2.75;

int main() {


    fruta f1, f2;
    estado e1, e2;
    bool esOk = true;
    int x=2, y=5, z=3;
    float peso= 1.5, total= 20.0;
    char letra = 'A';

    /*primera parte*/
    
   if ((x*y > z && esOk) || false){

    printf_s("resultado es true\n");

   }else{

    printf_s("El resultado es false\n");
   }

   if ((-x + y % z) > x && !esOk)
   {
     printf_s("resultado es true\n");

   }else{

    printf_s("El resultado es false\n");
   }

   /*caracterACodigo(letra) + x = y o f1*/

   int codigo;
   codigo = (int) letra;
   f1 = PERA;

   if (codigo + x == y || f1)
   {
    printf_s("resultado es true\n");

   }else{

    printf_s("El resultado es false\n");
   }

   /*segunda parte*/

   float codigo2;
   codigo2 = (float) x;
   e1 = MADURO;
   
   if ((e1 == MADURO || peso) > (codigo2 * 5.0 - 8.5))
   {
    printf_s("resultado es true\n");

   }else{

    printf_s("El resultado es false\n");
   }

   int realAentero;
   realAentero = (int) total - peso;
   codigo;
   char codigoAcaracter;
   codigoAcaracter = (char) realAentero + codigo;

        if (codigoAcaracter == 'S' && e1 != VERDE )
   {
    printf_s("resultado es true\n");

   }else{

    printf_s("El resultado es false\n");
   }

    return 0;
}