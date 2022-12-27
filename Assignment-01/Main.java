import java.util.Scanner;

class Complex
{
    float r, i;

    // default constructor
    Complex()
    {
        r = i = 0;
    }

    // parameterized constructor
    Complex(float real, float imaginary)
    {
        r = real;
        i = imaginary;
    }

    // method to display complex no
    void displayNo()
    {
        System.out.println("Complex No.: " + r + " + " + i + "i");
    }

    static void addition(Complex obj1, Complex obj2)
    {
        float real = (obj1.r + obj2.r);
        float imaginary = (obj1.i + obj2.i);
        Complex sum = new Complex(real, imaginary);
        System.out.println("Addition of these two complex numbers is");
        sum.displayNo();
    }

    static void subtraction(Complex obj1, Complex obj2)
    {
        float real = (obj1.r - obj2.r);
        float imaginary = (obj1.i - obj2.i);
        Complex difference = new Complex(real, imaginary);
        System.out.println("Subtraction of these two complex numbers is");
        difference.displayNo();
    }

    static void multiplication(Complex obj1, Complex obj2)
    {
        float real = ((obj1.r * obj2.r) - (obj1.i * obj2.i));
        float imaginary = ((obj1.r * obj2.i) + (obj1.i * obj2.r));
        Complex product = new Complex(real, imaginary);
        System.out.println("Multiplication of these two complex numbers is");
        product.displayNo();
    }

    static void division(Complex obj1, Complex obj2)
    {
        float real = (((obj1.r * obj2.r) + (obj1.i * obj2.i)) / ((obj2.r * obj2.r) + (obj1.r * obj1.r)));
        float imaginary = (((-obj1.r * obj2.i) + (obj1.i * obj2.r)) / ((obj2.r * obj2.r) + (obj1.r * obj1.r)));
        Complex division = new Complex(real, imaginary);
        System.out.println("Division of these two complex numbers is");
        division.displayNo();
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        Complex c1 = new Complex();
        System.out.print("Enter real part for first complex no (c1): ");
        c1.r = sc.nextFloat();
        System.out.print("Enter imaginary part for first complex no (c1): ");
        c1.i = sc.nextFloat();
        c1.displayNo();

        Complex c2 = new Complex();
        System.out.print("Enter real part for second complex no (c2): ");
        c2.r = sc.nextFloat();
        System.out.print("Enter imaginary part for second complex no (c2): ");
        c2.i = sc.nextFloat();
        c2.displayNo();

        int choice;
        do
        {
            Scanner sc1 = new Scanner(System.in);
            System.out.println("\n1 - Addition");
            System.out.println("2 - Subtraction");
            System.out.println("3 - Multiplication");
            System.out.println("4 - Division");
            System.out.println("0 - Exit");
            System.out.print("Enter the choice: ");
            choice = sc1.nextInt();

            switch(choice)
            {
                case 0:
                    break;
                case 1:
                    Complex.addition(c1, c2);
                    break;
                case 2:
                    Complex.subtraction(c1, c2);
                    break;
                case 3:
                    Complex.multiplication(c1, c2);
                    break;
                case 4:
                    Complex.division(c1, c2);
                    break;
                default:
                    System.out.println("Invalid input.");
            }
        }
        while (choice > 0 && choice < 5);
    }
}
