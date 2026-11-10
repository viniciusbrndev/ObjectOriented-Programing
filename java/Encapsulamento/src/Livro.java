public class Livro implements Publicacao{
    private String titulo;
    private String autor;
    private int numPags;
    private int pagAtual;
    private boolean aberto;
    private Pessoa leitor;

    public String getTitulo() {
        return titulo;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public String getAutor() {
        return autor;
    }
    public void setAutor(String autor) {
        this.autor = autor;
    }
    public int getNumPags() {
        return numPags;
    }
    public void setNumPags(int numPags) {
        this.numPags = numPags;
    }
    public int getPagAtual() {
        return pagAtual;
    }
    public void setPagAtual(int pagAtual) {
        this.pagAtual = pagAtual;
    }
    public boolean isAberto() {
        return aberto;
    }
    public void setAberto(boolean aberto) {
        this.aberto = aberto;
    }
    public Pessoa getLeitor() {
        return leitor;
    }
    public void setLeitor(Pessoa leitor) {
        this.leitor = leitor;
    }

    @Override
    public void abrir() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void fechar() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void felhear() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void avancarPag() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void voltarPag() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    


}
