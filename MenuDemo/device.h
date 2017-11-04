#ifndef DEVICE_H
#define DEVICE_H
#include "string"
#include "iostream"
using namespace std;

class Device
{
    
    
private:
    string name;
    int code;
    string type;
    string detail;
    int cday;
    int cmonth;
    int cyear;
    int uday;
    int umonth;
    int uyear;
    string unit;
    int cost;
    string note;
    
    Device * next;
    
public:
    
    
    Device();
    Device(int num);
    
    
    
    void setname(string name);
    void setcode(int code);
    void settype(string type);
    void setdetail(string detail);
    void setcday(int cday);
    void setcmonth(int cmonth);
    void setcyear(int cyear);
    void setuday(int uday);
    void setumonth(int umonth);
    void setuyear(int uyear);
    void setunit(string unit);
    void setcost(int cost);
    void setnote(string note);
    void setnext(Device * const other);
    void setInformation();
    void setInformation(int x, int y);
    void editInformation(int x, int y);
    
    string Name();
    int Code();
    string Type();
    string Detail();
    int Cday();
    int Cmonth();
    int Cyear();
    int Uday();
    int Umonth();
    int Uyear();
    string Unit();
    int Cost();
    string Note();
    
    Device * Next() const;
    
    void show(int, int);
    
};

Device::Device()
{
    this->next = 0;
}



void Device::setname(string name)
{
    this->name = name;
}
void Device::setcode(int code)
{
    this->code = code;
}
void Device::settype(string type)
{
    this->type = type;
}
void Device::setdetail(string detail)
{
    this->detail = detail;
}
void Device::setcday(int cday)
{
    this->cday = cday;
}
void Device::setcmonth(int cmonth)
{
    this->cmonth = cmonth;
}
void Device::setcyear(int cyear)
{
    this->cyear = cyear;
}
void Device::setuday(int uday)
{
    this->uday = uday;
}
void Device::setumonth(int umonth)
{
    this->umonth = umonth;
}
void Device::setuyear(int uyear)
{
    this->uyear = uyear;
}
void Device::setunit(string unit)
{
    this->unit = unit;
}
void Device::setcost(int cost)
{
    this->cost = cost;
}
void Device::setnote(string note)
{
    this->note = note;
}
void Device::setnext(Device * const other)
{
    this->next = other;
}

void Device::setInformation()
{   
    SetBGColor(0);
    int x = 1, y = 5;
    gotoxy(x,y);cout<<"NAME";x+=17;
    gotoxy(x,y);cout<<"|CODE";x+=7;
    gotoxy(x,y);cout<<"|TYPE";x+=8;
    gotoxy(x,y);cout<<"|DETAIL";x+=27;
    gotoxy(x,y);cout<<"|CREATION";x+=11;
    gotoxy(x,y);cout<<"|USING";x+=11;
    gotoxy(x,y);cout<<"|UNIT";x+=10;
    gotoxy(x,y);cout<<"|COST";x+=7;
    gotoxy(x,y);cout<<"|NOTE";
    
    
    x = 1;y++;
    
    gotoxy(x,y);fflush(stdin); getline(cin,name);x+=17;
    gotoxy(x,y);cout<<"|";cin>>code;x+=7;
    gotoxy(x,y);cout<<"|";cin>>type;x+=8;
    gotoxy(x,y);cout<<"|";fflush(stdin); getline(cin,detail);x+=27;
    gotoxy(x,y);cout<<"|";cin>>cday; cin>>cmonth;cin>>cyear;x+=11;
    gotoxy(x,y);cout<<"|";cin>>uday;cin>>umonth;cin>>uyear;x+=11;
    gotoxy(x,y);cout<<"|";cin>>unit;x+=10;
    gotoxy(x,y);cout<<"|";cin>>cost;x+=7;
    gotoxy(x,y);cout<<"|";fflush(stdin); getline(cin,note);
    
}

