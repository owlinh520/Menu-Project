#include <cstdlib>
#include "iostream"
#include "menufunction.h"
#include "devicefunction.h"
#include "softfunction.h"

int main(int argc, char** argv) 
{
    ShowCur(false);
    Sync(&pointer,inum);
    ShowScreen(pointer,inum);
    Control();
//    Backup(pointer,inum);
    getch();
    return 0;
}
