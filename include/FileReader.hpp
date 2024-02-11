/**
* @file FileReader.hpp
* @description veriler.txt dosyasi okuyan metodu tanimliyor
* @course Veri Yapilari 1B
* @assignment 1
* @date 11 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

using namespace std;

YoneticiListesi *read(string path)
{
    ifstream file;
    file.open(path);
    string line;

    if(!file.is_open())
    {
        cout << "File was not found" << endl;
        cout << "Please make sure the " << path << " file is in the same directory as the makefile" << endl;
    }

    YoneticiListesi *yl = new YoneticiListesi();

    while (getline(file, line))
    {
        SatirListesi *sat = new SatirListesi();
        istringstream ss(line);
        string data;

        if(line.empty()) continue;//incase empty line was found it will jump to the next line

        while (ss >> data)
        {
            sat->add(stoi(data));
        }
        yl->add(sat);
    }
    return yl;
    file.close();
}
