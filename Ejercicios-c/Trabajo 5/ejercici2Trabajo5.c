#include <stdio.h>
#define MAX_PACIENTE 100

typedef struct{
    char nombre[30];
    float coste_tratamiento;
    
}tpaciente;

typedef struct{
    tpaciente paciente[MAX_PACIENTE];
    int num_paciente;
}thospital; 

void inicializar_hospital(thospital *h);
int menu();
void introducir_paciente(thospital *h);
void listar_paciente(thospital h);
float calcular_media_coste(thospital *h);
void listar_superiore_media(thospital *h);

int main(){
    thospital h;
    int opcion;
    
    inicializar_hospital(&h);
    opcion = menu();

    while (opcion >= 1 && opcion <= 3)
    {
        if (opcion == 1)
        {
            introducir_paciente(&h);
        }
        if (opcion == 2)
        {
            listar_paciente(h);
        }
        if (opcion == 3)
        {
            listar_superiore_media(&h);
        }
        
        opcion = menu();
        
        
    }
    
    return 0;
}

void inicializar_hospital(thospital *h){

    h->num_paciente = 0;
    
}

int menu(){

    int op;
    printf("*********************************\n");
    printf("1. Nuevo Paciente: \n");
    printf("2. Listar Todos: \n");
    printf("3.Mostrar pacientes con coste superior a la media: \n");
    printf("4. Salir\n");
    scanf("%d", &op);
    return op;
}

void introducir_paciente(thospital *h){

    if (h->num_paciente < MAX_PACIENTE)
    {
        tpaciente nuevo_pac;
        printf("escribe el nombre del paciente: \n");
        scanf(" %29[^\n]" ,nuevo_pac.nombre);
        printf("Coste total de tratamiento: ");
        scanf("%f", &nuevo_pac.coste_tratamiento);

        h->paciente[h->num_paciente]= nuevo_pac;
        h->num_paciente = h->num_paciente +1;
    }else{

        printf("Error hospital lleno.");
    }
}

void listar_paciente(thospital h){

    int i;
    for ( i = 0; i < h.num_paciente; i++)
    {
        printf("%s, - coste: %.2f\n", h.paciente[i].nombre, h.paciente[i].coste_tratamiento);
    }
}

float calcular_media_coste(thospital *h){

    float suma = 0.0;
    int i;

    if (h->num_paciente > 0)
    {
        for ( i = 0; i < h->num_paciente; i++)
        {
            suma = suma + h->paciente[i].coste_tratamiento;
        }

        suma = suma / h->num_paciente;
        
        return suma;
    }else{

        return 0.0;
    }
}

void listar_superiore_media(thospital *h){

    float media;
    int i;
    media = calcular_media_coste(h);
    printf("la media de coste es: %.2f\n", media);
    printf("---pacientes por decimal de la media---\n");

    for ( i = 0; i < h->num_paciente; i++)
    {
        if (h->paciente[i].coste_tratamiento > media)
        {
            printf("%s, - %.2f\n", h->paciente[i].nombre, h->paciente[i].coste_tratamiento);
        }
        
    }

}