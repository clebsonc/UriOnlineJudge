import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main{
    private final String password = "2002";
    
    public Main(){}

    public String getPassword(){
        return this.password;
    }
    
    public static void main(String[] args) throws IOException{
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        while(!buffer.readLine().equals(new Main().getPassword()))
            System.out.println("Senha Invalida");
        System.out.println("Acesso Permitido");
    }
}
