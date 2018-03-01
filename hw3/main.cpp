#include "String.h"

using namespace std;

void test_constructor_and_print()
{
    String s("Hello World");

    //char * p = strstr("hello word", "el");
    //cout << p;
}

void test_assignment()
{
    String first("hello");
    cout << "1. Created a String Object and put 'hello' in it\n";
    cout << "2. Create second String Object and assign it with the first Object\n";
    String second(first);
    cout << "3. Add the first to the second string:\n";
    second += first;
    cout << "4. Print the second string\n";
    cout << second << endl;
    cout << "5. Reverse the second string\n";
    cout << second.reverse() << endl;
    cout << "6. find the first string in the second string and show the index of it.\n";
    cout << second.indexOf(first) << endl;
    cout << "7. find the 'l' character in the second string and show the index of it.\n";
    cout << second.indexOf('l') << endl;
    cout << "8. Create third object and you type the word in it.\n";
    String third;
    cin >> third;
    cout << "9. Is the frst == third? " << (first == third) << endl;
    cout << "10.Reverse the third.\n";
    cout << third.reverse();
    
}
int main()
{
    //test_constructor_and_print();
    test_assignment();
    
    // ...
    
}
