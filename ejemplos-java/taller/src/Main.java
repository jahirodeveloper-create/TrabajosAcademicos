import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        ArrayList<coche> listaCoche = new ArrayList<>();

        String opcion = "";
        String opcion2 = "";
        String opcion3 = "";
        int numClientes;

        System.out.println("bienvenido al taller bruhl eliga una opcion \n 1. ingresar coche \n 2. salir");
        opcion = scanner.nextLine();

        if ("1".equals(opcion)) {
            while (true) {

                coche coche = new coche();
                coche.ingresarDatos(scanner);
                listaCoche.add(coche);

                System.out.println("ingrese 1 para continuar o 2 para finalizar");
                opcion2 = scanner.nextLine();
                if ("2".equals(opcion2)) {
                    break;
                }
            }
        }

        if ("1".equals(opcion)){

            numClientes = listaCoche.size();
            System.out.println("la cantidad de clientes registrado son: " + numClientes);

            System.out.println("ingrese 1 para ver los clientes o  2 para finalizar: ");

            opcion3 = scanner.nextLine();

            if ("1".equals(opcion3)){

                for (coche coche: listaCoche ){

                    coche.imprimir();
                }
            }

        }

        System.out.println("programa finalizado");

        scanner.close();
    }
}
