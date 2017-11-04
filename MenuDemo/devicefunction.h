#pragma once
#include "device.h"
#include "fstream"
#include "stdlib.h"

#define tablex 2
#define tabley 8
#define MAX 30

Device *pointer;
int inum = 0;

void newDevice(Device **poiter, int &inum);
void deleteDevice(Device **poiter, int &inum);
Device pushDevice(Device **poiter, int &inum);
Device * Transfor(Device *poiter);
int Sync(Device **poiter,int &inum);
int Backup(Device *poiter,int inum);
int PRINT(Device **poiter,int inum);
void ShowScreen(Device *pointer, int inum);
void Clear(int x1, int y1, int x2, int y2, int BGC);
void editDevice();

void newDevice(Device **poiter, int &inum)
{
    Device *temp = new Device();
    temp->setInformation();
    temp->setnext((*poiter));
    (*poiter) = temp;
    inum++;
}

void deleteDevice(Device **poiter, int &inum)
{
    int idel = 1;
    int y = tabley+1;
    
    gotoxy(tablex-2,y);cout<<">>";
    bool exitwhile = true;
    while(exitwhile)
    {
        char c = getch();
        if (c == -32) c = getch();
        switch (c) 
        {
            case 72://len
                gotoxy(tablex-2,y);cout<<"  ";
                y--;
                if(y == tabley)
                {
                    y = tabley + inum;
                    idel = inum + 1;
                }
                gotoxy(tablex-2,y);cout<<">>";
                --idel;
                break;
            case 80: //xuong
                gotoxy(tablex-2,y);cout<<"  ";
                y++;
                if(y == tabley + inum + 1)
                {
                    y = tabley + 1;
                    idel = 0;
                }
                gotoxy(tablex-2,y);cout<<">>";
                ++idel;
                break;
            case 13: //enter
                exitwhile = false;
                break;
        }
    }    
    gotoxy(tablex-2,y);cout<<"  ";

    if(idel==1)
    {
        Device *temp;
        temp = (*poiter);
        (*poiter) = temp->Next();
        free(temp);
    }
    else
    {
        Device *temp1, *temp2;
        temp1 = (*poiter);
        temp2 = temp1->Next();
        for(int i = 1; i<idel-1; i++)
        {
            temp1 = temp1->Next();
            temp2 = temp2->Next();
        }
        temp1->setnext(temp2->Next());
        free(temp2);
    }
    inum--;
}

Device pushDevice(Device **poiter, int &inum)
{
    Device *temp;
    temp = (*poiter);
    (*poiter) = (*poiter)->Next();
    inum --;
    return *temp;
}

Device * Transfor(Device *poiter)
{
    Device *temp;
    Device *temp1, *temp2;
    temp1 = poiter;
    temp2 = temp1->Next();
    for(int i = 1; i<inum-1; i++)
    {
        temp1->setnext(temp);
        temp = temp1;
        temp1 = temp2;
        temp2 = temp2->Next();
    }
    temp1->setnext(temp);
    temp = temp1;
    temp2->setnext(temp);
    temp = temp2;
    return temp;
}

int Backup(Device *poiter,int inum)
{
    ofstream outFile("DataBase.txt");
    Device *temp;
    temp = Transfor(poiter);
    
    for(int i = inum; i > 0; i--)
    {   
        outFile<< temp->Type() <<endl;
        outFile<< temp->Code() <<endl;
        outFile<< temp->Type() <<endl;
        outFile<< temp->Detail() <<endl;
        outFile<< temp->Cday()<<endl<<temp->Cmonth()<<endl<<temp->Cyear()<<endl;
        outFile<< temp->Uday()<<endl<<temp->Umonth()<<endl<<temp->Uyear()<<endl;
        outFile<< temp->Unit() <<endl;
        outFile<< temp->Cost() <<endl;        
        if(i == 1)
        outFile<< temp->Note();
        else
        outFile<< temp->Note() <<endl;        
        temp = temp->Next();           
    }
    outFile.close();
    return -1;
}

