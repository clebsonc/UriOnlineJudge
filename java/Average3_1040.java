import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.lang.NullPointerException;
import java.lang.NumberFormatException;
import java.util.regex.Pattern;

class Main{
    private double s1, s2, s3, s4, fin_exam;
    private int w1, w2, w3, w4;
    
    /* Constructors */
    Main(){
        this.s1 = this.s2 = this.s3 = this.s4 = this.fin_exam = 0.0;
        this.w1 = 2;
        this.w2 = 3; 
        this.w3 = 4; 
        this.w4 = 1;
        this.fin_exam = 0.0;
    } 
    Main(double s1, double s2, double s3, double s4, int w1, int w2, int w3, int w4){
        this.setS1(s1);
        this.setS2(s2);
        this.setS3(s3);
        this.setS4(s4);
        this.setW1(w1);
        this.setW2(w2);
        this.setW3(w3);
        this.setW4(w4);
        this.fin_exam = 0.0;
    }
    
    public void setS1(double s){
        this.s1 = (s >= 0.0 ? s : 0.0);
    }
    public void setS2(double s){
        this.s2 = (s >= 0.0 ? s : 0.0);
    }
    public void setS3(double s){
        this.s3 = (s >= 0.0 ? s : 0.0);
    }
    public void setS4(double s){
        this.s4 = (s >= 0.0 ? s : 0.0);
    }

    public void setW1(int w){
        this.w1 = (w >= 0 ? w : 0);
    }
    public void setW2(int w){
        this.w2 = (w >= 0 ? w : 0);
    }
    public void setW3(int w){
        this.w3 = (w >= 0 ? w : 0);
    }
    public void setW4(int w){
        this.w4 = (w >= 0 ? w : 0);
    }
    public void setFinExam(double fin){
        this.fin_exam = (fin >= 0 ? fin : 0);
    }
    
    public double getS1(){
        return this.s1;
    }
    public double getS2(){
        return this.s2;
    }
    public double getS3(){
        return this.s3;
    }
    public double getS4(){
        return this.s4;
    }

    public int getW1(){
        return this.w1;
    }
    public int getW2(){
        return this.w2;
    }
    public int getW3(){
        return this.w3;
    }
    public int getW4(){
        return this.w4;
    }
    public double getFinExam(){
        return this.fin_exam;
    }

    public double getAverage(){
        return (this.s1 * this.w1 + this.s2 * this.w2 + this.s3 * this.w3 + this.s4 * this.w4) / (this.w1 + this.w2 + this.w3 + this.w4);
    }

    public double getFinalAverage(){
        return (this.getAverage()+this.getFinExam())/2;
    }

    public void studentSituation(double grade) throws IOException{
        if(grade < 5.0)
            System.out.println("Aluno reprovado.");
        else if (grade < 7.0){
            System.out.println("Aluno em exame.");
            BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
            try{
                this.setFinExam(Double.parseDouble(buffer.readLine()));
                System.out.println("Nota do exame: "+Math.floor(this.getFinExam()*10)/10);
                if(this.getFinalAverage() < 5)
                    System.out.println("Aluno reprovado.");
                else
                    System.out.println("Aluno aprovado.");
                System.out.println("Media final: "+Math.floor(this.getFinalAverage()*10)/10);
            } catch(NumberFormatException nfe){
                System.out.println("Error nfe" + nfe.getMessage());
            } catch(NullPointerException npe){
                System.out.println("Error npe: " + npe.getMessage());
            }
        }
        else
            System.out.println("Aluno aprovado.");
    }
    
    @Override
    public String toString(){
        return ("Grade 1: "+ this.s1 +"\nGrade 2: " +this.s2 +"\nGrade 3: "+this.s3+"\nGrade 4: "+ this.s4);
    }


    //Main Function
    public static void main(String[] args) throws IOException{
        Main exams = new Main();
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        try{
            String str = buffer.readLine();
            exams.setS1(Double.parseDouble(str.split(" ")[0]));
            exams.setS2(Double.parseDouble(str.split(" ")[1]));
            exams.setS3(Double.parseDouble(str.split(" ")[2]));
            exams.setS4(Double.parseDouble(str.split(" ")[3]));
            System.out.println("Media: " + Math.floor(exams.getAverage()*10)/10);            
            exams.studentSituation(exams.getAverage());
        } catch(NumberFormatException nfe){
            System.out.println("Error nfe" + nfe.getMessage());
        } catch(NullPointerException npe){
            System.out.println("Error npe: " + npe.getMessage());
        }
    }
}
