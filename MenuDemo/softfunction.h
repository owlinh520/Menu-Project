/* 
 * File:   Soft.h
 * Author: Linh Vu Vu
 *
 * Created on September 12, 2017, 2:10 PM
 */

#ifndef SOFT_H
#define SOFT_H
#include "devicefunction.h"
#include "stdlib.h"

void Swap(Device &dev1, Device &dev2);
void MakeStack(Device Arr[], int i_num);
void CompareStr(string sdev1, string sdev2, Device &dev1, Device &dev2);
void BubbleCode();
void BubbleName();
void BubbleType();
void BubbleUnit();
void SelectionCode();
void SelectionName();
void SelectionType();
void SelectionUnit();
void MakeStackInsert(Device Arr[], int i_num);
void InsertionCode();
void InsertionName();
void InsertionType();
void InsertionUnit();
void QuickSortCode(Device *Arr, int ileft, int iright);
void QuickCode();
void QuickSortName(Device *Arr, int ileft, int iright);
void QuickName();
void QuickSortType(Device *Arr, int ileft, int iright);
void QuickType();
void QuickSortUnit(Device *Arr, int ileft, int iright);
void QuickUnit();


void Swap(Device &dev1, Device &dev2)
{
    Device temp;
    temp = dev1;
    dev1 = dev2;
    dev2 = temp;
}


void MakeStack(Device Arr[], int i_num)
{
    for(int i = 0; i<i_num; i++)
    {
        Device *temp = new Device();
        *temp = Arr[i];
        temp->setnext(pointer);
        pointer = temp;
        inum++;
    }   
}

void CompareStr(string sdev1, string sdev2, Device &dev1, Device &dev2)
{
    if(sdev1.compare(sdev2) == -1)
    Swap(dev1,dev2);
}

void BubbleCode()
{
    Device Arr[MAX];
    int i_num = inum;
    
    for(int i = 0; i < i_num; i++)
    Arr[i] = pushDevice(&pointer,inum);

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
}

void BubbleName()
{
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
}

void BubbleType()
{
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
            CompareStr(Arr[j].Type(), Arr[j+1].Type(), Arr[j], Arr[j+1]);
        }
    }
    MakeStack(Arr,i_num);    
}

void BubbleUnit()
{
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
            CompareStr(Arr[j].Unit(), Arr[j+1].Unit(), Arr[j], Arr[j+1]);
        }
    }
    MakeStack(Arr,i_num);    
}

void SelectionCode()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    for(int i = 0; i < i_num - 1; i++)
    {       
        for(int j = i+1; j < i_num; j++)
        {
            if(Arr[i].Code() < Arr[j].Code())
            {
                Swap(Arr[i],Arr[j]);
            }
        }
    }
        
    MakeStack(Arr,i_num);
}

void SelectionName()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    for(int i = 0; i < i_num - 1; i++)
    {       
        for(int j = i+1; j < i_num; j++)
        {
            CompareStr(Arr[i].Name(), Arr[j].Name(), Arr[i], Arr[j]);
        }
    }
        
    MakeStack(Arr,i_num);
}

void SelectionType()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    for(int i = 0; i < i_num - 1; i++)
    {       
        for(int j = i+1; j < i_num; j++)
        {
            CompareStr(Arr[i].Type(), Arr[j].Type(), Arr[i], Arr[j]);
        }
    }
        
    MakeStack(Arr,i_num);
}

void SelectionUnit()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    for(int i = 0; i < i_num - 1; i++)
    {       
        for(int j = i+1; j < i_num; j++)
        {
            CompareStr(Arr[i].Unit(), Arr[j].Unit(), Arr[i], Arr[j]);
        }
    }
        
    MakeStack(Arr,i_num);
}

void InsertionCode()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);      
    }

    for(int i = 1; i < i_num; i++)
    {
        Device temp;
        temp = Arr[i];
        int j = i-1;
        while(temp.Code() < Arr[j].Code())
        {
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = temp;        
    }  
    
    MakeStackInsert(Arr,i_num);
}

void MakeStackInsert(Device Arr[], int i_num)
{
    for(int i = i_num - 1; i >= 0; i--)
    {
        Device *temp = new Device();
        *temp = Arr[i];
        temp->setnext(pointer);
        pointer = temp;
        inum++;
    }   
}

