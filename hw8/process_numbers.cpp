//
//  process_numbers.cpp
//  hw
//
//  Created by Xiang Jiang on 2016/11/23.
//  Copyright © 2016年 45C. All rights reserved.
//

#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    set<int> mySet;
    ifstream in("rand_numbers.txt");
    
    for_each (istream_iterator<int>(in),
              istream_iterator<int>(),
              [&](int num)
              {
                  mySet.insert(num);
              });
    
    ofstream odd;
    ofstream even;
    odd.open("odd.txt");
    even.open("even.txt");
    
    for (auto temp_int: mySet)
    {
        if (temp_int%2 == 0)
        {
            even << temp_int << "\n";
        }
        else
        {
            odd << temp_int << " ";
        }
    }
    
    odd.close();
    even.close();
    return 0;
}
