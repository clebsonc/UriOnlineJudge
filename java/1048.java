import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.lang.NullPointerException;
import java.lang.NumberFormatException;
 
 
class Main{
    private double salary;
    public Main(){}
    public Main(double s){
        this.salary = s;
    }
 
    void setSalary(double s){
        this.salary = s;
    }
    double getSalary(double s){
        return this.salary;
    }
 
    void computeNewSalary(){
        double v;
        if(this.salary <= 400 && this.salary > 0){
            v = this.salary + this.salary * 0.15;
            System.out.println("Novo salario: "+ String.format("%.2f", v));
            System.out.println("Reajuste ganho: "+ String.format("%.2f", this.salary* 0.15));
            System.out.println("Em percentual: 15 %");
        } else if (this.salary >= 400.01 && this.salary <=800){
            v = this.salary+this.salary * 0.12;
            System.out.println("Novo salario: "+ String.format("%.2f", v));
            System.out.println("Reajuste ganho: "+ String.format("%.2f", this.salary* 0.12));
            System.out.println("Em percentual: 12 %");
        } else if (this.salary >= 800.01 && this.salary <= 1200){
            System.out.println("Novo salario: "+ 
                                String.format("%.2f", (this.salary + this.salary * 0.10)));
            System.out.println("Reajuste ganho: "+ 
                                String.format("%.2f", this.salary* 0.10));
            System.out.println("Em percentual: 10 %");
        } else if (this.salary >= 1200.01 && this.salary <= 2000){
            System.out.println("Novo salario: "+
                                String.format("%.2f", (this.salary + this.salary * 0.07)));
            System.out.println("Reajuste ganho: "+ String.format("%.2f",this.salary* 0.07));
            System.out.println("Em percentual: 7 %");
        } else if (this.salary > 2000){
            System.out.println("Novo salario: "+ 
                                String.format("%.2f",(this.salary + this.salary * 0.04)));
            System.out.println("Reajuste ganho: "+ String.format("%.2f", this.salary* 0.04));
            System.out.println("Em percentual: 4 %");
        }
    }
 
    public static void main(String[] args){
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        try{
            double salary = Double.parseDouble(buffer.readLine());
            Main m = new Main(salary);
            m.computeNewSalary();
        } catch(NullPointerException npe){
            System.err.println("The string is null, you should enter a double formated number.");
            System.err.println(npe.getMessage());
            System.exit(1);
        } catch(NumberFormatException nfe){                                                           
            System.err.println("The string doesn't contain a parsable document.");
            System.err.println(nfe.getMessage());
            System.exit(1);
        } catch(IOException ioe){
            System.err.println("Error in IO: "+ioe.getMessage());
        }
    }
}
