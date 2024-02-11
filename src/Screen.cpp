/**
* @file Screen.cpp
* @description ekrana yazma sinifin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 12 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#include "Screen.hpp"

void Screen::Balance()
{
    int pg = state / PERPAGE;
    start = PERPAGE * pg;
    end = PERPAGE * (pg + 1);

    if (end >= yoneticiListesi->Count())
    {
        end = yoneticiListesi->Count();
    }
}

Screen::Screen(YoneticiListesi *yonetici)
{
    yoneticiListesi = yonetici;
    if (yoneticiListesi->Count() < PERPAGE)
    {
        end = yoneticiListesi->Count();
    }
    else
    {
        end = PERPAGE;
    }
    start = START;
}

void Screen::State(NodeDirection drc)
{
    if (drc == following)
    {
        if (state >= yoneticiListesi->Count() - 1)
        {
            return;
        }
        ++state;
        Balance();
    }
    else if (drc == previous)
    {
        if (state <= 0)
        {
            return;
        }
        --state;
        Balance();
    }
    else if (drc == standby)
    {
        Balance();
    }
}
void Screen::Page(PageDirection pageDrc)
{
    if (pageDrc == before)
    {
        for (int i = 0; i < PERPAGE; ++i)
        {
            State(previous);
        }
    }
    else if (pageDrc == after)
    {
        for (int i = 0; i < PERPAGE; ++i)
        {
            State(following);
        }
    }
}

void Screen::presentYoneticiList()
{
    int size = yoneticiListesi->Count();

    cout << setw(10) << "B201210556" << setw(10) << endl;
    system("cls");

    if (size == 0)
    {
        cout << "Nothing to display\n";
        exit(1);
        return;
    }

    CursorPosition.gotoxy(0, 0);
    if (start == 0)
    {
        cout << "<--first--";
    }
    else
    {
        cout << "<---back--";
    }

    int showCount = end - start;
    showCount *= 13;
    CursorPosition.gotoxy(showCount, 0);

    if (start == yoneticiListesi->Count())
    {
        cout << "--last-->";
    }
    else
    {
        cout << "--next-->";
    }
    for (int i = start; i < end; ++i)
    {
        int mod = i % PERPAGE;
        yoneticiListesi->printIndex(i, 15 * mod, 1);
    }
    presentSatirList((state % PERPAGE) * 15, 9);
}

void Screen::presentSatirList(int a, int b)
{
    yoneticiListesi->elementAt(state)->printSatirListesi(a, b);
}

int Screen::presentSelectedSatirNode()
{
    int selected = yoneticiListesi->randomNode(state);
    int xCoor = ((state % PERPAGE) + 1) * 15;
    int yCoor = (selected)*6;
    yCoor += 12;

    CursorPosition.gotoxy(xCoor, yCoor);
    cout << "<= will be deleted";
    yCoor = yoneticiListesi->elementAt(state)->Count() * 6 + 12;

    CursorPosition.gotoxy(0, yCoor - 1);

    return selected;
}

void Screen::deleteYoneticiNode()
{
    yoneticiListesi->removeAt(state);
    State(standby);

    if (state == end)
    {
        state--;
    }
    State(standby);
}

void Screen::deleteSelectedSatirNode(int randomIndex)
{
    yoneticiListesi->removeRandomSatirListesi(state, randomIndex);
}