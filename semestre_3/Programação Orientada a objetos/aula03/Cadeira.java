public class Cadeira {
    private String posicao;
    private boolean ocupado;

    public Cadeira(){
        ocupado = false;
        posicao = "Em pé";
    }

    public Cadeira(String p, boolean oc){
        posicao = p;
        ocupado = oc;
    }

    public void sentar(){
        if ( (!ocupado) && posicao.equals("Em pé"))
            ocupado = true;
    }
    public void levantar(){
        ocupado = false;
    }
    public void virar(){
        if (posicao.equals("Em pé")){
            posicao = "Invertida";
            ocupado = false;
        }
        else{
            posicao = "Em pé";
        }
    }
    public String getPosicao(){
        return posicao;
    }
}