import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.NumberFormatException;
import java.util.ArrayList;


class Main{
    private int start, end;
    public Main(){}
    public Main(int start, int end){
        this.start = start < end? start : end;
        this.end = end > start ? end : start;
    }
    
    public int getStart(){
        return this.start;
    }
    public int getEnd(){
        return this.end;
    }

    @Override
    public String toString(){
        return String.format(this.start + " " + this.end);
    }
    
    public static void main(String[] args) throws IOException, NumberFormatException{
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Main> list = new ArrayList<Main>();
        int quantity = Integer.parseInt(buffer.readLine());
        for(int i = 0; i < quantity; i++){
            String[] data = buffer.readLine().split(" ");
            list.add(new Main(Integer.parseInt(data[0]), Integer.parseInt(data[1])));
        }
        for(Main a : list){
            int sum = 0;
            for(int i = a.getStart()+1; i<a.getEnd(); i++){
                if(i%2 != 0){
                    sum += i;
                }
            }
            System.out.println(sum);
        }
    }
}
