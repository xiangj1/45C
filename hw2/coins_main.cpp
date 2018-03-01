// coins_main.cpp  /// The name of this file
#include "Coins.h"

using namespace  std;

const int CENTS_FOR_BAG = 68;

int main()
{
    ///  The first line creates a Coins object called 'pocket.'
    Coins pocket( 5, 3, 6, 8 );
    Coins piggybank (50, 50, 50, 50);
    cout << "I started with " << pocket << " in my pocket" << endl;
    
    
    ///  This line creates a Coins object called payForCandy and initializes it.
    Coins payForBag = pocket.extract_exact_change_for_cents( CENTS_FOR_BAG );
    cout << "I bought a bag for " << CENTS_FOR_BAG
    << " cents using " << payForBag << endl;
    cout << "I have " << pocket << " left in my pocket" << endl;
    
    cout << "Transfering $2.05 from piggy bank to pocket.\n";
    Coins transfer = piggybank.extract_exact_change_for_cents(205);
    pocket.deposit_coins(transfer);
    cout << "I have " << pocket << " left in my pocket" << endl;
    cout << "I have " << piggybank << " left in piggy bank" << endl;
    
    cout << "After vacuuming, put 10 quaters, 10 dimes, 10 nickels, and 10 pennies in piggybank\n";
    Coins sofa(10, 10, 10,10);
    piggybank.deposit_coins(sofa);
    
    cout << "Now I have $" << (double)piggybank.total_value_in_cents()/100 << " in the piggy bank\n";
    
    return 0;
}

