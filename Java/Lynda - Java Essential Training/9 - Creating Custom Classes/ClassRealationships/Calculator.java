/**
 * Created by petru on 10-Sep-15.
 */


public class Calculator {

    public static void main(String[] args) {
        Calculator calc = new Calculator();
        calc.calculate();
    }


    // calculate is an instance method
    // must be called from an instance of the class instead of from
    // the class definition itself
    protected void calculate() {
        InputHelper helper = new InputHelper();
        String s1 = helper.getInput("Enter a numeric value: ");
        String s2 = helper.getInput("Enter a numeric value: ");
        String op = helper.getInput("Choose an operation (+ - * /): ");

        double result = 0;

        try {
            switch (op) {
                case "+":
                    result = MathHelper.addValues(s1, s2);
                    break;
                case "-":
                    result = MathHelper.substractValues(s1, s2);
                    break;
                case "*":
                    result = MathHelper.multiplyValues(s1, s2);
                    break;
                case "/":
                    result = MathHelper.divideValues(s1, s2);
                    break;
                default:
                    System.out.println("Unrecognized operation!");
                    return;
            }

            System.out.println(s1 + op + s2 + " = " + result);

        } catch (Exception e) {
            System.out.println("Number formatting exception "
                    + e.getMessage());
        }
    }

}