int Sync(Device **poiter,int &inum)
{
    ifstream inFile("DataBase.txt");
    
    if(inFile.fail())
    {
        cout<<"Fail to open the file!"<<endl;
        return -1;
    }
    
    while (!inFile.eof())
    {
        Device * temp = new Device();
	char ctemp[255];
        int itemp;
        
        inFile.getline(ctemp, 255);
        string line = ctemp;
        temp->setname(line);
        
        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setcode(itemp);
        
        inFile.getline(ctemp, 255);
        line = ctemp;
        temp->settype(line);
        
        inFile.getline(ctemp, 255);
        line = ctemp;
        temp->setdetail(line);
                
        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setcday(itemp);

        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setcmonth(itemp);
        
        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setcyear(itemp);
        
        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setuday(itemp);
        
        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setumonth(itemp);
        
        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setuyear(itemp);

        inFile.getline(ctemp, 255);
        line = ctemp;
        temp->setunit(line);
        
        inFile.getline(ctemp, 255);
        itemp = atoi(ctemp);
        temp->setcost(itemp);
        
        inFile.getline(ctemp, 255);
        line = ctemp;
        temp->setnote(line);
       
        temp->setnext((*poiter));
        (*poiter) = temp;
        
        inum++;
    }
    
    inFile.close();
}

int PRINT(Device **poiter,int inum)
{
    ofstream outFile("PRINT.txt");
    
    Device *temp;
    temp = (*poiter);
    
    for(int i = 1; i <= inum; i++)
    {   
        outFile<<i<<endl;
        outFile<<"Name: " <<temp->Type() <<endl;
        outFile<<"Code: " <<temp->Code() <<endl;
        outFile<<"Type: " <<temp->Type() <<endl;
        outFile<<"Detail: " <<temp->Detail() <<endl;
        outFile<<"Creation Date: " <<temp->Cday()<<" "<<temp->Cmonth()<<" "<<temp->Cyear()<<endl;
        outFile<<"Using Date:    " <<temp->Uday()<<" "<<temp->Umonth()<<" "<<temp->Uyear()<<endl;
        outFile<<"Unit: " <<temp->Unit() <<endl;
        outFile<<"Cost: " <<temp->Cost() <<"$" <<endl;     
        outFile<<"Note: " <<temp->Note() <<endl;        
        temp = temp->Next();           
    }
    outFile.close();
    return -1;
}

void ShowScreen(Device *pointer, int inum)
{   
    
    Device* temp;
    temp = pointer;
    int x = tablex, y = tabley;
    Clear(x, y, x+117,y+inum+2, 4);
    gotoxy(x,y);
    for(int i = 0; i<118; i++)
    {
        cout<<" ";
    }
    gotoxy(x,y);cout<<"NAME";x+=17;
    gotoxy(x,y);cout<<"|CODE";x+=7;
    gotoxy(x,y);cout<<"|TYPE";x+=8;
    gotoxy(x,y);cout<<"|DETAIL";x+=27;
    gotoxy(x,y);cout<<"|CREATION";x+=11;
    gotoxy(x,y);cout<<"|USING";x+=11;
    gotoxy(x,y);cout<<"|UNIT";x+=10;
    gotoxy(x,y);cout<<"|COST";x+=7;
    gotoxy(x,y);cout<<"|NOTE";
    x = tablex, y++;
    
    SetBGColor(2);
    for(int i = 0 ; i< inum ; i++)
    {
        gotoxy(x,y);
        for(int i = 0; i<118; i++)
        {
        cout<<" ";
        }
        y++;
    }
    y-=inum;
    for(int i = 0 ; i< inum; i++)
    {
        temp->show(x,y);
        y++;
        temp = temp->Next();
    }
    cout<<endl;
    SetBGColor(0);
}

void Clear(int x1, int y1, int x2, int y2, int BGC)
{
    SetBGColor(0);
    for(int i = x1 ; i<= x2; i++)
    {
        for(int j = y1; j<= y2; j++)
        {
            gotoxy(i, j);
            cout<<" ";
        }
    }
    SetBGColor(BGC);
}


void editDevice()
{
    int idel = 1;
    int y = tabley+1; 
    gotoxy(tablex-2,y);cout<<">>";
    bool exitwhile = true;
    while(exitwhile)
    {
        char c = getch();
        if (c == -32) c = getch();
        switch (c) 
        {
            case 72://len
                gotoxy(tablex-2,y);cout<<"  ";
                y--;
                if(y == tabley)
                {
                    y = tabley + inum;
                    idel = inum + 1;
                }
                gotoxy(tablex-2,y);cout<<">>";
                --idel;
                break;
            case 80: //xuong
                gotoxy(tablex-2,y);cout<<"  ";
                y++;
                if(y == tabley + inum + 1)
                {
                    y = tabley + 1;
                    idel = 0;
                }
                gotoxy(tablex-2,y);cout<<">>";
                ++idel;
                break;
            case 13: //enter
                exitwhile = false;
                break;
        }
    }    

    
    Device *temp;
    temp = pointer;
    for(int i = 1; i<idel; i++)
    {
        temp = temp->Next();
    }
    temp->editInformation(tablex,y);
    SetBGColor(0);
    gotoxy(tablex-2,y);cout<<"  ";
}
