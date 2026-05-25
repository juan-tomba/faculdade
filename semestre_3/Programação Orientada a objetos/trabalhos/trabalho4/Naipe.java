public enum Naipe {
    PAUS("♣"), COPAS("♥"), ESPADAS("♠"), OUROS("♦");

    private String simbolo;

    Naipe(String simbolo) {
        this.simbolo = simbolo;
    }

    public String getSimbolo() {
        return simbolo;
    }
}