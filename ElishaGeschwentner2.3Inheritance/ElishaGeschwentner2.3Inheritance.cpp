#include <iostream>
#include <string>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"


//initialize accounts
CheckingAccount Checking(300);
SavingsAccount Savings(1500);
CreditAccount Credit(0);

//functions
const std::string ESC = "\x1B";

void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

void PressEnter()
{
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleClear()
{
    std::cout << ESC << "[2J" << ESC << "[H"; //clears the screen and moves the cursor to the top-left
}

float GetInteger(std::string message, float min, float max)
{
    float number = 0;
    while (true)
    {
        std::cout << "\n" << message;
        if (std::cin >> number && number >= min && number <= max)
        {
            ClearInputBuffer();
            break;
        }
        ClearInputBuffer();
        std::cout << "\nInvalid number.\n";
    }
    return number;
}

void ConsolePrint(std::string message, bool isExit = false, bool endl = true)
{
    std::cout << message;
    if (endl) { std::cout << std::endl; }
    
    if (isExit)
    {
        PressEnter();
        ConsoleClear();
    }
}

int main()
{
    //select account
    //deposit, withdraw

    int selection;
    do
    {
        ConsolePrint("Select the account to open the menu for.");
        ConsolePrint("1. Checking");
        ConsolePrint("2. Savings");
        ConsolePrint("3. Credit");
        ConsolePrint("4. Exit Program");

        selection = GetInteger("Selection: ", 1, 4);
        switch (selection)
        {
        default:
            break;
        case 1:

            //checking menu start

            do
            {
                ConsoleClear();

                ConsolePrint("You have opened your checking account. Select the action you want to do.");
                ConsolePrint("1. Withdraw");
                ConsolePrint("2. Deposit");
                ConsolePrint("3. Check Balance");
                ConsolePrint("4. Go back to accounts menu");

                selection = GetInteger("Selection: ", 1, 4);
                switch (selection)
                {
                default:
                    break;

                case 1:
                    Checking.Withdraw(GetInteger("How much would you like to deposit: ", 0.01, Checking.GetBalance()));

                    ConsolePrint(std::to_string(Checking.GetBalance()) + " dollars are left in your account.", true);
                    break;

                case 2:
                    Checking.Deposit(GetInteger("How much would you like to deposit: ", 0.01, INT_MAX));

                    ConsolePrint(std::to_string(Checking.GetBalance()) + " dollars are now in your account.", true);
                    break;
                    
                case 3:
                    
                    ConsolePrint("\n" + std::to_string(Checking.GetBalance()) + " dollars are in your account.", true);
                    break;

                case 4:
                    ConsolePrint("Returning to accounts menu", true);
                    break;
                }

            } while (selection != 4);
            break;

            //checking menu end

        case 2:

            //savings menu start

            do
            {
                ConsoleClear();

                ConsolePrint("You have opened your checking account. Select the action you want to do.");
                ConsolePrint("1. Withdraw");
                ConsolePrint("2. Deposit");
                ConsolePrint("3. Check Balance");
                ConsolePrint("4. Go back to accounts menu");

                selection = GetInteger("Selection: ", 1, 4);
                switch (selection)
                {
                default:
                    break;

                case 1:
                    Checking.Withdraw(GetInteger("How much would you like to deposit: ", 0.01, Checking.GetBalance()));

                    ConsoleClear();

                    ConsolePrint(std::to_string(Checking.GetBalance()) + " dollars are left in your account.");
                    PressEnter();
                    ConsoleClear();
                    break;

                case 2:
                    Checking.Deposit(GetInteger("How much would you like to deposit: ", 0.01, INT_MAX));

                    ConsoleClear();

                    ConsolePrint(std::to_string(Checking.GetBalance()) + " dollars are now in your account.");
                    PressEnter();
                    ConsoleClear();
                    break;

                case 3:

                    ConsolePrint("\n" + std::to_string(Checking.GetBalance()) + " dollars are in your account.");
                    PressEnter();
                    ConsoleClear();
                    break;

                case 4:
                    ConsolePrint("Returning to accounts menu");

                    PressEnter();
                    ConsoleClear();
                    break;
                }

            } while (selection != 4);
            break;

            //savings menu end


        }

        ConsoleClear();
    } while (selection != 4);

}
