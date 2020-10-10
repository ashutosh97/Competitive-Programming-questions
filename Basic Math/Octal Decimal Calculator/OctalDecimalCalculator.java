import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OctalDecimalCalculator {

    private static int BASE_8 = 8;
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final String RESULT_TEMPLATE = "The decimal number for octal %s is: %s";

    public static void main(String[] args){

        System.out.println("Please input octal number to convert");
        try {
            String octal = br.readLine();
            String decimal = convertOctalToDecimal(Integer.parseInt(octal));

            System.out.println(String.format(RESULT_TEMPLATE, octal, decimal));
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static String convertOctalToDecimal(int octal){
        int result = 0;
        String tmp =  String.valueOf(octal);
        int count = 0;
        int multiple;
        String caracter;
        for (int i = tmp.length(); i > 0; i--) {
            caracter = tmp.substring(i-1, i);
            multiple = (int) Math.pow(BASE_8, count);
            int value = (Integer.parseInt(caracter) * multiple);
            count = count + 1;
            result += value;

        }

        return String.valueOf(result);
    }

}
