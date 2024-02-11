/**
* @file YoneticiNode.hpp
* @description Yoneticinin Dugum ve ozelliklerinin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 7 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#ifndef YONETICI_HPP
#define YONETICI_HPP
#include "SatirListesi.hpp"

class YoneticiNode{
    public:
        SatirListesi* satirListesi;
        YoneticiNode *next;
        YoneticiNode *prev;
        double average = 0;
        
        YoneticiNode(SatirListesi* satirListesi, YoneticiNode *prev = NULL, YoneticiNode *next = NULL);
        double getAverage();
};
#endif