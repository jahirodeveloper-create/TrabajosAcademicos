import java.util.Scanner;

public class animalesCazados {

    private String nombreDeAnimal;
    private int clase;
    private int disparos;
    private String momentoDia;
    private int animalesCazados;

    public void ingresarDatos(Scanner scanner){

        System.out.println("ingrese el nombre del animal: ");
        this.nombreDeAnimal = scanner.nextLine();

        System.out.println("ingrese la clase del animal: ");
        this.clase = scanner.nextInt();

        System.out.println("cuantos disparon impactaron: ");
        this.disparos = scanner.nextInt();
        scanner.nextLine();

        System.out.println("ingrese momento del dia mañana, tarde, noche.");
        this.momentoDia= scanner.nextLine();

        animalesCazados++;
    }

    public void imprimirResultados(){

        System.out.println("los animales cazados son: ");

        if (animalesCazados > 0) {
            for (int i = 0; i < animalesCazados; i++) {
                System.out.println((i + 1) + ". " + nombreDeAnimal + " y su clase es " + clase + " y murio de " + disparos +" disparos y el momento del dia que fue casado " + momentoDia);
            }
        }
    }
}



