/* 
 * File:   findfunction.h
 * Author: Linh Vu Vu
 *
 * Created on September 15, 2017, 10:10 PM
 */

#ifndef FINDFUNCTION_H
#define FINDFUNCTION_H

#include "devicefunction.h"
//#include "softfunction.h"
#include <algorithm>

void FrontEndStr(int &iname1, int &iname2, string sdev1, string sdev2, Device **temp, Device **tempptr, int &icount);
void FontEndCode(Device *pointer, int inum);
void FrontEndName();
void FrontEndType();
void FrontEndUnit();

void FontEndCode(Device *pointer, int inum)
{
    SetBGColor(0);
    int code;
    gotoxy(tablex, tabley-2);cout<<"Code: ";cin>>code;
    Device* temp;
    Device* tempptr;
    temp = pointer;
    int icount = 0;
    
    for(int i = 0; i<inum; i++)
    {
        if(temp->Code() == code)
        {
            ++icount;
            Device *dtemp = new Device();
            *dtemp = *temp;
            dtemp->setnext(tempptr);
            tempptr = dtemp;
        }
        temp = temp->Next();
    }
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    if(icount != 0) ShowScreen(tempptr, icount);   
}

void FrontEndStr(int &iname1, int &iname2, string sdev1, string sdev2, Device **temp, Device **tempptr, int &icount)
{
    transform(sdev1.begin(), sdev1.end(), sdev1.begin(), ::tolower);
    transform(sdev2.begin(), sdev2.end(), sdev2.begin(), ::tolower);
    std::size_t found = sdev1.find(sdev2);
    if(found!=std::string::npos)
    {
        ++icount;
        Device *dtemp = new Device();
        *dtemp = *(*temp);
        dtemp->setnext((*tempptr));
        *tempptr = dtemp;
    }
    (*temp) = (*temp)->Next();
}

void FrontEndName()
{
    SetBGColor(0);
    string name;
    gotoxy(tablex, tabley-2);cout<<"Name: ";fflush(stdin);getline(cin,name);
    
    int icount = 0;
    Device* temp;
    Device* tempptr;
    temp = pointer;
    for(int i = 0; i<inum; i++)
    {
        int iname1, iname2;
        FrontEndStr(iname1,iname2,temp->Name(),name,&temp,&tempptr,icount);        
    }
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    if(icount != 0) ShowScreen(tempptr, icount);
}

void FrontEndType()
{
    SetBGColor(0);
    string type;
    gotoxy(tablex, tabley-2);cout<<"Type: ";fflush(stdin);getline(cin,type);
    
    int icount = 0;
    Device* temp;
    Device* tempptr;
    temp = pointer;
    for(int i = 0; i<inum; i++)
    {
        int iname1, iname2;
        FrontEndStr(iname1,iname2,temp->Type(),type,&temp,&tempptr,icount);        
    }
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    if(icount != 0) ShowScreen(tempptr, icount);
}

void FrontEndUnit()
{
    SetBGColor(0);
    string unit;
    gotoxy(tablex, tabley-2);cout<<"Unit: ";fflush(stdin);getline(cin,unit);
    
    int icount = 0;
    Device* temp;
    Device* tempptr;
    temp = pointer;
    for(int i = 0; i<inum; i++)
    {
        int iname1, iname2;
        FrontEndStr(iname1,iname2,temp->Unit(),unit,&temp,&tempptr,icount);        
    }
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    if(icount != 0) ShowScreen(tempptr, icount);
}

int BinarySearchCode(Device *Arr, int inum) 
{
    int left = 0;
    int right = inum - 1;
    int code;
    SetBGColor(0);
    gotoxy(tablex, tabley-2);cout<<"Code: ";cin>>code;
    while (left < right) 
    {
        int mid = (left + right) / 2;
        if(left == inum - 2)
        {
            if(Arr[left].Code() == code) return left;
            if(Arr[right].Code() == code) return right;
        }
        else
        if (code == Arr[mid].Code())
        {
            return mid;
        }
        else if (code > Arr[mid].Code())
          right = mid;
        else if (code < Arr[mid].Code())
          left = mid;
    }
    if(left == right && Arr[left].Code() == code) return left;
    else return -1;
}

void BinaryCode()
{
    //Bubble Code Sort
    Device Arr[MAX];
    Device* tempptr;
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);      
    }

    for(int i = 0; i < i_num - 1; i++)
    {
        for(int j = 0; j < i_num - 1; j++)
        {
            if(Arr[j].Code() < Arr[j+1].Code())
            {
                Swap(Arr[j],Arr[j+1]);
            }
        }
    }   
    
    MakeStack(Arr,i_num);
    int k = BinarySearchCode(Arr,inum);
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    
    if(k != -1 )
    {
        tempptr = &Arr[k];
        ShowScreen(tempptr,1);
    }
}

void BinaryMakeStack(int start, int end, Device *Arr)
{
    int icount = 0;
    Device *tempptr;
    for(int i = start; i<= end; i++)
    {
        Device *temp = new Device();
        *temp = Arr[i];
        temp->setnext(tempptr);
        tempptr = temp;
        icount++;
    }   
    ShowScreen(tempptr,icount);
}

