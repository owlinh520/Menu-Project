
#pragma once

#ifndef UTIL_H
#define UTIL_H

#define    KEY_A    0x41
#define    KEY_B    0x42
#define    KEY_C    0x43
#define    KEY_D    0x44
#define    KEY_E    0x45
#define    KEY_F    0x46
#define    KEY_G    0x47
#define    KEY_H    0x48
#define    KEY_I    0x49
#define    KEY_J    0x4A
#define    KEY_K    0x4B
#define    KEY_L    0x4C
#define    KEY_M    0x4D
#define    KEY_N    0x4E
#define    KEY_O    0x4F
#define    KEY_P    0x50
#define    KEY_Q    0x51
#define    KEY_R    0x52
#define    KEY_S    0x53
#define    KEY_T    0x54
#define    KEY_U    0x55
#define    KEY_V    0x56
#define    KEY_W    0x57
#define    KEY_X    0x58
#define    KEY_Y    0x59
#define    KEY_Z    0x5A
#define    KEY_LEFT    VK_LEFT
#define    KEY_RIGHT   VK_RIGHT
#define    KEY_UP      VK_UP
#define    KEY_DOWN    VK_DOWN
#define    KEY_ESC     VK_ESCAPE
#define    KEY_DELETE  VK_DELETE
#define    KEY_ENTER   VK_RETURN

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */

#include "windows.h"
#include "stdio.h"
#include "string"
#include "iostream"

using namespace std;

double _tickCount; // Biến đếm thời gian, sử dụng cho Mainloop
 
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); // Lấy handle cửa sổ console hiện hành
 
// Đưa con trỏ đến tọa độ x:y
void gotoxy(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
 
// Đặt màu cho chữ
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
 
// Đặt màu nền cho chữ
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
 
// Thiết lập chế độ hiển thị, có fullscreen hay không
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
    typedef BOOL (WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
    SCDMProc_t SetConsoleDisplayMode;
    HMODULE hKernel32;
    BOOL bFreeLib = FALSE, ret;
    const char KERNEL32_NAME[] = "kernel32.dll";
 
    hKernel32 = GetModuleHandleA(KERNEL32_NAME);
    if (hKernel32 == NULL)
    {
        hKernel32 = LoadLibraryA(KERNEL32_NAME);
        if (hKernel32 == NULL)
            return FALSE;
 
        bFreeLib = true;
    }
 
    SetConsoleDisplayMode =
        (SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
    if (SetConsoleDisplayMode == NULL)
    {
        SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
        ret = FALSE;
    }
    else
    {
        DWORD tmp;
        ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
    }
 
    if (bFreeLib)
        FreeLibrary(hKernel32);
 
    return ret;
}
 
// Đặt chế độ FullScreen
void setFullScreen()
{
    NT_SetConsoleDisplayMode( GetStdHandle( STD_OUTPUT_HANDLE ), 1 );
}
 
// Thoát khỏi fullscreen
void exitFullScreen()
{
    NT_SetConsoleDisplayMode( GetStdHandle( STD_OUTPUT_HANDLE ), 0 );
}
 
// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
 
// Xóa toàn bộ nội dung cửa sổ console - chôm từ MSDN
void cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 };    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;
 
// Get the number of character cells in the current buffer. 
 
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
      return;
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
 
   // Fill the entire screen with blanks.
 
   if( !FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
      dwConSize, coordScreen, &cCharsWritten ))
      return;
 
   // Get the current text attribute.
 
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
      return;
 
   // Set the buffer's attributes accordingly.
 
   if( !FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
      dwConSize, coordScreen, &cCharsWritten ))
      return;
 
   // Put the cursor at its home coordinates.
 
   SetConsoleCursorPosition( hConsole, coordScreen );
}
// Viết lại hàm clrscr, không cần cũng được nhưng để nhìn vào code cho đẹp mắt
void clrscr()
{
    cls(hCon);
}
// Kiểm tra xem phím nào được nhấn, trả về true nếu phím đó đã được nhấn xuống
bool checkKey(int key)
{
    return GetAsyncKeyState(key);
}

// reset lại bộ đếm
void resetTick()
{
    _tickCount = 0;
}
 
// Đếm, thực hiện việc tăng biến đếm
void tickCount()
{
    _tickCount += 0.1;
}
 
// trả về giá trị hiện tại của biến đếm
double getTickCount()
{
    return _tickCount;
}
 
// Thực hiện việc đếm và gọi vòng lặp chính (mainloop)
// Tham số truyền vào gồm có: giá trị cực đại mà sau khi tăng đến mức đó, sẽ gọi tiếp mainloop và renderloop
//        gloop: game loop hay còn gọi là mainloop, thực hiện việc xử lý logic trong game
//        rloop: render loop, thực hiện việc in các hình ảnh, chữ,.. trong game ra màn hình
void Tick(double maxValue, void (*gloop) (), void (*rloop) ())
{
    tickCount();
        if (getTickCount() > maxValue){ 
            resetTick();
            gloop(); // Game loop
        }
    rloop(); // Render loop
}
