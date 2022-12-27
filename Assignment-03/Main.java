import java.util.Scanner;

class Publication
{
    // Publication class variables - common to both subclasses
    String title, type;
    int price, copies;

    // common method to both subclasses
    void saleCopy()
    {
        System.out.println("Sale of " + type + " publication: " + price*copies + "/-");
    }
}

class Book extends Publication
{
    // constructor to give publication type "Book"
    Book()
    {
        type = "Book";
    }

    String author;

    void orderCopies()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter title of the book: ");
        title = sc.nextLine();
        System.out.print("Enter name of the author: ");
        author = sc.nextLine();
        System.out.print("Enter price: ");
        price = sc.nextInt();
        System.out.print("Enter number of copies: ");
        copies = sc.nextInt();
    }

    void dispay()
    {
        System.out.println("\n------------------------------");
        System.out.println("BOOK DETAILS");
        System.out.println("------------------------------");
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price (per copy): " + price);
        System.out.println("Number of copies: " + copies);
        System.out.println("------------------------------");
    }
}

class Magazine extends Publication
{
    // constructor to give publication type "Magazine"
    Magazine()
    {
        type = "Magazine";
    }

    int currentIssue;

    void receiveIssue()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter title of the magazine: ");
        title = sc.nextLine();
        System.out.print("Enter current issue: ");
        currentIssue = sc.nextInt();
        System.out.print("Enter price: ");
        price = sc.nextInt();
        System.out.print("Enter number of copies: ");
        copies = sc.nextInt();
    }

    void dispay()
    {
        System.out.println("\n------------------------------");
        System.out.println("MAGAZINE DETAILS");
        System.out.println("------------------------------");
        System.out.println("Title: " + title);
        System.out.println("Current Issue: " + currentIssue);
        System.out.println("Price (per copy): " + price);
        System.out.println("Number of copies: " + copies);
        System.out.println("------------------------------");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Book b1 = new Book();
        b1.orderCopies();
        b1.dispay();
        System.out.println();

        Magazine m1 = new Magazine();
        m1.receiveIssue();
        m1.dispay();

        System.out.println("\n------------------------------");
        System.out.println("PUBLICATION SALE");
        System.out.println("------------------------------");
        b1.saleCopy();
        m1.saleCopy();
        System.out.println("Total sale of publication: " + (b1.price*b1.copies + m1.price*m1.copies) + "/-");
        System.out.println("------------------------------");
    }
}
