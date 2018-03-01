//
//  main.cpp
//  hw
//
//  Created by Xiang Jiang on 2016/11/28.
//  Copyright © 2016年 45C. All rights reserved.
//

#include "MapArray.h"
#include "SetList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
    MapArray<string, int> ints;
    SetList<string> sets;
    
    ifstream sample("sample_doc.txt");
    ifstream stop("stopwords.txt");
    
    for_each(istream_iterator<string>(stop),
             istream_iterator<string>(),
             [&](string temp)
             {
                 sets.insert(temp);
             });
    
    for_each(istream_iterator<string>(sample),
             istream_iterator<string>(),
             [&](string temp)
             {
                 string temp_string(temp);
                 transform(temp.begin(), temp.end(), temp_string.begin(), ::tolower);
                 
                 if( sets.find(temp_string) == sets.end())
                 {
                     ints[temp] += 1;
                 }
             });
    
    ofstream frequency;
    frequency.open("frequency.txt");
    for (auto temp: ints)
    {
        frequency << temp.first << ": " << temp.second << endl;
    }
    cout << endl;
    frequency.close();
    return 0;
}
