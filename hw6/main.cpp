//
//  main.cpp
//  hw
//
//  Created by Xiang Jiang on 2016/11/8.
//  Copyright © 2016年 45C. All rights reserved.
//

#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Picture.h"

using namespace std;

int main()
{
    Picture pic;
    Triangle FirstTriangle(5,5);
    pic.add(&FirstTriangle);
    Triangle SecondTriangle(4,3);
    pic.add(&SecondTriangle);
    Circle FirstCircle(5);
    pic.add(&FirstCircle);
    Circle SecondCircle(10);
    pic.add(&SecondCircle);
    Square FirstSquare(5);
    pic.add(&FirstSquare);
    Square SecondSqaure(10);
    pic.add(&SecondSqaure);
    Rectangle FirstRectangle(4,8);
    pic.add(&FirstRectangle);
    Rectangle SecondRectangle(8,4);
    pic.add(&SecondRectangle);
    pic.drawAll();
    cout << "Total area is: " << pic.totalArea() << endl;
    
    return 0;
}
