class PesoAltura {
    int peso;       //peso em quilogramas
    int altura;     //altura em centímetros
}

class EstruturaSimples {
    public static final int alturaMaxima = 225;
    public static void main(String[] args) {
        PesoAltura pessoa1 = new PesoAltura();
        pessoa1.peso = 80;
        pessoa1.altura= 185;

        System.out.print("Peso: " + pessoa1.peso + ", Altura " + pessoa1.altura + ". ");
        
        if(pessoa1.altura > alturaMaxima) System.out.println("Altura acima da máxima.");
        else System.out.println("Altura abaixo da máxima.");
    }
}
