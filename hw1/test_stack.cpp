#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Stack test1;
    
    //char var1 = '0';
    string temp = "";
    
    while(1)
    {
        cout << "\nType a sentence(enter >>ctl+d<< to exit): ";
        if(!getline(cin, temp))
            break;
        
        
        for(int i=0; i < temp.size(); i++)
            test1.push(temp[i]);
        
        cout << "\nPoping from the last character\n";
        for(int i=0; i < temp.size(); i++)
            cout << test1.pop();
        
        //cout << "\nIs empty: " << test1.isEmpty();
        //cout << "\nIs full: " << test1.isFull();
    }
        
    return 0;
}
