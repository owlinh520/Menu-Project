
#pragma once

#ifndef MENU_H
#define MENU_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif


#include "box.h"
#include "frame.h"
#define colorbackground 3
#define colorselect 4
#define colorfont 7

class Button : public Box
{
private:
    string title;
    bool touch;
    bool select;

public: 
    Button();
    Button(string name);
    void setselect(bool select);// cai dat lua chon
    void settouch(bool touch);  //cai dat tro vao vi tri
    void settitle(string title);//cai dat ten cua nut.
    void draw();                //in ra màn hình box
    void clear();
    bool getselect()
        {
            return select;
        }
};

Button::Button()
{
    
}

Button::Button(string name)
    {
        settitle(name);
        setsize(1, 12);
        setpos(0,0);
        touch = false;
        select = false;
    };
    
void Button::settitle(string title)
    {
        this->title = title;
    }
void Button::settouch(bool touch)
    {
        this->touch = touch;
    }
void Button::setselect(bool select)
    {
        this->select = select;
    }
void Button::draw()
    {
        if(touch == false)
        SetBGColor(colorbackground);
        else SetBGColor(colorselect);
            
        for (int i = getx(); i < getx()+getwidth(); i++) 
            {
                for (int j = gety(); j < gety()+getheigth(); j++) 
                    {
                        gotoxy(i, j);
                        printf(" ");
                    }
            }
            //in title
            SetColor(colorfont); 
            for(int i = 0; i < title.length();i++){
                gotoxy(getx()+1+i,(2*gety()+getheigth())/2);
                cout<<title[i];
            }  
    }
void Button::clear()
{
    SetBGColor(0);
    for (int i = getx(); i < getx()+getwidth(); i++) 
            {
                for (int j = gety(); j < gety()+getheigth(); j++) 
                    {
                        gotoxy(i, j);
                        printf(" ");
                    }
            }
}


#endif /* MENU_H */
