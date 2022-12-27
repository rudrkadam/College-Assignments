import java.util.Scanner;

interface Vehicle
{
    void gearChange();
    void speedUp();
    void applyBrakes();
}

class Bicycle implements Vehicle
{
    int speed, gear = 0;

    public void gearChange()
    {
        if (speed == 0)
        {
            gear = 0;
            System.out.println("Current gear of bicycle: " + gear);
        }
        else if (speed > 0 && speed <= 5)
        {
            gear = 1;
            System.out.println("Current gear of bicycle: " + gear);
        }
        else if (speed > 5 && speed <= 10)
        {
            gear = 2;
            System.out.println("Current gear of bicycle: " + gear);
        }
        else if (speed > 10 && speed <= 15)
        {
            gear = 3;
            System.out.println("Current gear of bicycle: " + gear);
        }
        else if (speed > 15 && speed <= 20)
        {
            gear = 4;
            System.out.println("Current gear of bicycle: " + gear);
        }
        else if (speed > 20)
        {
            gear = 5;
            System.out.println("Current gear of bicycle: " + gear);
        }
    }

    public void speedUp()
    {
        if (speed < 28)
        {
            speed = speed + 2;
            System.out.println("Speed increased by 2km/hr.");
        }
        else
        {
            speed = 30;
            System.out.println("Bicycle at maximum speed.");
        }
    }

    public void applyBrakes()
    {
        System.out.println("Apply brakes:");
        System.out.println("1 - Decrease speed");
        System.out.println("2 - Emergency brake");
        Scanner sc = new Scanner(System.in);
        int choice = sc.nextInt();
        if (choice == 1)
        {
            System.out.println("Speed of bicycle decreased by 2km/hr.");
            this.speed = this.speed - 2;
            System.out.println("Current speed of bicycle: " + this.speed + "km/hr.");
        }
        else if (choice == 2)
        {
            System.out.println("The bicycle is at an immediate halt.");
            this.speed = 0;
        }
        else
        {
            System.out.println("Enter valid braking choice.");
        }
    }
}

class Bike implements Vehicle
{
    int speed, gear = 0;

    public void gearChange()
    {
        if (speed == 0)
        {
            gear = 0;
            System.out.println("Current gear of bike: " + gear);
        }
        else if (speed > 0 && speed <= 10)
        {
            gear = 1;
            System.out.println("Current gear of bike: " + gear);
        }
        else if (speed > 10 && speed <= 25)
        {
            gear = 2;
            System.out.println("Current gear of bike: " + gear);
        }
        else if (speed > 25 && speed <= 35)
        {
            gear = 3;
            System.out.println("Current gear of bike: " + gear);
        }
        else if (speed > 35 && speed <= 50)
        {
            gear = 4;
            System.out.println("Current gear of bike: " + gear);
        }
        else if (speed > 50)
        {
            gear = 5;
            System.out.println("Current gear of bike: " + gear);
        }
    }

    public void speedUp()
    {
        if (speed < 115)
        {
            speed = speed + 5;
            System.out.println("Speed increased by 5km/hr.");
        }
        else
        {
            speed = 120;
            System.out.println("Bike at maximum speed.");
        }
    }

    public void applyBrakes()
    {
        System.out.println("Apply brakes:");
        System.out.println("1 - Decrease speed");
        System.out.println("2 - Emergency brake");
        Scanner sc = new Scanner(System.in);
        int choice = sc.nextInt();
        if (choice == 1)
        {
            System.out.println("Speed of bike decreased by 5km/hr.");
            this.speed = this.speed - 5;
            System.out.println("Current speed of bike: " + this.speed + "km/hr.");
        }
        else if (choice == 2)
        {
            System.out.println("The bike is at an immediate halt.");
            this.speed = 0;
        }
        else
        {
            System.out.println("Enter valid braking choice.");
        }
    }
}

class Car implements Vehicle
{
    int speed, gear = 0;

