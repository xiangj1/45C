//
//  Triangle.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/8.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h
#include "Shape.h"

class Triangle: public Shape
{
public:
    Triangle(double newHeight = 0, double newBase = 0):Shape(newHeight/2,newBase/2 )
    {
        height = newHeight;
        base = newBase;
        ;
        
    }
    virtual double area()
    {
        return height*base/2;
    }
    virtual void draw()
    {
        //top
        for(int i = 0; i < base+1; i++)
            std::cout << " ";
        std::cout << "*\n";
        //body
        for(int h = 1; h < height; h++)
        {
            for(int i = 0; i < base - h+1; i++)
                std::cout << " ";
            std::cout << "*";
            
            for(int i = 0; i < h*2; i++)
                std::cout << " ";
            std::cout << "*\n";
        }
        //bot
        for(int i = 0; i < base+2; i++)
            std::cout << "* ";
        /*for (int h = 1, m = 2; h <height; h++, m+=2)
        {
            int b = 0, a;
            for (a = b; b <=(base*2-m)/2;b++)
                std::cout <<" ";
            std::cout << "*";
            for (; a<(base-b); a++)
                std::cout <<"  ";
            std::cout << "*\n";
        }
        for (int n = 0; n < base+1; n++)
            std::cout << "**";
        std::cout <<std::endl;*/
        
    }
private:
    double height, base;
};


#endif /* Triangle_h */