void Device::editInformation(int x, int y)
{
    int iselect = 1;
    SetBGColor(2);
    gotoxy(x,y);cout<<">";

    bool exitwhile = true;
    while(exitwhile)
    {
        char c = getch();
        if (c == -32) c = getch();
        switch (c) 
        {
            case 75://trai
                --iselect;
                if(iselect < 1) iselect = 9;
                break;
            case 77: //phai
                ++iselect;
                if(iselect > 9) iselect = 1;
                break;
            case 13: //enter
                exitwhile = false;
                break;
        }

        switch(iselect)
        {
            case 1:
                gotoxy(x+98,y);cout<<"|";
                gotoxy(x+17,y);cout<<"|";
                gotoxy(x,y);cout<<">";
                break;
            case 2:
                gotoxy(x,y);cout<<"|";
                gotoxy(x+24,y);cout<<"|";
                gotoxy(x+17,y);cout<<">";
                break;
            case 3:
                gotoxy(x+17,y);cout<<"|";
                gotoxy(x+32,y);cout<<"|";
                gotoxy(x+24,y);cout<<">";
                break;
            case 4:
                gotoxy(x+24,y);cout<<"|";
                gotoxy(x+59,y);cout<<"|";
                gotoxy(x+32,y);cout<<">";
                break;
            case 5:
                gotoxy(x+70,y);cout<<"|";
                gotoxy(x+32,y);cout<<"|";
                gotoxy(x+59,y);cout<<">";
                break;
            case 6:
                gotoxy(x+59,y);cout<<"|";
                gotoxy(x+81,y);cout<<"|";
                gotoxy(x+70,y);cout<<">";
                break;
            case 7:
                gotoxy(x+70,y);cout<<"|";
                gotoxy(x+91,y);cout<<"|";
                gotoxy(x+81,y);cout<<">";
                break;
            case 8:
                gotoxy(x+81,y);cout<<"|";
                gotoxy(x+98,y);cout<<"|";
                gotoxy(x+91,y);cout<<">";
                break;
            case 9:
                gotoxy(x+91,y);cout<<"|";
                gotoxy(x,y);cout<<"|";
                gotoxy(x+98,y);cout<<">";
                break;
        }
    }    

    switch(iselect)
    {
        case 1:
            gotoxy(x,y);cout<<"|";
            for(int i = 1; i < 17; i++)
            {
                gotoxy(x+i,y);
                cout<<" ";
            }
            gotoxy(x+1,y);fflush(stdin);getline(cin,name);
            break;
        case 2:
            gotoxy(x+17,y);cout<<"|";
            for(int i = 1; i < 7; i++)
            {
                gotoxy(x+17+i,y);
                cout<<" ";
            }
            gotoxy(x+18,y);cin>>code;
            break;
        case 3:
            gotoxy(x+24,y);cout<<"|";
            for(int i = 1; i < 8; i++)
            {
                gotoxy(x+24+i,y);
                cout<<" ";
            }
            gotoxy(x+25,y);cin>>type;
            break;
        case 4:
            gotoxy(x+32,y);cout<<"|";
            for(int i = 1; i < 27; i++)
            {
                gotoxy(x+32+i,y);
                cout<<" ";
            }
            gotoxy(x+33,y);fflush(stdin); getline(cin,detail);
            break;
        case 5:
            gotoxy(x+59,y);cout<<"|";
            for(int i = 1; i < 11; i++)
            {
                gotoxy(x+59+i,y);
                cout<<" ";
            }
            gotoxy(x+60,y);cin>>cday; cin>>cmonth;cin>>cyear;
            break;
        case 6:
            gotoxy(x+70,y);cout<<"|";
            for(int i = 1; i < 11; i++)
            {
                gotoxy(x+70+i,y);
                cout<<" ";
            }
            gotoxy(x+71,y);cin>>uday;cin>>umonth;cin>>uyear;
            break;
        case 7:
            gotoxy(x+81,y);cout<<"|";
            for(int i = 1; i < 10; i++)
            {
                gotoxy(x+81+i,y);
                cout<<" ";
            }
            gotoxy(x+82,y);cin>>unit;
            break;
        case 8:
            gotoxy(x+91,y);cout<<"|";
            for(int i = 1; i < 7; i++)
            {
                gotoxy(x+91+i,y);
                cout<<" ";
            }
            gotoxy(x+92,y);cin>>code;
            break;
        case 9:
            gotoxy(x+98,y);cout<<"|";
            for(int i = 1; i < 20; i++)
            {
                gotoxy(x+98+i,y);
                cout<<" ";
            }
            gotoxy(x+99,y);fflush(stdin); getline(cin,note);
            break;
    }

}


string Device::Name()
{
    return name;
}
int Device::Code()
{
    return code;
}
string Device::Type()
{
    return type;
}
string Device::Detail()
{
    return detail;
}
int Device::Cday()
{
    return cday;
}
int Device::Cmonth()
{
    return cmonth;
}
int Device::Cyear()
{
    return cyear;
}
int Device::Uday()
{
    return uday;
}
int Device::Umonth()
{
    return umonth;
}
int Device::Uyear()
{
    return uyear;
}
string Device::Unit()
{
    return unit;
}
int Device::Cost()
{
    return cost;
}
string Device::Note()
{
    return note;
}

Device * Device::Next() const
{
    return next;
}

void Device::show(int x, int y)
{
    gotoxy(x,y);cout<<"|"<<name;x+=17;
    gotoxy(x,y);cout<<"|"<<code;x+=7;
    gotoxy(x,y);cout<<"|"<<type;x+=8;
    gotoxy(x,y);cout<<"|"<<detail;x+=27;
    gotoxy(x,y);cout<<"|"<<cday<<"/"<<cmonth<<"/"<<cyear;x+=11;
    gotoxy(x,y);cout<<"|"<<uday<<"/"<<umonth<<"/"<<uyear;x+=11;
    gotoxy(x,y);cout<<"|"<<unit;x+=10;
    gotoxy(x,y);cout<<"|"<<cost;x+=7;
    gotoxy(x,y);cout<<"|"<<note;
}

#endif /* DEVICE_H */

