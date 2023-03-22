// Java program to demonstrate
// the multiple inheritance
// in interface

// Interface to implement the
// addition and subtraction methods
interface Add_Sub {
    public void add(double x, double y);

    public void subtract(double x, double y);
}

// Interface to implement the
// multiplication and division
interface Mul_Div {
    public void multiply(double x, double y);

    public void divide(double x, double y);
}

// Calculator interface which extends
// both the above defined interfaces
interface Calculator extends Add_Sub, Mul_Div {
    public void printResult(double result);
}

// Calculator class which
// implements the above
// interface
public class pgm5 implements Calculator {

    // Implementing the addition
    // method
    public void add(double x, double y) {
        double result = x + y;
        printResult(result);
    }

    // Implementing the subtraction
    // method
    public void subtract(double x, double y) {
        double result = x - y;
        printResult(result);
    }

    // Implementing the multiplication
    // method
    public void multiply(double x, double y)

    {
        double result = x * y;
        printResult(result);
    }

    // Implementing the division
    // method
    public void divide(double x, double y) {
        double result = x / y;
        printResult(result);
    }

    // Implementing a method
    // to print the result
    public void printResult(double result) {
        System.out.println(
                "The result is : " + result);

    }

    // Driver code
    public static void main(String args[]) {
        // Creating the object of
        // the calculator
        pgm5 c = new pgm5();
        c.add(5, 10);
        c.subtract(35, 15);
        c.multiply(6, 9);
        c.divide(45, 6);
    }
}