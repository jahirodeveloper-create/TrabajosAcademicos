#include <stdio.h>
#include <stdbool.h>

#define MAX 50
#define MAX_BIBLIOTECA 5000

typedef struct {
    char nombre[MAX];
    int l;
} palabra;

typedef enum {
    NOVELA, ENSAYO, POESIA, TECNICO, INFANTIL
} tgenero;

typedef struct {
    palabra titulo;       
    char codigo[14];
    palabra nombreAutor;
    palabra apellidoAutor;
    tgenero genero;
    int numeroPaginas;
    int yearPublicacion;
    int numeroDeEjemplares;
    bool disponible;       
} tLibreria;

typedef struct {
    palabra tituloCopia;
    palabra nombreCopia;
    palabra apellidoCopia;
} copialibros;

typedef struct {
    copialibros NOVELA;
    copialibros ENSAYO;
    copialibros POESIA;
    copialibros TECNICO;
    copialibros INFANTIL;
} egenero;

typedef struct {
    tLibreria libros[MAX_BIBLIOTECA];
    egenero generosLibros[MAX_BIBLIOTECA];
    int total;
} tbiblioteca;

tbiblioteca biblioteca;

void imprimirMasPagina(tbiblioteca *miBiblioteca);
void imprimirAutor(tbiblioteca *miBiblioteca);

int main() {
    biblioteca.total = 0;
    int opcion;
    int opcionGenero;
    int opcionLibroDisponible;

    printf("elija una opcion:\n");
    printf("0. Salir\n");
    printf("1. ingresar\n");

    while (true) {
        scanf("%d", &opcion);

        if (opcion == 0 || opcion == 1) {
            break;
        } else {
            printf("opcion no valida\n");
            printf("elija una opcion:\n");
            printf("0. Salir\n");
            printf("1. ingresar\n");
        }
    }

    if (opcion == 1) {
        while (opcion == 1 && biblioteca.total < MAX_BIBLIOTECA) {
            printf("ingrese el nombre del titulo\n");
            scanf(" %[^\n]s", biblioteca.libros[biblioteca.total].titulo.nombre, (unsigned int)MAX);
            
            printf("ingrese el codigo del libro\n");
            scanf(" %s", biblioteca.libros[biblioteca.total].codigo, (unsigned int)14);
            
            printf("ingrese el nombre del autor\n");
            scanf(" %[^\n]s", biblioteca.libros[biblioteca.total].nombreAutor.nombre, (unsigned int)MAX);
            
            printf("ingrese el apellido del autor\n");
            scanf(" %[^\n]s", biblioteca.libros[biblioteca.total].apellidoAutor.nombre, (unsigned int)MAX);
            
            printf("ingrese el genero del libro \n");
            printf("0. NOVELA\n");
            printf("1. ENSAYO\n");
            printf("2. POESIA\n");
            printf("3. TECNICO\n");
            printf("4. INFANTIL\n");
            scanf(" %d", &opcionGenero);
            
            if (opcionGenero >= 0 && opcionGenero <= 4) {
                biblioteca.libros[biblioteca.total].genero = (tgenero)opcionGenero;
            } else {
                printf("genero no valido, se asignara por defecto NOVELA\n");
                biblioteca.libros[biblioteca.total].genero = NOVELA;
            }

            printf("ingrese el numero de paginas del libro\n");
            scanf(" %d", &biblioteca.libros[biblioteca.total].numeroPaginas);
            
            printf("ingrese el año de publicacion del libro\n");
            scanf(" %d", &biblioteca.libros[biblioteca.total].yearPublicacion);
            
            printf("ingrese el numero de ejemplares del libro\n");
            scanf(" %d", &biblioteca.libros[biblioteca.total].numeroDeEjemplares);
            
            printf("ingrese si el libro esta disponible (1 para si, 0 para no)\n");
            scanf(" %d", &opcionLibroDisponible);

            if (opcionLibroDisponible == 1) {
                biblioteca.libros[biblioteca.total].disponible = true;
            } else if (opcionLibroDisponible == 0) {
                biblioteca.libros[biblioteca.total].disponible = false;
            } else {
                printf("opcion no valida, se asignara por defecto no disponible\n");
                biblioteca.libros[biblioteca.total].disponible = false;
            }

            biblioteca.total++;

            printf("elija una opcion:\n");
            printf("0. Salir\n");
            printf("1. continuar\n");
            
            while (true) {
                scanf("%d", &opcion);
                if (opcion == 0 || opcion == 1) {
                    break;
                } else {
                    printf("opcion no valida\n");
                    printf("elija una opcion:\n");
                    printf("0. Salir\n");
                    printf("1. ingresar\n");
                }
            }
        }

        for (int i = 0; i < biblioteca.total; i++) {
            printf("los libros ingresados son: %d. %s\n", i + 1, biblioteca.libros[i].titulo.nombre);
        }
    }

    if (biblioteca.total > 0) {
        imprimirMasPagina(&biblioteca);
        imprimirAutor(&biblioteca);
    }

    printf("programa finalizado\n");
    return 0;
}

