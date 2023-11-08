#!/bin/bash

echo -e "\nWelcome to your Banking Database Application!"

choice0=0
while [ $choice0 -ne 9 ]
do
    # Change directory to the databases folder
    cd /mnt/d/Programming/Linux/Bank\ Database/Databases

    declare dbname
    echo -e "\n------- MENU -------"
    echo "1 - Show Databases"
    echo "2 - Create Database"
    echo "3 - Insert Data"
    echo "4 - Search Data"
    echo "5 - Display Database"
    echo "6 - Update Data"
    echo "7 - Delete Data"
    echo "8 - Delete Database"
    echo "9 - Exit"
    echo "--------------------"
    echo "DB Selected: $dbname"
    echo "--------------------"

    echo -e "\nEnter a choice: \c"
    read choice0

    case $choice0 in

    # Showing available Databases
    1 )
        filecount=$(ls | wc -l)
        if [ $filecount -eq 0 ]
        then
            echo -e "\n------------------------------"
            echo -e "NO DATABASES AVAILABLE"
            echo -e "------------------------------"
        else
            echo -e "\n------------------------------"
            echo -e "AVAILABLE DATABASES:"
            echo -e "------------------------------"
            ls -1 | sed -e 's/\.txt$//'
            # sed command removes any string .txt found at the end of the file names
            echo -e "------------------------------"

            read -p "Enter \"1\" to choose from above Database or press \"0\" for Main Menu: " choice1
            
            if [ $choice1 -eq 1 ]
            then
                read -p "Enter Database name you want to select: " dbname 
                echo -e "\n⇒ $dbname Database selected!"
            else
                echo -e "⇒ No Database selected!"
            fi
        fi ;;

    # Create Database
    2 )
        read -p "Enter database name: " dbname

        if [ -f $dbname ] || [ -f $dbname.txt ];
        then
            echo -e "\nDatabase $dbname already exists."
        else
            touch $dbname.txt
            echo -e "\nDatabase $dbname created and selected."
            echo "AccountNo, Name, Branch, MobNo" >> $dbname.txt
        fi ;;

    # Insert data into Database
    3 )
        choice2=1
        while [ $choice2 -ne 0 ]
        do
            echo ""
            read -p "Enter \"1\" to Enter Data or press \"0\" for Main Menu: " choice2

            if [ $choice2 -eq 1 ]
            then
                echo -e "Bank Name: $dbname"
                read -p "Account No.: " accno
                read -p "Name: " name
                read -p "Branch: " branch
                read -p "Mobile No.: " mobno

                existingAcc=$(grep -c "$accno" $dbname.txt)
                if [ $existingAcc -eq 0 ]
                then
                    if [ $mobno -ge 999999999 ] && [ $mobno -le 10000000000 ]
                    then
                        echo "$accno, $name, $branch, $mobno" >> $dbname.txt
                        echo -e "\nData entered successfully."
                    else
                        echo -e "\nMobile No. Invalid!"
                    fi
                else
                    echo -e "\nEntered Account No. $accno already exists!"
                fi
            fi
        done ;;

    # Searching for data in Database
    4 )
        read -p "Enter Account Number to search: " search
        searchcount=$(grep -c "$search" $dbname.txt)

        if [ $searchcount -eq 0 ]
        then
            echo -e "\n------------------------------"
            echo -e "No Account with Account No. $search found!"
            echo -e "------------------------------"
        else
            echo -e "\n------------------------------"
            echo -e "Account found:"
            grep "$search" $dbname.txt
            echo -e "------------------------------"
        fi ;;

    #  Displaying Database
    5 )
        linecount=$(wc -l < $dbname.txt)
        if [ $linecount -eq 1 ]
        then
            echo -e "\n------------------------------"
            echo -e "DATABASE IS EMPTY."
            echo -e "------------------------------"
        else
            echo -e "\n------------------------------"
            echo "DISPLAYING BANK DATABASE"
            echo "------------------------------"
            echo "Bank Database: $dbname"
            cat $dbname.txt
            echo "------------------------------"
        fi ;;
    
    # Updating data in Database
    6 )
        read -p "Enter Account Number to update details: " accno0
        searchcount0=$(grep -c "$accno0" $dbname.txt)

        if [ $searchcount0 -eq 0 ]
        then
            echo -e "\n------------------------------"
            echo -e "No Account with Account No. $accno0 found!"
            echo -e "------------------------------"
        else
            echo -e "\n------------------------------"
            echo -e "Account found:"
            grep "$accno0" $dbname.txt
            echo -e "------------------------------"

            read -p "Enter New Name: " newname
            read -p "Enter New Branch: " newbranch
            read -p "Enter New Mobile No.:" newmobno

            sed -i "s/.*$accno0.*/$accno0, $newname, $newbranch, $newmobno/g" $dbname.txt
            echo -e "\n------------------------------"
            echo -e "Account Information Updated:"
            grep "$accno0" $dbname.txt
            echo -e "------------------------------"
        fi ;;

    # Deleting data in Database
    7 )
        read -p "Enter Account Number to delete details: " accno1
        searchcount1=$(grep -c "$accno1" $dbname.txt)

        if [ $searchcount1 -eq 0 ]
        then
            echo -e "\n------------------------------"
            echo -e "No Account with Account No. $accno1 found!"
            echo -e "------------------------------"
        else
            echo -e "\n------------------------------"
            echo -e "Account found:"
            grep "$accno1" $dbname.txt
            echo -e "------------------------------"

            deleteConf0=1
            echo -e "\nEnter \"0\" to confirm the deletion of Account No. $accno1: \c"
            read deleteConf0

            if [ $deleteConf0 -eq 0 ]
            then
                echo -e "\n⇒ Account No. $accno1 successfully deleted!"
                sed -i "/.*$accno1.*/d" $dbname.txt
            else
                echo -e "\n⇒ Delete not done."
            fi
        fi ;;


    # Deleting Database
    8 )
        deleteConf1=1
        echo -e "\nEnter \"0\" to confirm the deletion of $dbname: \c"
        read deleteConf1

        if [ $deleteConf1 -eq 0 ]
        then
            echo -e "\n⇒ Successfully deleted $dbname Database!"
            rm $dbname.txt
        else
            echo -e "\n⇒ Delete not done."
        fi ;;
        
    # Exit from the Program
    9 )
        echo -e "\n⇒ Exited!" ;;

    esac
done
