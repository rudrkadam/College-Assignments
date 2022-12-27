import java.util.Scanner;

// abstract class inherited by subclasses
abstract class Shape
{
    double value1, value2;

    // function to input the data
    void input()
    {
        Scanner sc = new Scanner(System.in);
        value1 = sc.nextDouble();
        value2 = sc.nextDouble();
    }

    // abstract method - redefined in subclasses
    abstract void computeArea();
}

class Triangle extends Shape
{
    @Override
    void computeArea()
    {
        System.out.println("Area of triangle: " + 0.5*value1*value2);
    }
}

class Rectangle extends Shape
{
    @Override
    void computeArea()
    {
        System.out.println("Area of rectangle: " + value1*value2);
    }
}

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("1 - Calculate area of triangle");
        System.out.println("2 - Calculate area of rectangle");
        System.out.print("Choose operation: ");
        Scanner sc = new Scanner(System.in);
        int choice = sc.nextInt();

        switch (choice)
        {
            case 1:
                Shape t = new Triangle();
                System.out.println("Enter base and height of the triangle:");
                t.input();
                t.computeArea();
                break;
            case 2:
                Shape r = new Rectangle();
                System.out.println("Enter length and breadth of the rectangle:");
                r.input();
                r.computeArea();
                break;
            default:
                System.out.println("Invalid input.");
                break;
        }
    }
}
