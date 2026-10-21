import java.util.ArrayList;
import java.util.Scanner;
public class Alumno {

    private int idAlumno;
    private String nombre;


    ArrayList<clases> clases = new ArrayList<>();


    public boolean isOpcion(Scanner scanner){

        boolean resultado;
        int numero;

        System.out.println("ingrese 1 para continuar o 0 para finalizar");

        numero = scanner.nextInt();
        scanner.nextLine();

        if (numero == 0){

            resultado = true;
        }else{

            resultado = false;
        }

        return resultado;
    }


    public void ingresarAlumno(Scanner scanner){

        System.out.println("ingrese el id y nombre del alumno y la nota de cada materia");

        while (true){

            boolean resultado;

            System.out.println("ingrese el nombre: ");
            this.nombre = scanner.nextLine();

            System.out.println("ingrese el id: ");
            this.idAlumno = scanner.nextInt();
            scanner.nextLine();

            clases clases1 = new clases();

            clases1.ingresaNotas(scanner);

            clases.add(clases1);

            resultado = isOpcion(scanner);

            if (resultado){

                break;
            }
        }
    }

    public void imprimir(){

        System.out.println("el alumno: " + nombre);
        System.out.println("el id del alumno :" + idAlumno);

        System.out.println("y el resultado de las clases es: ");

        for(int i = 0 ; i < clases.size(); i++){

            clases.get(i).imprimir();
        }
    }
}
