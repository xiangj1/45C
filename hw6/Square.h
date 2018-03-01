//
//  Square.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/8.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef Square_h
#define Square_h
#include "Shape.h"

#include "Shape.h"
class Square: public Shape
{
public:
    Square( double newSide )
    : side( newSide )

    {
        side = newSide;
        
    }
    
    virtual double area()
    {
        return side*side;
    }
    
    virtual void draw()
    {
        for (int col = 0; col<side; col++)
            std::cout << "* ";
        std::cout << "\n";
        for (int row = 2; row < side; row++)
        {
            std::cout <<"*";
            for (int col = 1; col < (side-1)*2; col++)
                std::cout << " ";
            std::cout << "*\n";
        }
        for (int col = 0; col<side; col++)
            std::cout << "* ";
        std::cout << std::endl;
    }
    
private:
    double side;
};

#endif /* Square_h */
