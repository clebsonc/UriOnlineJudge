import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.lang.NumberFormatException;

class Main{
    private int start, end, smin, emin;
    
    //Constructors
    Main(){}
    Main(int start, int end, int smin, int emin){
        this.setStart(start);
        this.setEnd(end);
        this.setStartMin(smin);
        this.setEndMin(emin);
    }

    public void setStart(int start){
        this.start = (start >= 0 ? start : 0);
    }
    public void setEnd(int end){
        this.end = (end >= 0 ? end : 0);
    }
    public setStartMin(int smin){
        this.smin = (smin >=0 ? smin: 0);
    }
    public setEndMin(int emin){
        this.emin = (emin >=0 ? emin: 0);
    }
    public int getStart(){
        return this.start;
    }
    public int getEnd(){
        return this.end;
    }
    public int getEMin(){
        return this.emin;
    }
    public int getSMin(){
        return this.smin;
    }
    
    public int computeGameDuration(){
        if(this.getStart() < this.getEnd()){
            return this.getEnd() - this.getStart();
        }
        return 24 - this.getStart() + this.getEnd();
    }

    public int computeGameDurationMinutes(){
        if(this.getEMin() < this.getSMin()){
            return "O JOGO DUROU " + this.computeGameDuration() + "HORA(S) e "+(60 - this.getSMin() + this.getEMin()) + "MINUTO(S).";
        } else if(this.getEnd() < this.getStart){
            return "O JOGO DUROU " + this.computeGameDuration() + "HORA(S) e "+(this.getEMin() - this.getSMin()) + "MINUTO(S).";
        }
    }

    @Override
    public String toString(){
        return "Start: "+this.start +
        "\nEnd: "+this.end+
        "\nGameDuration: "+this.computeGameDuration();
    }

    public static void main(String[] args) throws IOException{
        Main game1 = new Main();
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        String[] string =  buffer.readLine().split(" ");
        try{
            game1.setStart(Integer.parseInt(string[0]));
            game1.setStartMin(Integer.parseInt(string[1]));
            game1.setEnd(Integer.parseInt(string[2]));
            game1.setEndMin(Integer.parseInt(string[3]));
        }catch(NumberFormatException nfe){
            System.err.println("Number Format is wrong, it must be an integer. "+nfe);
            System.exit(1);
        }
        System.out.println("O JOGO DUROU "+game1.computeGameDuration()+ " HORA(S)");
    }
}
