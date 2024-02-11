/**
* @file SatirListesi.hpp
* @description SatirListesinin ozelliklerinin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 5 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include "SatirNode.hpp"
#include "CursorPosition.hpp"

class SatirListesi
{
private:
    SatirNode *head;
    int size;
    SatirNode *FindPreviousByPosition(int);
public:
    SatirListesi();
    bool isEmpty() const;
    int Count() const;
    void add(const int &data);
    void insert(int index, const int &data);
    void removeAt(int index);
    SatirNode* getSatirNodeAt(int index);
    const int& elementAt(int index);
    void printSatirListesi(int x,int y);
    void clear();
    ~SatirListesi();
};

#endif