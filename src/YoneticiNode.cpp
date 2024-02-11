/**
* @file YoneticiNode.cpp
* @description Yoneticinin Dugum ve ozelliklerinin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 7 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#include "YoneticiNode.hpp"

YoneticiNode::YoneticiNode(SatirListesi *satirListesi, YoneticiNode *prev, YoneticiNode *next)
{
    this->satirListesi = satirListesi;
    this->prev = prev;
    this->next = next;
    this->average = getAverage();
}

double YoneticiNode::getAverage()
{
    double sum = 0;
    if (satirListesi->isEmpty())
        return sum;
    int size = satirListesi->Count();
    for (int i = 0; i < size; ++i)
    {
        sum += satirListesi->elementAt(i);
    }
    return sum / size;
}