int BinaryCompareStr(string sdev1, string sdev2)
{
        int icount = 0, ilength;
        int iname1 = (int)sdev1[icount];
        int iname2 = (int)sdev2[icount];
        if(sdev1.length() < sdev2.length())
            ilength = sdev1.length();
        else
            ilength = sdev2.length();

        while(iname1 == iname2 && icount < ilength - 1)
        {
            icount++;
            iname1+=(int)sdev1[icount];
            iname2+=(int)sdev2[icount];
        } 
        if(iname1 == iname2 && sdev1.length() >= sdev2.length())
        {
            return 0;
        }
        else      
        if(iname1 < iname2)
        {
            return -1;
        }
        else return 1;
}

int BinarySearchName(Device *Arr, int inum, string &name) 
{
    int left = 0;
    int right = inum - 1;
    
    while (left < right) 
    {
        int mid = (left + right) / 2;
        if(left == inum - 2)
        {
            if(BinaryCompareStr(Arr[left].Name(), name) == 0) return left;
            if(BinaryCompareStr(Arr[right].Name(), name) == 0) return right;
        }
        else
        
            if (BinaryCompareStr(Arr[mid].Name(), name) == 0)
            {
                return mid;
            }
            else if (BinaryCompareStr(Arr[mid].Name(), name) == -1)
                left = mid+1;
            else
                right = mid-1;
        
    }
}

void BinaryName()
{
    string name;
    SetBGColor(0);
    gotoxy(tablex, tabley-2);cout<<"Name: ";fflush(stdin);getline(cin,name);
    //Bubble Name Sort
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    for(int i = 0; i < i_num - 1; i++)
    {
        for(int j = 0; j < i_num - 1; j++)
        {
                CompareStr(Arr[j].Name(), Arr[j+1].Name(), Arr[j], Arr[j+1]);
        }
    }
    MakeStack(Arr,i_num);

    int mid = BinarySearchName(Arr,i_num,name);
    int i = mid, j = mid;
    while(BinaryCompareStr(Arr[i].Name(),name) == 0) i--;
    while(BinaryCompareStr(Arr[j].Name(),name) == 0) j++;
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    BinaryMakeStack(i+1,j-1,Arr);
}

int BinarySearchType(Device *Arr, int inum) 
{
    int left = 0;
    int right = inum - 1;
    string type;
    SetBGColor(0);
    gotoxy(tablex, tabley-2);cout<<"Type: ";fflush(stdin);getline(cin,type);
    while (left < right) 
    {
        int mid = (left + right) / 2;
        if(left == inum - 2)
        {
            if(BinaryCompareStr(Arr[left].Type(), type) == 0) return left;
            if(BinaryCompareStr(Arr[right].Type(), type) == 0) return right;
        }
        else
        if (BinaryCompareStr(Arr[mid].Type(), type) == 0)
        {
            return mid;
        }
        else if (BinaryCompareStr(Arr[right].Type(), type) == -1)
          right = mid;
        else if (BinaryCompareStr(Arr[right].Type(), type) == 1)
          left = mid;
    }
    if(left == right && BinaryCompareStr(Arr[left].Type(), type) == 0) return left;
    else return -1;
}

void BinaryType()
{
    Device* tempptr;
    //Bubble Type Sort
    Device Arr[MAX];
    int iname1, iname2;
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    for(int i = 0; i < i_num - 1; i++)
    {
        for(int j = 0; j < i_num - 1; j++)
        {
                CompareStr(Arr[j].Type(), Arr[j+1].Type(), Arr[j], Arr[j+1]);
        }
    }
    MakeStack(Arr,i_num);
    int k = BinarySearchType(Arr,inum);
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    
    if(k != -1 )
    {
        tempptr = &Arr[k];
        ShowScreen(tempptr,1);
    }
}
int BinarySearchUnit(Device *Arr, int inum) 
{
    int left = 0;
    int right = inum - 1;
    string name;
    SetBGColor(0);
    gotoxy(tablex, tabley-2);cout<<"Unit: ";fflush(stdin);getline(cin,name);
    while (left < right) 
    {
        int mid = (left + right) / 2;
        if(left == inum - 2)
        {
            if(BinaryCompareStr(Arr[left].Type(), name) == 0) return left;
            if(BinaryCompareStr(Arr[right].Type(), name) == 0) return right;
        }
        else
        if (BinaryCompareStr(Arr[mid].Type(), name) == 0)
        {
            return mid;
        }
        else if (BinaryCompareStr(Arr[right].Type(), name) == -1)
          right = mid;
        else if (BinaryCompareStr(Arr[right].Type(), name) == 1)
          left = mid;
    }
    if(left == right && BinaryCompareStr(Arr[left].Type(), name) == 0) return left;
    else return -1;
}

void BinaryUnit()
{
    BubbleUnit();
    Device* tempptr;
    //Bubble Name Sort
    Device Arr[MAX];
    int iname1, iname2;
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
        Arr[i] = pushDevice(&pointer,inum);

    int k = BinarySearchUnit(Arr,inum);
    Clear(tablex, tabley-2, tablex+117, tabley+inum, 0);
    
    if(k != -1 )
    {
        tempptr = &Arr[k];
        ShowScreen(tempptr,1);
    }
}


#endif /* FINDFUNCTION_H */

