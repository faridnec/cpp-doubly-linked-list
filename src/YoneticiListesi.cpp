/**
* @file YoneticiListesi.cpp
* @description SatirListesinin ozelliklerinin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 7 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"

YoneticiNode* YoneticiListesi::FindPosition(int index)
{
    if (index < 0 || index >= size)
        throw "No Such Element";
    return FindPreviousByPosition(index + 1);
}

YoneticiNode* YoneticiListesi::FindPreviousByPosition(int index)
{
    if (index < 0 || index > size)
        throw "No such element";
    YoneticiNode *prv = head;
    int i = 1; // 0
    for (YoneticiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
    {
        prv = prv->next;
    }
    return prv;
}

YoneticiListesi::YoneticiListesi()
{
    head = NULL; // new YoneticiNode(NULL)
    size = 0;
}

bool YoneticiListesi::isEmpty() const
{
    return size == 0;
}
int YoneticiListesi::Count() const
{
    return size;
}

void YoneticiListesi::add(SatirListesi *&data)
{
    insert(size, data);
}

void YoneticiListesi::insert(int index, SatirListesi *&data)
{
    if (index < 0 || index > size)
        throw "Index out of Range";
    if (index == 0)
    {                                              // insert at the beginning of the Linked List
        head = new YoneticiNode(data, NULL, head); // head->next = new YoneticiNode(data)
        if (head->next != NULL)
            head->next->prev = head; //
    }
    else
    { // insert somewhere between nodes not in the beginning or the last
        YoneticiNode *prv = FindPreviousByPosition(index);
        prv->next = new YoneticiNode(data, prv, prv->next);
        if (prv->next->next != NULL) // if we wanted targetIndex add node between nodes of List
            prv->next->next->prev = prv->next;
    }
    size++;
}
void YoneticiListesi::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw "Index out of Range";
    YoneticiNode *del;
    if (index == 0)
    {               // delete node at the begining of the list
        del = head; //->next
        head->next = del->next;
        if (head != NULL)
            head->prev = NULL; // if(head->next != NULL) head->next->prev = head
    }
    else
    { // delete node between nodes of the list
        YoneticiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL) // if we wanted targetIndex delete node targetIndex the last of List
            del->next->prev = prv;
    }
    size--;
    delete del;
}

void YoneticiListesi::removeRandomSatirListesi(int index, int inlineIndex)
{

    int count = Count();
    if (index < 0 || index >= count)
        throw "Index out of bounds";

    SatirListesi *satirListesi = this->elementAt(index);

    satirListesi->removeAt(inlineIndex);
    getAverage(index);
}

void YoneticiListesi::getAverage(int index)
{
    YoneticiNode *yoneticiNode = FindPosition(index);

    if (yoneticiNode == NULL)
        throw "hata";

    double sum = 0;

    if (yoneticiNode->satirListesi->isEmpty())
    {
        yoneticiNode->average = sum;
        return;
    }

    int size = yoneticiNode->satirListesi->Count();
    for (int i = 0; i < size; ++i)
    {
        sum += yoneticiNode->satirListesi->elementAt(i);
    }
    yoneticiNode->average = sum / size;
}

void YoneticiListesi::swapNode(int index, int targetIndex)
{
    if (index < 0 || index >= size)
        "Index out of Range";
    YoneticiNode *del;
    if (index == 0)
    {
        del = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        YoneticiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    if (targetIndex < 0 || targetIndex > size)
        throw "Index out of Range";
    if (targetIndex == 0)
    {

        del->next = head;
        del->prev = NULL;
        head = del;
        if (head->next != NULL)
            head->next->prev = head;
    }
    else
    {
        YoneticiNode *prv = FindPreviousByPosition(targetIndex);

        del->next = prv->next;
        del->prev = prv;
        prv->next = del;
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

void YoneticiListesi::sortByAverage()
{
    if (size <= 1)
        return;
    for (int step = 0; step < size; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            YoneticiNode *tmp = FindPosition(i);
            YoneticiNode *tmp2 = tmp->next;

            if (tmp->average > tmp2->average)
            {
                swapNode(i + 1, i);
            }
        }
    }
}

SatirListesi *&YoneticiListesi::elementAt(int index)
{
    if (index < 0 || index >= size)
        throw "No Such Element";
    if (index == 0)
        return head->satirListesi;
    return FindPreviousByPosition(index)->next->satirListesi;
}

int YoneticiListesi::randomNode(int index)
{
    int size = Count();

    if (index < 0 || index >= size)
        throw "Index out of bounds";

    srand(time(NULL));
    SatirListesi *satirListesi = elementAt(index);

    int range = satirListesi->Count();
    if (range == 0)
        throw "No Such Element";
    int inlineIndex = rand() % range;

    return inlineIndex;
}

void YoneticiListesi::printIndex(int index, int xCor, int yCor)
{
    YoneticiNode *y_node = FindPosition(index);
    CursorPosition.gotoxy(xCor, yCor);
    cout << fixed << setprecision(2);
    cout << y_node << "\n";
    CursorPosition.gotoxy(xCor, yCor + 1);
    cout << "-----------\n";
    CursorPosition.gotoxy(xCor, yCor + 2);
    if (y_node->prev == 0)
    {
        cout << "|" << setw(5) << y_node->prev << setw(6) << "|\n";
    }
    else
    {
        cout << "|" << y_node->prev << setw(3) << "|\n";
    }
    CursorPosition.gotoxy(xCor, yCor + 3);
    cout << "-----------\n";
    CursorPosition.gotoxy(xCor, yCor + 4);
    cout << "|" << setw(3) << y_node->average << setw(5) << "|" << endl;
    CursorPosition.gotoxy(xCor, yCor + 5);
    cout << "-----------\n";
    CursorPosition.gotoxy(xCor, yCor + 6);
    if (y_node->next == 0)
    {
        cout << "|" << setw(5) << y_node->next << setw(6) << "|\n";
    }
    else
    {
        cout << "|" << y_node->next << setw(3) << "|\n";
    }
    CursorPosition.gotoxy(xCor, yCor + 7);
    cout << "-----------\n\n";
}

/*
friend ostream &operator<<(ostream &screen, YoneticiListesi &right)
{
    for (YoneticiNode *itr = right.head; itr != NULL; itr = itr->next)
    {
        //if(itr->next == NULL) itr->next = 0;
        screen << "["<<itr->satirListesi<< " | " <<itr->getAverage() << " | " <<itr->next->satirListesi<<"] -> "<<*itr->satirListesi;/* <<itr->next->satirListesi<<
        if (itr->next != NULL)
            screen << "\r\n";
    }
    if (right.isEmpty())
        screen << "The list is empty!";
    return screen;
}
*/
void YoneticiListesi::clear()
{
    while(!isEmpty()) removeAt(0);
}
YoneticiListesi::~YoneticiListesi()
{
    clear();
}