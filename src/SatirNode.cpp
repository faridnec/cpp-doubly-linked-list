/**
* @file SatirNode.cpp
* @description SatirListesinin Dugum tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 5 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#include "SatirNode.hpp"

SatirNode::SatirNode(const int& data = int(), SatirNode *prev, SatirNode *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}