//
//  mapset.cpp
//  hw
//
//  Created by Xiang Jiang on 2016/11/23.
//  Copyright © 2016年 45C. All rights reserved.
//

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    map <string, int> myMap;
    set <string> mySet;
    
    ifstream sample("sample_doc.txt");
    ifstream stop("stopwords.txt");
    
    for_each(istream_iterator<string>(stop),
             istream_iterator<string>(),
             [&](string temp)
             {
                 mySet.insert(temp);
             });
    
    for_each(istream_iterator<string>(sample),
             istream_iterator<string>(),
             [&](string temp)
             {
                 string temp1(temp);
                 transform(temp.begin(), temp.end(), temp1.begin(), ::tolower);
                 
                 if( mySet.find(temp1)== mySet.end() )
                 {
                     myMap[temp] += 1;
                 }
             });
    
    return 0;
}
