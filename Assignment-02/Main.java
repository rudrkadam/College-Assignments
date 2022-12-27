import java.util.Scanner;

class Employee
{
    // Employee class variables - personal details
    String emp_name;
    int emp_id;
    String emp_address;
    String emp_emailID;
    long emp_mobileNo;
    String emp_designation;

    // Employee class variables - salary
    double basic_pay;
    double net_salary, gross_salary, da, hra, pf, scf;

    // salary calculation method
    void salaryCalculator(double basic_pay)
    {
        da = basic_pay * 0.97;
        hra = basic_pay * 0.10;
        pf = basic_pay * 0.12;
        scf = basic_pay * 0.001;
        gross_salary = basic_pay + hra;
        net_salary = gross_salary - pf - scf;
    }

    // method to input employee details
    Scanner sc = new Scanner(System.in);
    Scanner scl = new Scanner(System.in);
    void input()
    {
        System.out.print("Enter the name of the employee: ");
        emp_name = scl.nextLine();
        System.out.print("Enter the employee ID: ");
        emp_id = sc.nextInt();
        System.out.print("Enter the address: ");
        emp_address = scl.nextLine();
        System.out.print("Enter the email ID: ");
        emp_emailID = scl.nextLine();
        System.out.print("Enter the mobile no.: ");
        emp_mobileNo = sc.nextLong();
    }

    // method to print (output) employee details
    void display()
    {
        System.out.println("\n----------------------------------");
        System.out.println("EMPLOYEE DETAILS");
        System.out.println("----------------------------------");
        System.out.println("• Name: " + "\t\t"+emp_name);
        System.out.println("• Emp ID: " + "\t\t"+emp_id);
        System.out.println("• Designation: " + "\t"+emp_designation);
        System.out.println("• Address: " + "\t\t"+emp_address);
        System.out.println("• Email ID: " + "\t"+emp_emailID);
        System.out.println("• Mobile No.: " + "\t"+emp_mobileNo);
        System.out.println("----------------------------------");
    }

    // method to print salary slips
    void salary_slip()
    {
        System.out.println("\n----------------------------------");
        System.out.println("SALARY SLIP FOR EMPLOYEE ID " + emp_id);
        System.out.println("----------------------------------");
        System.out.println("• Basic Pay (BP): " + "\t"+basic_pay + "/-");
        System.out.println("• DA: " + "\t\t\t\t"+da + "/-");
        System.out.println("• HRA: " + "\t\t\t\t"+hra + "/-");
        System.out.println("• PF: " + "\t\t\t\t"+pf + "/-");
        System.out.println("• Gross Salary: " + "\t"+gross_salary + "/-");
        System.out.println("• Net Salary: " + "\t\t"+net_salary + "/-");
        System.out.println("----------------------------------");
    }

    // method to input and output employee details
    void details()
    {
        input();
        display();
    }

    // method to input basic pay and print salary slip
    void salary()
    {
        System.out.print("\nEnter basic pay (BP) for Employee ID " + emp_id + ": ");
        basic_pay = sc.nextDouble();
        salaryCalculator(basic_pay);
        salary_slip();
    }
}

class Programmer extends Employee
{
    Programmer()
    {
        emp_designation = "Programmer";
        details();
        salary();
    }
}

class TeamLead extends Employee
{
    TeamLead()
    {
        emp_designation = "Team Lead";
        details();
        salary();
    }
}

class AssProjManager extends Employee
{
    AssProjManager()
    {
        emp_designation = "A.Proj.Manager";
        details();
        salary();
    }
}

class ProjManager extends Employee
{
    ProjManager()
    {
        emp_designation = "Proj.Manager";
        details();
        salary();
    }
}

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("1 - Programmer");
        System.out.println("2 - Team Lead");
        System.out.println("3 - Assistant Proj. Manager");
        System.out.println("4 - Project Manager");
        System.out.print("Choose designation of new employee: ");
        Scanner sc = new Scanner(System.in);
        int des = sc.nextInt();

        switch (des)
        {
            case 1:
                Programmer p1 = new Programmer();
                break;
            case 2:
                TeamLead tl1 = new TeamLead();
                break;
            case 3:
                AssProjManager apm1 = new AssProjManager();
                break;
            case 4:
                ProjManager pm1 = new ProjManager();
                break;
            default:
                System.out.println("Invalid input.");
        }
    }
}
