/**
* @file YoneticiListesi.hpp
* @description YoneticiListesinin ozelliklerinin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 7 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include "YoneticiNode.hpp"

class YoneticiListesi{
private:
    YoneticiNode *head;
    int size;
    YoneticiNode* FindPosition(int index);
    YoneticiNode *FindPreviousByPosition(int index);

public:
    YoneticiListesi();
    bool isEmpty() const;
    int Count() const;
    void add(SatirListesi*&);
    void insert(int,SatirListesi*&);
    void removeAt(int);
    void removeRandomSatirListesi(int, int);
    void getAverage(int);
    void sortByAverage();
    SatirListesi*& elementAt(int);
    void swapNode(int, int);
    int randomNode(int);
    void printIndex(int,int, int);
    void clear();
    ~YoneticiListesi();
};

#endif