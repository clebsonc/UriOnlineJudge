public abstract class TwoOperands{
    private int a, b;

    public TwoOperands(){}
    public TwoOperands(int a, int b){
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

    @Override
    public String toString(){
        return String.format("A = %d \tB = %d", this.a, this.b);
    }
}
