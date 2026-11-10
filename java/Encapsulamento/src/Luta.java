
import java.util.Random;

public class Luta {
    private Lutador desafiado;
    private Lutador desafiante;
    private int rounds;
    private boolean aprovada;

    public void marcarLuta(Lutador  l1, Lutador l2, int r){
        if(l1.getCategoria().equals(l2.getCategoria()) && l1 != l2 && r > 0){
            this.aprovada = true;
            this.setRounds(r);
            this.desafiado = l1;
            this.desafiante = l2;
        }else{
            this.aprovada = false;
            this.desafiado = null;
            this.desafiante = null;
        }
    }
    public void lutar(){
        if(this.aprovada){
            System.out.println(">>>DESAFIAOD<<<");
            this.desafiado.apresentar();
            System.out.println(">>>DESAFIANTE<<<");
            this.desafiante.apresentar();
            for(int i = 0; i < this.getRounds(); i++){
                Random aleat = new Random();
                int vencedor = aleat.nextInt(3);
                switch(vencedor){
                    case 0 -> {
                        //Empate
                        this.desafiado.setEmpates(this.desafiado.getEmpates() +1);
                        this.desafiante.setEmpates(this.desafiante.getEmpates() +1);
                    }
                    case 1 -> {
                        //Desafiado vence
                        this.desafiado.setVitorias(this.desafiado.getVitorias() +1);
                        this.desafiante.setDerrotas(this.desafiante.getDerrotas() +1);
                    }
                    case 2 -> {
                        //Desafiante vence
                        this.desafiante.setVitorias(this.desafiante.getVitorias() +1);
                        this.desafiado.setDerrotas(this.desafiado.getDerrotas() +1);
                    }
                }   
            }
        }else{
            System.out.println(">>LUTA NÃO APROVADA<<");
        }
    }

    public int getRounds() {
        return rounds;
    }

    public void setRounds(int rounds) {
        this.rounds = rounds;
    }
}
