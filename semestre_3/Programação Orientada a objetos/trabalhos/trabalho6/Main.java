package trabalhos.trabalho6;

public class Main {
    public static void main(String[] args) {

        Circulo circulo = new Circulo("Vermelho", true, 5);
        Quadrado quadrado = new Quadrado("Azul", false, 4);
        Retangulo retangulo = new Retangulo("Verde", true, 3, 6);

        // testa circulo
        System.out.println(circulo);
        System.out.println("Área: " + String.format("%.2f", circulo.getArea()));
        System.out.println("Perímetro: " + String.format("%.2f", circulo.getPerimetro()));

        // testa quadrado
        System.out.println(quadrado);
        System.out.println("Área: " + quadrado.getArea());
        System.out.println("Perímetro: " + quadrado.getPerimetro());

        // testa retangulo
        System.out.println(retangulo);
        System.out.println("Área: " + retangulo.getArea());
        System.out.println("Perímetro: " + retangulo.getPerimetro());
    }
}