void imprimirMasPagina(tbiblioteca *miBiblioteca) {
    int mayorPaginas = miBiblioteca->libros[0].numeroPaginas;
    int libroPaginas = 0;

    for (int i = 0; i < miBiblioteca->total; i++) {
        if (miBiblioteca->libros[i].numeroPaginas > mayorPaginas) {
            mayorPaginas = miBiblioteca->libros[i].numeroPaginas;
            libroPaginas = i;
        }
    }
    printf("el libro con mas paginas es: %s con %d paginas\n", miBiblioteca->libros[libroPaginas].titulo.nombre, mayorPaginas);
}

void imprimirAutor(tbiblioteca *miBiblioteca) {
    int contadorNOVELA = 0;
    int contadorENSAYO = 0;
    int contadorPOESIA = 0;
    int contadorTECNICO = 0;
    int contadorINFANTIL = 0;
    int opcion;

    for (int i = 0; i < miBiblioteca->total; i++) {
        switch (miBiblioteca->libros[i].genero) {
        case 0:
            miBiblioteca->generosLibros[contadorNOVELA].NOVELA.tituloCopia = miBiblioteca->libros[i].titulo;
            miBiblioteca->generosLibros[contadorNOVELA].NOVELA.nombreCopia = miBiblioteca->libros[i].nombreAutor;
            miBiblioteca->generosLibros[contadorNOVELA].NOVELA.apellidoCopia = miBiblioteca->libros[i].apellidoAutor;
            contadorNOVELA++;
            break;

        case 1:
            miBiblioteca->generosLibros[contadorENSAYO].ENSAYO.tituloCopia = miBiblioteca->libros[i].titulo;
            miBiblioteca->generosLibros[contadorENSAYO].ENSAYO.nombreCopia = miBiblioteca->libros[i].nombreAutor;
            miBiblioteca->generosLibros[contadorENSAYO].ENSAYO.apellidoCopia = miBiblioteca->libros[i].apellidoAutor;
            contadorENSAYO++;
            break;
        
        case 2: 
            miBiblioteca->generosLibros[contadorPOESIA].POESIA.tituloCopia = miBiblioteca->libros[i].titulo;
            miBiblioteca->generosLibros[contadorPOESIA].POESIA.nombreCopia = miBiblioteca->libros[i].nombreAutor;
            miBiblioteca->generosLibros[contadorPOESIA].POESIA.apellidoCopia = miBiblioteca->libros[i].apellidoAutor;
            contadorPOESIA++;
            break;
        
        case 3:
            miBiblioteca->generosLibros[contadorTECNICO].TECNICO.tituloCopia = miBiblioteca->libros[i].titulo;
            miBiblioteca->generosLibros[contadorTECNICO].TECNICO.nombreCopia = miBiblioteca->libros[i].nombreAutor;
            miBiblioteca->generosLibros[contadorTECNICO].TECNICO.apellidoCopia = miBiblioteca->libros[i].apellidoAutor;
            contadorTECNICO++;
            break;

        case 4:
            
            miBiblioteca->generosLibros[contadorINFANTIL].INFANTIL.tituloCopia = miBiblioteca->libros[i].titulo;
            miBiblioteca->generosLibros[contadorINFANTIL].INFANTIL.nombreCopia = miBiblioteca->libros[i].nombreAutor;
            miBiblioteca->generosLibros[contadorINFANTIL].INFANTIL.apellidoCopia = miBiblioteca->libros[i].apellidoAutor;
            contadorINFANTIL++;
            break;

        default:
            break;
        }
    }

    printf("\nHay %d libros guardados y estan dividos por generos:\n", miBiblioteca->total);
    printf("1.NOVELA: %d\n", contadorNOVELA);
    printf("2.ENSAYO: %d\n", contadorENSAYO);
    printf("3.POESIA: %d\n", contadorPOESIA);
    printf("4.TECNICO: %d\n" , contadorTECNICO);
    printf("5.INFANTIL: %d\n", contadorINFANTIL);
    printf("Ingrese un numero para ver los libros por su categoria valida:\n");
    scanf("%d", &opcion);

    if (opcion >= 1 && opcion <= 5) {
        switch (opcion) {
        case 1:
            if (contadorNOVELA > 0) {
                for (int i = 0; i < contadorNOVELA; i++) {
                    
                    printf("%d.obra: %s\n", i+1, miBiblioteca->generosLibros[i].NOVELA.tituloCopia.nombre);
                    printf("nombre: %s %s\n", miBiblioteca->generosLibros[i].NOVELA.nombreCopia.nombre, miBiblioteca->generosLibros[i].NOVELA.apellidoCopia.nombre);
                }
            }
            break;
        case 2:
            if (contadorENSAYO > 0) {
                for (int i = 0; i < contadorENSAYO; i++) {
                    printf("%d.obra: %s\n", i+1, miBiblioteca->generosLibros[i].ENSAYO.tituloCopia.nombre);
                    printf("nombre: %s %s\n", miBiblioteca->generosLibros[i].ENSAYO.nombreCopia.nombre, miBiblioteca->generosLibros[i].ENSAYO.apellidoCopia.nombre);
                }       
            }
            break;
        case 3:
            if (contadorPOESIA > 0) {
                for (int i = 0; i < contadorPOESIA; i++) {
                    printf("%d.obra: %s\n", i+1, miBiblioteca->generosLibros[i].POESIA.tituloCopia.nombre);
                    printf("nombre: %s %s\n", miBiblioteca->generosLibros[i].POESIA.nombreCopia.nombre, miBiblioteca->generosLibros[i].POESIA.apellidoCopia.nombre);
                }       
            }
            break;
        case 4:
            if (contadorTECNICO > 0) {
                for (int i = 0; i < contadorTECNICO; i++) {
                    
                    printf("%d.obra: %s\n", i+1, miBiblioteca->generosLibros[i].TECNICO.tituloCopia.nombre);
                    printf("nombre: %s %s\n", miBiblioteca->generosLibros[i].TECNICO.nombreCopia.nombre, miBiblioteca->generosLibros[i].TECNICO.apellidoCopia.nombre);
                }       
            }
            break;
        case 5:
            if (contadorINFANTIL > 0) {
                for (int i = 0; i < contadorINFANTIL; i++) {
                    printf("%d.obra: %s\n", i+1, miBiblioteca->generosLibros[i].INFANTIL.tituloCopia.nombre);
                    printf("nombre: %s %s\n", miBiblioteca->generosLibros[i].INFANTIL.nombreCopia.nombre, miBiblioteca->generosLibros[i].INFANTIL.apellidoCopia.nombre);
                }       
            }
            break;
        default:
            break;
        }
    } else {
        printf("opcion no valida\n");
    }
}