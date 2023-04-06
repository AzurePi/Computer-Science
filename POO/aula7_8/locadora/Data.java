package aula7_8.locadora;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    //getters & setters ------------------------------
    public int getDia(){
        return dia;
    }

    public int getMes(){
        return mes;
    }

    public int getAno(){
        return ano;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    // métodos -------------------------------------
    public int periodo(Data fim){
        int p = 0;

        p += Math.abs(fim.getAno() - this.ano) * 365;
        p += Math.abs(fim.mes - this.mes) * 30;
        p += Math.abs(fim.dia - this.dia);

        return p;
    }



}
