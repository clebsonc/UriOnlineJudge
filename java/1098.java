class Main{
    public static void main(String[] args){
        for(double i = 0; i <= 2; i += 0.2){
            for(double j = 1; j <= 3; j++){
                System.out.printf("0.2");
                if(i == 0 || i == 1 || String.format("%.2f", i).endsWith("01")){
                    System.out.printf("I=%d J=%d\n", (int) i, (int) j);
                } else{
                    System.out.printf("I=%.1f J=%.1f\n",i, (j+i));
                }
            }
        }
    }
}
