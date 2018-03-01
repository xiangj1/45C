// coins_menu.cpp  /// The name of this file
#include "Coins.h"

using namespace  std;

const int CENTS_FOR_BAG = 68;

int main()
{
    ///  The first line creates a Coins object called 'pocket.'
    Coins myCoins( 0, 0, 0, 0);
    
    int choice = 0;
    while(true)
    {
        cout << "===Menu===\n"
        << "1 - Deposit change\n"
        << "2 - Extract change\n"
        << "3 - Print the balance\n"
        << "4 - Exit the program\n"
        << "Enter the Choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                int qua, dim, nic, pen;
                cout << "\nPlease enter number of Quaters you wanna deposit: ";
                cin >> qua;
                cout << "\nPlease enter number of Dimes you wanna deposit: ";
                cin >> dim;
                cout << "\nPlease enter number of Nickels you wanna deposit: ";
                cin >> nic;
                cout << "\nPlease enter number of Pennies you wanna deposit: ";
                cin >> pen;
                Coins deposit(qua, dim, nic, pen);
                myCoins.deposit_coins(deposit);
                
            }
            break;
                
            case 2:
            {
                int amount = 0;
                cout << "Enter the amount of the cents you wanna extract: ";
                cin >> amount;
                myCoins.extract_exact_change_for_cents(amount);
            }
            break;
                
            case 3:
                cout << "I have " << myCoins << " left" << endl;
            break;
                
            case 4:
                cout << "See ya~~~~";
                return 0;
                
                
            default:
                cout << "The buffer you intered is not valid\n";
                break;
        }
        
    }
    
    return 0;
}

