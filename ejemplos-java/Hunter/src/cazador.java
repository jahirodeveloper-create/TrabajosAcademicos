import java.util.ArrayList;
import java.util.Scanner;
public class cazador {

    private String nombreCazador;

    private ArrayList<animalesCazados> listaAnimales = new ArrayList<>();


    public boolean opcion(Scanner scanner){

        boolean verdadero;
        int opcion;
        System.out.println("ingrese 1 para continuar o 0 para finalizar");
        opcion = scanner.nextInt();
        scanner.nextLine();
        if (opcion == 1){

            verdadero = true;
        }else{

            verdadero = false;
        }

        return verdadero;
    }


    public void ingresarDatos(Scanner scanner){

        boolean resultado;

        System.out.println("ingrese el nombre del cazador");

        nombreCazador = scanner.nextLine();

        while(true) {

            animalesCazados animalesCazados = new animalesCazados();

            animalesCazados.ingresarDatos(scanner);

            listaAnimales.add(animalesCazados);

            resultado = opcion(scanner);

            if (resultado){

                System.out.println("ingrese el nuevo animal: ");
            }else{

                break;
            }


        }

    }

    public void imprimirCazador (){

        System.out.println("el nombre del cazador es: " + nombreCazador);

        for(int i = 0 ; i < listaAnimales.size(); i++){

            listaAnimales.get(i).imprimirResultados();
        }
    }

}




