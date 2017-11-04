#pragma once

#ifndef FRAME_H
#define FRAME_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif


#include "box.h"
#include "button.h"
#include "conio.h"

class Frame : public Box
{

    private:
    
    int icount; //số lượng phần tử của frame
    bool exit; //đóng frame
    int itouch; //biến di chuyển lên xuống trong menu

public:  
    Button ArrItem[20];//max = 20 item button can be added
    Frame();   
    Frame(int x, int y); //đặt vị trí cho frame    
    void addButton(Button item);//thêm các menu item cho frame
    bool getendgame();//lấy giá trị của endgame để thoát    
    void gamerender();//vẽ ra frame
    struct direction;// khai bao di chuyen cua bien 
    void gameloop();//setup the direction control of the frame   
    void movedir(direction dir);//moveing in frame
    void clearframe();//frame working

};

Frame::Frame(int x, int y)
    {
        setpos(x, y);
        icount = 0;
        itouch = 0;
        exit = false;
        
    }
Frame::Frame()
    {
    
    }

void Frame::addButton(Button item)
    {
        item.setpos(getx()+1, gety()+1);
        ArrItem[icount] = item;
        this->icount++;
        setpos(getx()+13,gety());
    }
bool Frame::getendgame()
    {
        return exit;
    }
void Frame::gamerender()//vẽ frame
    {
        for (int i = 0; i < icount; i++)
        {
            ArrItem[i].draw();
        }
    }
struct Frame::direction
    {
        int x, y;
    };
void Frame::gameloop()
    {   
        
            direction dir;
            dir.x = 0;
            dir.y = 0;

            char c = getch();
            if(c==-32) c= getch();
            switch(c)
            {
                case 72://len
                    dir.x = 0;
                    dir.y = -1;
                    break;
                case 80: //xuong
                    dir.x = 0;
                    dir.y = 1;
                    break;
                case 77://phai
                    dir.x = 1;
                    dir.y = 0;
                    break;
                case 75://trai
                    dir.x = -1;
                    dir.y = 0;
                    break;
                case 13: //enter
                    ArrItem[itouch].setselect(true);
                    break;
                case 27://escapse
                    exit = true;
                    break;
            }
            movedir(dir); 
        
    }

void Frame::movedir(direction dir) 
    {
        if(!exit)
            {
            int iprev = itouch;
            itouch += dir.x;

            if(itouch < 0) itouch = icount - 1;
            if(itouch == icount) itouch = 0;
            if(itouch != iprev)
                {
                ArrItem[itouch].settouch(true);
                ArrItem[iprev].settouch(false);
                ArrItem[itouch].draw();
                ArrItem[iprev].draw();
                }
            }else clearframe();
    }

void Frame::clearframe()
    {
        for (int i = 0; i < icount; i++)
        {
            ArrItem[i].clear();
        }
    }

#endif /* FRAME_H */
