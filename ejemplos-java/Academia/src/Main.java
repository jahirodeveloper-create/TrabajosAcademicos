import java.util.ArrayList;
import java.util.Scanner;

public class Main{

    public static void main (String[] args){

        Scanner scanner = new Scanner(System.in);
        ArrayList<Alumno> alumnos = new ArrayList<>();

        int opcion;

        while(true){
            Alumno alumno = new Alumno();
            alumno.ingresarAlumno(scanner);
            alumnos.add(alumno);

            System.out.println("ingrese 1 para continuar con otro estudiante o 0 para finalizar");
            opcion= scanner.nextInt();
            scanner.nextLine();

            if (opcion == 0){

                break;
            }

        }

        for (Alumno imprimir: alumnos){

            imprimir.imprimir();
        }

        System.out.println("programa finalizado");

        scanner.close();


    }
}
