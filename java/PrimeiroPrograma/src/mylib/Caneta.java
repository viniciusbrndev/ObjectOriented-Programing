package mylib;

public class Caneta{
    public String modelo;
    public String cor;
    private float ponta;
    protected int carga;
    private boolean tampada;

    public void status(){
        System.out.println("Modelo: " + this.modelo);
        System.out.println("Uma caneta " + this.cor );
        System.out.println("Está tampada? " + this.tampada);
        System.out.println("Carga: " + this.carga);
    }

    public String getModelo(){
        return this.modelo;
    }
    public void setModelo(String m){
        this.modelo = m;
    }
    public float getPonta(){
        return this.ponta;
    }
    public void setPonta(float m){
        this.ponta = m;
    }
    
    protected void escolherPonta(double tam){
        this.ponta = (float) tam;
    }
    public void tampar(){
        if(this.tampada == true)
            System.out.println("A caneta já está tampada");
        else
            this.tampada = true;
    }

    public  void destampar(){
        if(this.tampada == false)
            System.out.println("A caneta já está destampada");
        else
            this.tampada = false;
    }
    public void escrever(){
        if(this.tampada == true)
            System.out.println("ERRO a caneta está tampada!");
        else
            System.out.println("Escrevendo...");
    }   
}