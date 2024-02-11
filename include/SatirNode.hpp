/**
* @file SatirNode.hpp
* @description SatirListesinin Dugum tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 5 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#ifndef SATIRNODE_HPP
#define SATIRNODE_HPP
#include <iostream>
#include <iomanip>

using namespace std;
class SatirNode
{
public:
    int data;
    SatirNode *next;
    SatirNode *prev;
    SatirNode(const int&, SatirNode *prv = NULL, SatirNode *nx = NULL);
};
#endif