import java.util.Scanner;
public class clases {

    private double matematica;
    private double ingles;
    private double programacion;
    private double sistemasInformaticos;
    private double basesDeDatos;
    private final double notaAprobado= 5.0;
    String notaFinal;



    public void ingresaNotas(Scanner scanner){

        System.out.println("ingrese la nota de matematicas del 1 al 10 de matematicas : ");
        this.matematica = scanner.nextDouble();
        System.out.println("ingrese la nota de ingles del 1 al 10 de ingles : ");
        this.ingles = scanner.nextDouble();
        System.out.println("ingrese la nota de programcion del 1 al 10 de programacion : ");
        programacion = scanner.nextDouble();
        System.out.println("ingrese la nota de sistemas informatico del 1 al 10 de sistemasInformaticos : ");
        sistemasInformaticos = scanner.nextDouble();
        System.out.println("ingrese la notabases de datos del 1 al 10 de basesDeDatos : ");
        basesDeDatos = scanner.nextDouble();

    }

    public void imprimir(){

        notaFinal = matematica >= this.notaAprobado? "la nota es " + this.matematica + " y es aprobado": "la nota " + this.matematica + " nota reprobrada";
        System.out.println(notaFinal);

        notaFinal = ingles >= this.notaAprobado? "la nota es " + this.ingles + " y es aprobado": "la nota " + this.ingles + " nota reprobrada";
        System.out.println(notaFinal);

        notaFinal = programacion >= this.notaAprobado? "la nota es " + this.programacion + " y es aprobado": "la nota " + this.programacion + " nota reprobrada";
        System.out.println(notaFinal);

        notaFinal = sistemasInformaticos >= this.notaAprobado? "la nota es " + this.sistemasInformaticos + " y es aprobado": "la nota " + this.sistemasInformaticos + " nota reprobrada";
        System.out.println(notaFinal);

        notaFinal = basesDeDatos >= this.notaAprobado? "la nota es " + this.ingles + " y es aprobado": "la nota " + this.basesDeDatos + " nota reprobrada";
        System.out.println(notaFinal);

    }

}
