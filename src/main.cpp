/**
* @file main.cpp
* @description test kismi ve menuleri icerir
* @course Veri Yapilari 1B
* @assignment 1
* @date 5 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "FileReader.hpp"
#include "Screen.hpp"

#include <iostream>
using namespace std;

int main()
{
    YoneticiListesi *yl = read("veriler.txt");
    Screen *cursor = new Screen(yl);
    string signary = "";
    yl->sortByAverage();
    
    do {
        cursor->presentYoneticiList();
        cout<<"input >>";
        cin>>signary;
        if (signary == "c") {
            NodeDirection dr = following;
            cursor->State(dr);
        } else if (signary == "z") {
            NodeDirection direction = previous;
            cursor->State(direction);
        } else if (signary == "k") {
            int randomIndex = 0;
            try {
                randomIndex = cursor->presentSelectedSatirNode();
            } catch (...) {
                continue;
            }
            cin>>signary;
            if (signary == "k") {
                cursor->deleteSelectedSatirNode(randomIndex);
                yl->sortByAverage();
            }
        } else if (signary == "p") {
            cursor->deleteYoneticiNode();
        } else if (signary == "d") {
            cursor->Page(after);
        } else if (signary == "a") {
            cursor->Page(before);
        }
    } while (signary != "q");
    
    return 0;
}