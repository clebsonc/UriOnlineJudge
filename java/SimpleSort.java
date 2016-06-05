import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.NullPointerException;
import java.io.IOException;

class Main{
    public int[] simpleSort(int[] values){
        int max = values[0];
        for(int i = 0; i < values.length; i ++){
            for(int j = 0; j < values.length-1; j ++){
                if(values[j] > values[j+1]){
                    int temp = values[j+1];
                    values[j+1] = values[j];
                    values[j] = temp;
                }
            }
        }
        return values;
    } 


    public static void main(String[] args) throws IOException{
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        try{
            String[] string = buffer.readLine().split(" ");
            int[] values = new int [string.length];
            for(int i = 0; i < string.length; i++){
                values[i] = Integer.parseInt(string[i]);
            }
            int [] copy = new int[values.length];
            for( int i = 0; i < values.length; i ++){
                copy[i] = values[i];
            }
            for(int x:new Main().simpleSort(values))
                System.out.println(x);
            System.out.println();
            for(int x:copy)
                System.out.println(x);
        } catch(NullPointerException ioe){
            System.out.println("Error while parsing: " + ioe.getMessage());
            System.exit(1);
        }
    }
}
