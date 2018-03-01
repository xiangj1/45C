//
//  Picture.h
//  hw
//
//  Created by Xiang Jiang on 2016/11/8.
//  Copyright © 2016年 45C. All rights reserved.
//

#ifndef Picture_h
#define Picture_h

typedef class ShapeLinkedListPair * ShapeLinkedList;
class ShapeLinkedListPair
{
public:
    Shape * info;
    ShapeLinkedList next;
    ShapeLinkedListPair( Shape * newInfo, ShapeLinkedList newNext )
    : info(newInfo), next( newNext )
    {
    }
};

class Picture
{
    ShapeLinkedList head;
public:
    Picture()
    : head( 0 )
    {
    }
    void add( Shape * a )
    {
        head = new ShapeLinkedListPair( a, head );
    }
    double totalArea()
    {
        double total = 0.0;
        for (ShapeLinkedList p = head; p != 0; p = p->next)
            total += p->info->area();
        return total;
    }
    void drawAll()
    {
        for (ShapeLinkedList temp = head; temp != nullptr; temp = temp->next)
        {
            temp->info->draw();
            std::cout << std::endl;
        }
    }
};



#endif /* Picture_h */
