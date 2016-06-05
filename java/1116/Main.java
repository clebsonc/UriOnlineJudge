import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

class Main{
    public static void main(String[] args) throws IOException{
        ArrayList<Divide> data = new ArrayList<Divide>();
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(buffer.readLine().trim());
        for(int i=0; i < n; i++){
            String[] values = buffer.readLine().split(" ");
            data.add(new Divide(Integer.parseInt(values[0]), Integer.parseInt(values[1])));
        }

        for(Divide s : data){
            s.printDivision();
        }
    }
}
