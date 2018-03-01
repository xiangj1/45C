//
//  Shape.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/8.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef Shape_h
#define Shape_h
#include <iostream>

class Shape
{
    
public:
    Shape(double newCenterX = 0, double newCenterY = 0, double newSize = 0){
        centerX = newCenterX;
        centerY = newCenterY;
        size = newSize;
    }
    
    virtual double area() = 0;
    virtual void draw() = 0;
    virtual ~Shape(){};
protected:
    double centerX;
    double centerY;
    double size;
    
};

#endif /* Shape_h */
