// Coins.h		///  The name of this file.
#include <iostream>

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;

class Coins
{
private:
    int quarters, dimes, nickels, pennies;
    
public:
    Coins(int qua, int dim, int nic, int pen)
    {
        quarters = qua;
        dimes = dim;
        nickels = nic;
        pennies = pen;
    }
    void deposit_coins(Coins & c )
    {
        quarters += c.quarters;
        dimes += c.dimes;
        nickels += c.nickels;
        pennies += c.pennies;
    }
    bool has_exact_change_for_cents(int amount_in_cents )
    {
        return total_value_in_cents() >= amount_in_cents;
    }
    Coins extract_exact_change_for_cents(int amount_in_cents )
    {
        int qua = amount_in_cents/25;
        int dim = (amount_in_cents%25)/10;
        int nic = ((amount_in_cents%25)%10)/5;
        int pen = ((amount_in_cents%25)%10)%5;
        Coins payment(qua, dim, nic, pen);
        
        if(!has_exact_change_for_cents(amount_in_cents))
        {
            std::cout << "Not enough money";
            return payment;
        }
        
        amount_in_cents = total_value_in_cents() - amount_in_cents;
        
        quarters = amount_in_cents/25;
        dimes = (amount_in_cents%25)/10;
        nickels = ((amount_in_cents%25)%10)/5;
        pennies = ((amount_in_cents%25)%10)%5;

        return payment;
    }
    int total_value_in_cents()
    {
        int result = quarters*25 + dimes*10 + nickels*5 + pennies;
        return result;
    }
    void print(std::ostream & out )
    {
        out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, "
        << pennies << " pennies"; 
    }

};

std::ostream & operator << ( std::ostream & out, Coins c )
{
    c.print(out);
    return out;
}

