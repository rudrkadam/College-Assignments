import  java.util.Scanner;

class ExceptionHandling
{
    static void arithmeticException(int num1, int num2)
    {
        try
        {
            System.out.println(num1 + " / " + num2 + " = " + num1/num2);
        }
        catch(ArithmeticException e)
        {
            System.out.println("Can't divide by 0!");
        }
    }

    static void arrayOutOfBound(int n)
    {
        try
        {
            int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            System.out.println("Element at index position " + n + ": " + arr[n]);
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Entered index is our of bound!");
        }
    }

    static void numberFormatException(String str)
    {
        try
        {
            int num = Integer.parseInt(str);
            System.out.println("Entered number is: " + num);
        }
        catch(NumberFormatException e)
        {
            System.out.println("Number format exception encountered!");
        }
    }
}

public class Main
{
    public static void main(String[] args)
    {
        int choice;
        Scanner sc = new Scanner(System.in);
        do
        {
            System.out.println("\nException Handling - Menu");
            System.out.println("1 - Arithmetic Exception");
            System.out.println("2 - Array out of bound Exception");
            System.out.println("3 - Number format Exception");
            System.out.println("0 - Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice)
            {
                case 0:
                    break;
                case 1:
                    int num1, num2;
                    System.out.println("Enter two numbers.");
                    System.out.print("Num1: ");
                    num1 = sc.nextInt();
                    System.out.print("Num2: ");
                    num2 = sc.nextInt();
                    ExceptionHandling.arithmeticException(num1, num2);
                    break;
                case 2:
                    int n;
                    System.out.println("Given array is arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}");
                    System.out.print("Enter index value to get element: ");
                    n = sc.nextInt();
                    ExceptionHandling.arrayOutOfBound(n);
                    break;
                case 3:
                    String str;
                    System.out.print("Enter the number: ");
                    Scanner scl = new Scanner(System.in);
                    str = scl.nextLine();
                    ExceptionHandling.numberFormatException(str);
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
        while (choice > 0 && choice < 4);
    }
}