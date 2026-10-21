#include <stdio.h>
#include <stdbool.h>

int main() {
    // variables
    int n, numero, contador;
    bool digitos ;
    // fin variables

    contador = 1000;
    n = 1;
    numero = 0;
    
    do
    {
         digitos = false;
        

        if (n < 10)
        {
            if (n == 9)
            {
                digitos = true;
            }

        }
        else if (n < 100)
        {
            numero = ((n / 10) + (n % 10));

            if (numero > 9)
            {
                numero = ((numero / 10) + (numero % 10));
            }

        }

        if (numero == 9)
        {
            digitos = true;

        }
        else if (n < 1000)
        {
            numero = (n / 100) + ((n / 10) % 10) + (n / 10);

            if (numero > 9)
            {
                numero = ((numero / 10) + (numero % 10));
            }

        }

        if (numero == 9)
        {
            digitos = true;

        }

        if (digitos)
        {
            if (n % 9 == 0)
            {
                printf("el numero: %d es multiplo de 9. \n", n);
            }
        }

        n = n + 1;
        
    } while (n <= contador);
    


    return 0;
}