    public void gearChange()
    {
        if (speed == 0)
        {
            gear = 0;
            System.out.println("Current gear of car: " + gear);
        }
        else if (speed > 0 && speed <= 20)
        {
            gear = 1;
            System.out.println("Current gear of car: " + gear);
        }
        else if (speed > 20 && speed <= 40)
        {
            gear = 2;
            System.out.println("Current gear of car: " + gear);
        }
        else if (speed > 40 && speed <= 60)
        {
            gear = 3;
            System.out.println("Current gear of car: " + gear);
        }
        else if (speed > 60 && speed <= 80)
        {
            gear = 4;
            System.out.println("Current gear of car: " + gear);
        }
        else if (speed > 80)
        {
            gear = 5;
            System.out.println("Current gear of car: " + gear);
        }
    }

    public void speedUp()
    {
        if (speed < 190)
        {
            speed = speed + 10;
            System.out.println("Speed increased by 10km/hr.");
        }
        else
        {
            speed = 200;
            System.out.println("Car at maximum speed.");
        }
    }

    public void applyBrakes()
    {
        System.out.println("Apply brakes:");
        System.out.println("1 - Decrease speed");
        System.out.println("2 - Emergency brake");
        Scanner sc = new Scanner(System.in);
        int choice = sc.nextInt();
        if (choice == 1)
        {
            System.out.println("Speed of car decreased by 10km/hr.");
            this.speed = this.speed - 10;
            System.out.println("Current speed of car: " + this.speed + "km/hr.");
        }
        else if (choice == 2)
        {
            System.out.println("The car is at an immediate halt.");
            this.speed = 0;
        }
        else
        {
            System.out.println("Enter valid braking choice.");
        }
    }
}

public class Main
{
    static int menu()
    {
        System.out.println("1 - Speed up");
        System.out.println("2 - Show speed");
        System.out.println("3 - Show gear");
        System.out.println("4 - Apply brakes");
        System.out.println("0 - Exit");
        System.out.print("Choose the operation: ");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    public static void main(String[] args)
    {
        System.out.println("1 - Bicycle");
        System.out.println("2 - Bike");
        System.out.println("3 - Car");
        System.out.print("Choose the vehicle: ");
        Scanner sc = new Scanner(System.in);
        int vehicleChoice = sc.nextInt();

        switch (vehicleChoice)
        {
            case 1:
                Bicycle bc = new Bicycle();
                int choice1;
                do
                {
                    choice1 = menu();

                    switch (choice1)
                    {
                        case 0:
                            break;
                        case 1:
                            bc.speedUp();
                            break;
                        case 2:
                            System.out.println("Speed of bicycle: " + bc.speed + "km/hr.");
                            break;
                        case 3:
                            bc.gearChange();
                            break;
                        case 4:
                            bc.applyBrakes();
                            break;
                        default:
                            System.out.println("Invalid operation.");
                            break;
                    }
                }
                while(choice1 > 0 && choice1 < 5);
                break;
            case 2:
                Bike bk = new Bike();
                int choice2;
                do
                {
                    choice2 = menu();

                    switch (choice2)
                    {
                        case 0:
                            break;
                        case 1:
                            bk.speedUp();
                            break;
                        case 2:
                            System.out.println("Speed of bike: " + bk.speed + "km/hr.");
                            break;
                        case 3:
                            bk.gearChange();
                            break;
                        case 4:
                            bk.applyBrakes();
                            break;
                        default:
                            System.out.println("Invalid operation.");
                            break;
                    }
                }
                while(choice2 > 0 && choice2 < 5);
                break;
            case 3:
                Car c = new Car();
                int choice3;
                do
                {
                    choice3 = menu();

                    switch (choice3)
                    {
                        case 0:
                            break;
                        case 1:
                            c.speedUp();
                            break;
                        case 2:
                            System.out.println("Speed of car: " + c.speed + "km/hr.");
                            break;
                        case 3:
                            c.gearChange();
                            break;
                        case 4:
                            c.applyBrakes();
                            break;
                        default:
                            System.out.println("Invalid operation.");
                            break;
                    }
                }
                while(choice3 > 0 && choice3 < 5);
                break;
            default:
                System.out.println("Invalid vehicle choice.");
        }
    }
}
