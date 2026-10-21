import java.util.Scanner;
public class coche {

    private int numeroCliente;
    private String marcaCoche;
    private String colorCoche;
    private int añoCoche;
    private boolean seguro;


    public void ingresarDatos(Scanner scanner){

        String opcion = "";

        System.out.println("ingrese el numero del cliente: ");
        numeroCliente = scanner.nextInt();

        scanner.nextLine();

        System.out.println("ingrese la marca del coche: ");
        marcaCoche = scanner.nextLine();

        System.out.println("ingrese el color del coche: ");
        colorCoche = scanner.nextLine();

        System.out.println("ingrese el año del coche: ");
        añoCoche= scanner.nextInt();

        scanner.nextLine();

        System.out.println("tiene seguro ingrese si o no: ");
        opcion = scanner.nextLine().toLowerCase();

        if ("si".equals(opcion)){

            seguro = true;
        } else if ("no".equals(opcion)) {

            seguro = false;
        }else{

            System.out.println("opcion no valida no tiene seguro ");

            seguro = false;
        }
    }

    public void imprimir(){

        System.out.println("el cliente: " + numeroCliente);
        System.out.println("la marca del coche es: " + marcaCoche);
        System.out.println("el color del coche es: " + colorCoche);
        System.out.println("el año del coche es: " + añoCoche);
        System.out.println("tiene seguro: ");

        if (seguro){

            System.out.print("si\n");
        }else{

            System.out.println("no\n");
        }
    }
}