void InsertionName()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    for(int i = 1; i < i_num; i++)
    {
        Device temp;
        temp = Arr[i];
        int j = i;
        if(temp.Name().compare(Arr[j-1].Name())==-1)
        {
            Arr[j] = Arr[j-1];
            do
            {
                Arr[j] = Arr[j-1];
                if(temp.Name().compare(Arr[j-1].Name())!=-1)
                break;
                --j;
            }while(j>0);
            Arr[j] = temp;   
        }  
    }
    MakeStackInsert(Arr,i_num);
}

void InsertionType()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    for(int i = 1; i < i_num; i++)
    {
        Device temp;
        temp = Arr[i];
        int j = i;
        if(temp.Type().compare(Arr[j-1].Type())==-1)
        {
            Arr[j] = Arr[j-1];
            do
            {
                Arr[j] = Arr[j-1];
                if(temp.Type().compare(Arr[j-1].Type())!=-1)
                break;
                --j;
            }while(j>0);
            Arr[j] = temp;   
        }  
    }
    MakeStackInsert(Arr,i_num);
}
void InsertionUnit()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    for(int i = 1; i < i_num; i++)
    {
        Device temp;
        temp = Arr[i];
        int j = i;
        if(temp.Unit().compare(Arr[j-1].Unit())==-1)
        {
            Arr[j] = Arr[j-1];
            do
            {
                Arr[j] = Arr[j-1];
                if(temp.Unit().compare(Arr[j-1].Unit())!=-1)
                break;
                --j;
            }while(j>0);
            Arr[j] = temp;   
        }  
    }
    MakeStackInsert(Arr,i_num);
}

void QuickSortCode(Device *Arr, int ileft, int iright)
{
	int key = Arr[(ileft+iright)/2].Code();
	int i = ileft, j = iright;
	while(i <= j)
	{
		while(Arr[i].Code() < key) i++;
		while(Arr[j].Code() > key) j--;
		if(i <= j)
		{
			if (i < j)
			Swap(Arr[i], Arr[j]);	
			i++;
			j--;
		}
	}
	if (ileft < j) QuickSortCode(Arr, ileft, j);
	if (i < iright) QuickSortCode(Arr, i, iright);
}

void QuickCode()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    QuickSortCode(Arr, 0, i_num-1);   
    MakeStackInsert(Arr,i_num);
}

void QuickSortName(Device *Arr, int ileft, int iright)
{
	string key = Arr[(ileft+iright)/2].Name();
	int i = ileft, j = iright;
	while(i <= j)
	{	
        while(Arr[i].Name().compare(key) == -1) ++i;
        while(Arr[j].Name().compare(key) == 1) --j;
		if(i <= j)
		{
			if (i < j)
			Swap(Arr[i], Arr[j]);	
			i++;
			j--;
		}
	}
	if (ileft < j) QuickSortName(Arr, ileft, j);
	if (i < iright) QuickSortName(Arr, i, iright);
}

void QuickName()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    QuickSortName(Arr, 0, i_num-1);
    MakeStackInsert(Arr,i_num);
}
void QuickSortUnit(Device *Arr, int ileft, int iright)
{
	string key = Arr[(ileft+iright)/2].Unit();
	int i = ileft, j = iright;
	while(i <= j)
	{
		while(Arr[i].Unit().compare(key) == -1) ++i;
        while(Arr[j].Unit().compare(key) == 1) --j;
		if(i <= j)
		{
			if (i < j)
			Swap(Arr[i], Arr[j]);	
			i++;
			j--;
		}
	}
	if (ileft < j) QuickSortUnit(Arr, ileft, j);
	if (i < iright) QuickSortUnit(Arr, i, iright);
}

void QuickUnit()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    QuickSortUnit(Arr, 0, i_num-1);
    MakeStackInsert(Arr,i_num);
}

void QuickSortType(Device *Arr, int ileft, int iright)
{
	string key = Arr[(ileft+iright)/2].Type();
	int i = ileft, j = iright;
	while(i <= j)
	{
		while(Arr[i].Type().compare(key) == -1) ++i;
        while(Arr[j].Type().compare(key) == 1) --j;
		if(i <= j)
		{
			if (i < j)
			Swap(Arr[i], Arr[j]);	
			i++;
			j--;
		}
	}
	if (ileft < j) QuickSortType(Arr, ileft, j);
	if (i < iright) QuickSortType(Arr, i, iright);
}

void QuickType()
{
    Device Arr[MAX];
    int i_num = inum;
    for(int i = 0; i < i_num; i++)
    {
        Arr[i] = pushDevice(&pointer,inum);
    }
    
    QuickSortType(Arr, 0, i_num-1);
    MakeStackInsert(Arr,i_num);
}
#endif /* SOFT_H */

