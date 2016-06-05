import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.lang.NullPointerException;

class Main{
    private int ca, cb;

    Main(){};
    Main(int a, int b){
        this.ca = a;
        this.cb = b;
    }
    
    public int getCa(){
        return this.ca;
    }
    
    public int getCb(){
        return this.cb;
    }

    public void printQuadrante(){
        if(this.ca > 0 && this.cb > 0)
            System.out.println("primeiro");
        else if(this.ca > 0 && this.cb < 0)
            System.out.println("quarto");
        else if(this.ca < 0 && this.cb > 0)
            System.out.println("segundo");
        else if(this.ca  < 0 && cb < 0)
            System.out.println("terceiro");
    }

    public static String[] getData() throws NullPointerException{
        String[] data = null;
        try{
            BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
            data = buffer.readLine().split(" ");
        } catch(IOException ioe){
            System.err.println("Error occurred: "+  ioe.getMessage());
        }
        return data;
    }

    public static void main(String[] args) throws IOException, NullPointerException{
        int a, b;
        do{
            String [] data = getData();
            a = Integer.parseInt(data[0]);
            b = Integer.parseInt(data[1]);
            Main m = new Main(a, b);
            m.printQuadrante();
            }while(a != 0 && b != 0);
    }
}
