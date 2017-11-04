#pragma once

#ifndef BOX_H
#define BOX_H

#include "Util.h"

//define box
class Box
{
    private:
        int heigth;
        int width;
        int x;
        int y;
    public:
        
        void setpos(int x, int y);
        void setsize(int heigth, int width);   
        
        int getx()
        {
            return x;
        }
        int gety()
        {
            return y;
        }        
        int getheigth()
        {
            return heigth;
        }
        int getwidth()
        {
            return width;
        }  
};

void Box::setpos(int x, int y)
        {
            this->x = x;
            this->y = y;
            
        }
void Box::setsize(int heigth, int width)
        {
            this->heigth = heigth;
            this->width = width;
        }

#endif
