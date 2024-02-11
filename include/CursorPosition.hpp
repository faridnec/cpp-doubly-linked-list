/**
* @file CursorPosition.hpp
* @description konsolda koordinat konum
* @course Veri Yapilari 1B
* @assignment 1
* @date 10 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#ifndef CURSORPOSITION_HPP
#define CURSORPOSITION_HPP

#include <windows.h>
static class CursorPosition{
    public:
    static void gotoxy(int x, int y)
    {
        COORD coordinate;
        coordinate.X = x;
        coordinate.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
    }
} CursorPosition;
#endif