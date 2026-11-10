package mylib;

public class Aula02 {
    public static void main(String[] args) throws Exception {
        Caneta c1 = new Caneta();
        c1.cor = "verde";
        c1.carga = 100;
        c1.status();
        c1.escolherPonta(0.5);
        
    }
}
