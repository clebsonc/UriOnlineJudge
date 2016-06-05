import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

class Main{
    private int a, b;

    public Main(){}
    public Main(int a, int b){
        this.a = a;
        this.b = b;
    }

    public int getA(){
        return this.a;
    }
    public int getB(){
        return this.b;
    }
    public void setA(int a){
        this.a = a;
    }
    public void setB(int b){
        this.b = b;
    }
    
    public void printDivision(){
        if(this.getB() == 0)
            System.out.println("divisao impossivel");
        else{
            System.out.printf("%.1f\n",((float)this.getA() / this.getB()));
        }
    }

    @Override
    public String toString(){
        return String.format("A = %d \tB = %d", this.a, this.b);
    }

    public static void main(String[] args) throws IOException{
        ArrayList<Main> data = new ArrayList<Main>();
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(buffer.readLine().trim());
        for(int i=0; i < n; i++){
            String[] values = buffer.readLine().split(" ");
            data.add(new Main(Integer.parseInt(values[0]), Integer.parseInt(values[1])));
        }

        for(Main s : data){
            s.printDivision();
        }
    }
}