public class ControleRemoto implements Controlador {
    // Atributos
    private int volume;
    private boolean ligado;
    private boolean tocando;

    public ControleRemoto() {
        this.ligado = false;
        this.volume = 50;
        this.tocando = false;
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public boolean isLigado() {
        return ligado;
    }

    public void setLigado(boolean ligado) {
        this.ligado = ligado;
    }

    public boolean isTocando() {
        return tocando;
    }

    public void setTocando(boolean tocando) {
        this.tocando = tocando;
    }

    @Override
    public void abrirMenu() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void desliga() {
        if(this.isLigado())
            this.setLigado(false);
    }

    @Override
    public void desligarMudo() {
        if(this.isLigado() && this.getVolume() == 0)
            this.setVolume(50);
    }

    @Override
    public void fechaMenu() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void ligar() {
        if(this.isLigado() != true)
            this.setLigado(true);
    }

    @Override
    public void ligarMudo() {
        if(this.isLigado() && this.getVolume() != 0)
            setVolume(0);
    }

    @Override
    public void maisVolume() {
        if(this.getVolume() < 100 && this.isLigado()){
            this.setVolume(this.getVolume() +5);
        }
        
    }

    @Override
    public void menosVolume() {
        if(this.getVolume() > 0 && this.isLigado()){
            this.setVolume(this.getVolume() -5);
        }
    }

    @Override
    public void pause() {
        if(this.isLigado() && this.isTocando()){
            setTocando(false);
        }
    }

    @Override
    public void play() {
        if(this.isLigado() && this.isTocando() == false){
            this.setTocando(true);
        }
    }
    
    
}