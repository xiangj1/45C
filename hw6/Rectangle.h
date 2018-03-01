//
//  Rectangle.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/8.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h
#include "Square.h"

class Rectangle : public Square
{
public:
    Rectangle (double newHeight = 0, double newWidth = 0):Square(newHeight)
    {
        height = newHeight;
        width = newWidth;
        ;
    }
    virtual double area()
    {
        return height*width;
    }
    
    virtual void draw()
    {
        for (int col = 0; col < width; col++)
            std::cout << "* ";
        std::cout << "\n";
        for(int row = 0; row < height; row++)
        {
            std::cout << "* ";
            for(int i = 0; i < width-2; i++)
                std::cout << "  ";
            std::cout << "*\n";
        }
        for (int col = 0; col < width; col ++)
            std::cout << "* ";
        std::cout << std::endl;
    }
    
protected:
    double height, width;
};

#endif /* Rectangle_h */
