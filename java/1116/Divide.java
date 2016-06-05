public class Divide extends TwoOperands{
    public Divide(int a, int b){
        super(a, b);
    }

    public void printDivision(){
        if(super.getB() == 0)
            System.out.println("divisao impossivel");
        else{
            System.out.printf("%.1f\n",((float)super.getA() / super.getB()));
        }
    }
}
