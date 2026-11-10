public final class Lutador implements Disputa{
    private String nome;
    private String country;
    private int idade;
    private float altura;
    private float peso;
    private String categoria;
    private int vitorias;
    private int derrotas;
    private int empates;
    
    public void setPeso(float peso){
        this.peso = peso;
        this.setCategoria();
    }
    public float getPeso(){
        return this.peso;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getCountry() {
        return country;
    }
    public void setCountry(String country) {
        this.country = country;
    }
    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public float getAltura() {
        return altura;
    }
    public void setAltura(float altura) {
        this.altura = altura;
    }
    public String getCategoria() {
        return categoria;
    }
    public void setCategoria() {
        float ppeso= this.getPeso();
        if(ppeso <= 70)
            this.categoria = "Pena";
        else if(ppeso <= 90)
            this.categoria = "Médio";
        else
            this.categoria = "Pesado";
    }
    public int getVitorias() {
        return vitorias;
    }
    public void setVitorias(int vitorias) {
        this.vitorias = vitorias;
    }
    public int getDerrotas() {
        return derrotas;
    }
    public void setDerrotas(int derrotas) {
        this.derrotas = derrotas;
    }
    public int getEmpates() {
        return empates;
    }
    public void setEmpates(int empates) {
        this.empates = empates;
    }
    // Métodos 
    public Lutador(String name, String pais, float pe, int years, int vic, int der,int emp){
        this.setNome(name);
        this.setCountry(pais);
        this.setPeso(pe);
        this.setIdade(years);
        this.setAltura(0f);
        this.setVitorias(vic);
        this.setEmpates(emp);
        this.setDerrotas(der);
        // categoria já é ajustada em setPeso
    }
    public void apresentar(){
        System.out.println("Nome: " + this.getNome());
        System.out.println("Altura: " + this.getAltura());
        System.out.println("Idade: " + this.getIdade());
        System.out.println("Nacionalidade: " + this.getCountry());
    }
}
