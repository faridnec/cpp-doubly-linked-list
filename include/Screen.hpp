/**
* @file Screen.hpp
* @description ekrana yazma sinifin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 12 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "YoneticiListesi.hpp"
#include "CursorPosition.hpp"

#define PERPAGE 8
#define START 0

enum PageDirection{
    before = 0,
    after = 1
};

enum NodeDirection{
    previous = 0,
    following = 1,
    standby = 2
};

class Screen{
private:
    YoneticiListesi* yoneticiListesi;
    int state;
    int start;
    int end;
    void Balance();
public:
    Screen(YoneticiListesi*);
    void State(NodeDirection);
    void Page(PageDirection);
    void presentYoneticiList();
    void presentSatirList(int, int);
    int presentSelectedSatirNode();
    void deleteYoneticiNode();
    void deleteSelectedSatirNode(int);
};
#endif