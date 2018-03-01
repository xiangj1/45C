//
//  Circle.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/8.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef Circle_h
#define Circle_h
#include "Shape.h"

class Circle : public Shape
{
private:
    const double Pi = 3.14159;

public:
    Circle(double r = 0):Shape(r, r)
    {
        radius = r;
    }
    
    virtual double area()
    {
        return Pi * radius * radius ;
    }
    virtual void draw()
    {
        std::cout << "          **          \n"<<
                     "       *      *       \n"<<
                     "    *            *    \n"<<
                     "  *                *  \n"<<
                     " *                  * \n"<<
                     "*                    *\n"<<
                     "*                    *\n"<<
                     " *                  * \n"<<
                     "  *                *  \n"<<
                     "    *            *    \n"<<
                     "       *      *       \n"<<
                     "          **          \n"<< std::endl;
    }
private:
    double radius;
};

#endif /* Circle_h */
