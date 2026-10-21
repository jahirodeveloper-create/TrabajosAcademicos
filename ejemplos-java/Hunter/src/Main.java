import java.util.ArrayList;
import java.util.Scanner;

public class Main{

    public static boolean opcionMain(Scanner scanner){

        boolean opcion1;
        int bole;

        System.out.println("ingrese 1 para continuar con otro cazador o 0 para finalizar");
        bole = scanner.nextInt();
        scanner.nextLine();

        if (bole == 1){

            opcion1 = true;
        }else{

            opcion1 = false;
        }
        return opcion1;
    }


    public static void main (String[] args){

        ArrayList<cazador> listaCaza = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        boolean resultado;

        System.out.println("ingrese los datos del cazador");

        while(true){

            cazador cazador = new cazador();

            cazador.ingresarDatos(scanner);

            listaCaza.add(cazador);

            resultado = opcionMain(scanner);

            if (resultado == false){

                break;
            }


        }

        for (int i = 0; i < listaCaza.size(); i++){

            listaCaza.get(i).imprimirCazador();
        }

        System.out.println("programa finalizado");

    }
}