#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H
#include "stdlib.h"
#include "frame.h"
#include "button.h"
#include "devicefunction.h"
#include "softfunction.h"
#include "findfunction.h"
#include "conio.h"
void ShowAndClear();
void Clear(int x1 , int y1, int x2, int y2, int BGC);

void Control()
{
    Button ManageButt("Manage");
        Button NewButt0("New");
        Button EditButt0("Edit");
        Button DeleteButt0("Delete");
            Button CodeButt03("Code");
            Button NameButt03("Name");
            
    Button PrintButt("Print");
    
    Button SoftButt("Sort");
        Button SelectButt2("Selection");
            Button CodeButt21("By Code");
            Button NameButt21("By Name");
            Button TypeButt21("By Type");
            Button UnitButt21("By Unit");
            
        Button InsertButt2("Insertion");
            Button CodeButt22("By Code");
            Button NameButt22("By Name");
            Button TypeButt22("By Type");
            Button UnitButt22("By Unit");
            
        Button BubbleButt2("Bubble");
            Button CodeButt23("By Code");
            Button NameButt23("By Name");
            Button TypeButt23("By Type");
            Button UnitButt23("By Unit");
            
        Button QuickButt2("Quick");
            Button CodeButt24("By Code");
            Button NameButt24("By Name");
            Button TypeButt24("By Type");
            Button UnitButt24("By Unit");
        
    Button FindButt("Find");
        Button BinaryButt("Binary");
            Button CodeButt31("By Code");
            Button NameButt31("By Name");
            Button TypeButt31("By Type");
            Button UnitButt31("By Unit");
            
        Button FrontEndButt("FrontEnd");
            Button CodeButt32("By Code");
            Button NameButt32("By Name");
            Button TypeButt32("By Type");
            Button UnitButt32("By Unit");
        
    Button StatisticalButt("Statistical");
    Button ExitButt("Exit");
    
    
    Frame startframe(0,0);
    
    startframe.addButton(ManageButt);
    startframe.addButton(PrintButt);
    startframe.addButton(SoftButt);
    startframe.addButton(FindButt);
    startframe.addButton(StatisticalButt);
    startframe.addButton(ExitButt);
    
    startframe.ArrItem[0].settouch(true);
    startframe.gamerender();
    while(!startframe.getendgame())
    {
        startframe.gameloop();
        
        if(startframe.ArrItem[0].getselect())
            {               
                Frame manageframe(startframe.ArrItem[0].getx()-1, startframe.ArrItem[0].gety()+1);
                manageframe.addButton(NewButt0);
                manageframe.addButton(EditButt0);
                manageframe.addButton(DeleteButt0);
                
                manageframe.ArrItem[0].settouch(true);
                manageframe.gamerender();
                while(!manageframe.getendgame())
                {
                    manageframe.gameloop();
                    if(manageframe.ArrItem[0].getselect())
                    {   
                        SetBGColor(0);
                        ShowCur(true);  
                        newDevice(&pointer,inum);
                        ShowCur(false);
                        Clear(0, 5, 118, 10, 0);
                        ShowScreen(pointer,inum);
                        manageframe.ArrItem[0].setselect(false);
                    }
                    
                    if(manageframe.ArrItem[1].getselect())
                    {   
                        SetBGColor(0);
                        editDevice();
                        ShowScreen(pointer,inum);
                        manageframe.ArrItem[1].setselect(false);
                    }
                    
                    if(manageframe.ArrItem[2].getselect())
                    {   
                        SetBGColor(0);
                        deleteDevice(&pointer,inum);
                        ShowScreen(pointer,inum);
                        manageframe.ArrItem[2].setselect(false);
                    }
                }
                startframe.ArrItem[0].setselect(false);
            }
        
        if(startframe.ArrItem[1].getselect())
            {   
                SetBGColor(0);
                PRINT(&pointer,inum);
                ShowScreen(pointer,inum);
                startframe.ArrItem[1].setselect(false);
            }
        
        if(startframe.ArrItem[2].getselect())
            {               
                Frame sortframe(startframe.ArrItem[2].getx()-1, startframe.ArrItem[2].gety()+1);
                sortframe.addButton(SelectButt2);
                sortframe.addButton(InsertButt2);
                sortframe.addButton(BubbleButt2);
                sortframe.addButton(QuickButt2);
                
                sortframe.ArrItem[0].settouch(true);
                sortframe.gamerender();
                while(!sortframe.getendgame())
                {
                    sortframe.gameloop();
                    
                    if(sortframe.ArrItem[0].getselect())
                    {               
                        Frame selectframe(sortframe.ArrItem[0].getx()-1, sortframe.ArrItem[0].gety()+1);
                        selectframe.addButton(CodeButt21);
                        selectframe.addButton(NameButt21);                        
                        selectframe.addButton(TypeButt21);                        
                        selectframe.addButton(UnitButt21);  
                                          
                        selectframe.ArrItem[0].settouch(true);
                        selectframe.gamerender();
                        while(!selectframe.getendgame())
                        {
                            selectframe.gameloop();
                            if(selectframe.ArrItem[0].getselect())
                            {
                                SelectionCode();
                                ShowScreen(pointer,inum);
                                selectframe.ArrItem[0].setselect(false);
                            }
                            if(selectframe.ArrItem[1].getselect())
                            {
                                SelectionName();
                                ShowScreen(pointer,inum);
                                selectframe.ArrItem[1].setselect(false);
                            }
                            if(selectframe.ArrItem[2].getselect())
                            {
                                SelectionType();
                                ShowScreen(pointer,inum);
                                selectframe.ArrItem[2].setselect(false);
                            }
                            if(selectframe.ArrItem[3].getselect())
                            {
                                SelectionUnit();
                                ShowScreen(pointer,inum);
                                selectframe.ArrItem[3].setselect(false);
                            }
                        }                        
                        sortframe.ArrItem[0].setselect(false);
                    }
                    
                    if(sortframe.ArrItem[1].getselect())
                    {               
                        Frame insertframe(sortframe.ArrItem[1].getx()-1, sortframe.ArrItem[1].gety()+1);
                        insertframe.addButton(CodeButt22);
                        insertframe.addButton(NameButt22);                        
                        insertframe.addButton(TypeButt22);                        
                        insertframe.addButton(UnitButt22);  
                           
                        insertframe.ArrItem[0].settouch(true);
                        insertframe.gamerender();
                        while(!insertframe.getendgame())
                        {
                            insertframe.gameloop();
                            if(insertframe.ArrItem[0].getselect())
                            {
                                InsertionCode();
                                ShowScreen(pointer,inum);
                                insertframe.ArrItem[0].setselect(false);
                            }
                            if(insertframe.ArrItem[1].getselect())
                            {
                                InsertionName();
                                ShowScreen(pointer,inum);
                                insertframe.ArrItem[1].setselect(false);
                            }
                            if(insertframe.ArrItem[2].getselect())
                            {
                                InsertionType();
                                ShowScreen(pointer,inum);
                                insertframe.ArrItem[2].setselect(false);
                            }
                            if(insertframe.ArrItem[3].getselect())
                            {
                                InsertionUnit();
                                ShowScreen(pointer,inum);
                                insertframe.ArrItem[3].setselect(false);
                            }
 
                        }                        
                        sortframe.ArrItem[1].setselect(false);
                    }
                    
                    if(sortframe.ArrItem[2].getselect())
                    {               
                        Frame bubbleframe(sortframe.ArrItem[2].getx()-1, sortframe.ArrItem[2].gety()+1);
                        bubbleframe.addButton(CodeButt23);
                        bubbleframe.addButton(NameButt23);                        
                        bubbleframe.addButton(TypeButt23);                        
                        bubbleframe.addButton(UnitButt23);  
                                
                        bubbleframe.ArrItem[0].settouch(true);
                        bubbleframe.gamerender();
                        while(!bubbleframe.getendgame())
                        {
                            bubbleframe.gameloop();
                            
                            if(bubbleframe.ArrItem[0].getselect())
                            {
                                BubbleCode();
                                ShowScreen(pointer,inum);
                                bubbleframe.ArrItem[0].setselect(false);
                            }
                            
                            if(bubbleframe.ArrItem[1].getselect())
                            {
                                BubbleName();
                                ShowScreen(pointer,inum);
                                bubbleframe.ArrItem[1].setselect(false);
                            }
                            if(bubbleframe.ArrItem[2].getselect())
                            {
                                BubbleType();
                                ShowScreen(pointer,inum);
                                bubbleframe.ArrItem[2].setselect(false);
                            }
                            if(bubbleframe.ArrItem[3].getselect())
                            {
                                BubbleUnit();
                                ShowScreen(pointer,inum);
                                bubbleframe.ArrItem[3].setselect(false);
                            }
                        }                        
                        sortframe.ArrItem[2].setselect(false);
                    }
                    
                    if(sortframe.ArrItem[3].getselect())
                    {               
                        Frame quickframe(sortframe.ArrItem[3].getx()-1, sortframe.ArrItem[3].gety()+1);
                        quickframe.addButton(CodeButt24);
                        quickframe.addButton(NameButt24);                        
                        quickframe.addButton(TypeButt24);                        
                        quickframe.addButton(UnitButt24);  
                        
                        quickframe.ArrItem[0].settouch(true);
                        quickframe.gamerender();
                        while(!quickframe.getendgame())
                        {
                            quickframe.gameloop();
                            if(quickframe.ArrItem[0].getselect())
                            {
                                QuickCode();
                                ShowScreen(pointer,inum);
                                quickframe.ArrItem[0].setselect(false);
                            }
                            if(quickframe.ArrItem[1].getselect())
                            {
                                QuickName();
                                ShowScreen(pointer,inum);
                                quickframe.ArrItem[1].setselect(false);
                            }
                            if(quickframe.ArrItem[2].getselect())
                            {
                                QuickType();
                                ShowScreen(pointer,inum);
                                quickframe.ArrItem[2].setselect(false);
                            }
                            if(quickframe.ArrItem[3].getselect())
                            {
                                QuickUnit();
                                ShowScreen(pointer,inum);
                                quickframe.ArrItem[3].setselect(false);
                            }
                        }                        
                        sortframe.ArrItem[3].setselect(false);
                    }
                }
                startframe.ArrItem[2].setselect(false);

            }
        
        if(startframe.ArrItem[3].getselect())
        {   
            Frame findframe(startframe.ArrItem[3].getx()-1, startframe.ArrItem[3].gety()+1);
            findframe.addButton(BinaryButt);
            findframe.addButton(FrontEndButt);
                
            findframe.ArrItem[0].settouch(true);
            findframe.gamerender();
            while(!findframe.getendgame())
            {
                findframe.gameloop();
                    
                if(findframe.ArrItem[0].getselect())
                {               
                        Frame binaryframe(findframe.ArrItem[0].getx()-1, findframe.ArrItem[0].gety()+1);
                        binaryframe.addButton(CodeButt31);
                        binaryframe.addButton(NameButt31);                        
                        binaryframe.addButton(TypeButt31);                        
                        binaryframe.addButton(UnitButt31);  
                                          
                        binaryframe.ArrItem[0].settouch(true);
                        binaryframe.gamerender();
                        while(!binaryframe.getendgame())
                        {
                            binaryframe.gameloop();
                            if(binaryframe.ArrItem[0].getselect())
                            {
                                BinaryCode();
                                binaryframe.ArrItem[0].setselect(false);
                            }
                            if(binaryframe.ArrItem[1].getselect())
                            {
                                BinaryName();
                                binaryframe.ArrItem[1].setselect(false);
                            }
                        }
                        findframe.ArrItem[0].setselect(false);
                }
                
                if(findframe.ArrItem[1].getselect())
                {               
                        Frame frontendframe(findframe.ArrItem[1].getx()-1, findframe.ArrItem[1].gety()+1);
                        frontendframe.addButton(CodeButt32);
                        frontendframe.addButton(NameButt32);                        
                        frontendframe.addButton(TypeButt32);                        
                        frontendframe.addButton(UnitButt32);  
                                          
                        frontendframe.ArrItem[0].settouch(true);
                        frontendframe.gamerender();
                        while(!frontendframe.getendgame())
                        {
                            frontendframe.gameloop();
                            if(frontendframe.ArrItem[0].getselect())
                            {
                                FontEndCode(pointer,inum);
                                frontendframe.ArrItem[0].setselect(false);
                            }
                            if(frontendframe.ArrItem[1].getselect())
                            {
                                FrontEndName();
                                frontendframe.ArrItem[1].setselect(false);
                            }
                            if(frontendframe.ArrItem[2].getselect())
                            {
                                FrontEndType();
                                frontendframe.ArrItem[2].setselect(false);
                            }
                            if(frontendframe.ArrItem[3].getselect())
                            {
                                FrontEndUnit();
                                frontendframe.ArrItem[3].setselect(false);
                            }
                            
                        }
                        Clear(tablex, tabley, tablex+117, tabley+inum, 0);
                        findframe.ArrItem[1].setselect(false);
                }
            }
            
            
            
            startframe.ArrItem[3].setselect(false);
        }
        
        if(startframe.ArrItem[5].getselect())
        {   
            break;
        }
    
    }
}


#endif /* MENUFUNCTION_H */

