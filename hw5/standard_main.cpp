#include "String.h"

using namespace std;

int main()
{
    String first("first");
    String second(first);
    String third("third");
    String fourth;
    fourth = third;
    String fifth;

    cout << "First[2] = " << first[2] << endl;
    cout << "Size of Second: " << second.size() << endl;
    cout << "Index of 'i' in Third: " << third.indexOf('i') << endl;
    cout << "Is fourth == Third? " << (fourth==third)<< endl;
    cout << "Please enter the fifth string: ";
    cin >> fifth;
    cout << "\nFifth is : " << fifth << endl;
    cout << "Is fifth less than fourth? " << (fifth<fourth) << endl;
    cout << "Fifth+fourth = " << (fifth+fourth) << endl;
    fifth+=first;
    cout << "Fifth+=first = " << fifth << endl;
    cout << "Reverse of the fifth: " << fifth << endl;

    return 0;
}
