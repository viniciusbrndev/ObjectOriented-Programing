public class Conta{
    public int numConta;
    private char tipo;
    protected String dono;
    protected double saldo;
    protected boolean status;

    public void setNumConta(int n){
        this.numConta = n;
    }
    public int getNumConta(){
        return this.numConta;
    }
    public void setTypeAcount(char type){
        this.tipo = type;
    }
    public char getTypeAcount(){
        return this.tipo;
    }
    public void setSaldo(double v){
        this.saldo = v;
    }
    public double getSaldo(){
        return this.saldo;
    }
    public void setDono(String dono){
        this.dono = dono;
    }
    public String getDono(){
        return this.dono;
    }
    public void setStatus(boolean st){
        this.status = st;
    }
    public boolean getStatus(){
        return this.status;
    }


    public Conta(){
        this.saldo = 0;
        this.status = false;
    }
    public boolean abirConta(char type) {
        if(getStatus())
            return false;
        this.setStatus(true);
        this.setTypeAcount(type);
        if(type == 'c')
            this.setSaldo(50);
        else
            this.setSaldo(150);
        return status;
    }
    public void fecharConta(){
        if(this.getSaldo() != 0){
            System.out.println("Não foi possível fechar a conta, saldo existente.");
        }
        else{
            setStatus(false);
            System.out.println("Conta fechada!");
        }
    }
    public void depositarNaConta(double value){
        if(this.getStatus()){
            this.setSaldo(this.getSaldo() + value);
        }
        else
            System.out.println("Não foi possível depositar na conta");
    }
    public void sacarDaConta(double value, double v){
        
    }
}
