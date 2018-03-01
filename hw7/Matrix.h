//
//  Matrix.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/16.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h
#include "Array.h"

template <typename Element>

class Matrix
{
private:
    int rows, cols;
    // define m as an Array of Array pointers using the
    // template you defined above
    Array <Array < Element >* > m;
public:
    Matrix( int newRows, int newCols ):rows( newRows ), cols( newCols ),m( rows )
    {
        for (int i = 0; i < rows; i++ )
            m[i] = new Array < Element >( cols );
    }
    int numRows()
    {
        return rows;
    }
    int numCols()
    {
        return cols;
    }
    Array < Element > & operator [] ( int row )
    {
        return *m[row];
    }
    
    void print( std::ostream & out )
    {
        for (int i = 0; i < rows; i++)
            out << m[i] << std::endl;
    }
    // You can write this one too, but use the Array::operator<<
    
    friend std::ostream & operator << (std::ostream & out, Matrix & m )
    {
        m.print(out);
        return out;
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete m[i];
    }
};

#endif /* Matrix_h */
