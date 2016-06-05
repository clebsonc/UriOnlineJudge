import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main{
    public static void main(String[] args){ 
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        try{
            double value = Float.parseFloat(buffer.readLine());
            if(value < 0 || value > 100.0)
                System.out.println("Fora de intervalo");
            else if(value <= 25)
                System.out.println("Intervalo [0,25]");
            else if(value <= 50)
                System.out.println("Intervalo (25,50]");
            else if(value <= 75)
                System.out.println("Intervalo (50,75]");
            else if(value <= 100)
                System.out.println("Intervalo (75,100]");
        }catch(IOException ioe){
            System.out.println(ioe);
        }
    }
}
