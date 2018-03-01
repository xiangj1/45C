#include <iostream>

using namespace std;

double knot_to_mpm(int knot)
{
    double result = 0;
    //knot = feet per hour
    result = knot * 6076;
    //feet per hour = mph
    result /= 5280;
    // mph = mpm
    result /= 60;
    return result;
}

int main(int argc, const char * argv[]) {
    int knot = 0;
    
    std::cout << "Insert the knot, it will converse into miles per minute\n";
    cin >> knot;
    cout << knot << " knots equals to " << knot_to_mpm(knot) << " miles per minute\n";
    return 0;
}

