/**
* @file SatirListesi.cpp
* @description SatirListesinin ozelliklerinin tanimlamasi
* @course Veri Yapilari 1B
* @assignment 1
* @date 5 Kasim 2022
* @author Muhammad Najmuddin Farid muhammad.farid@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"

    SatirNode* SatirListesi::FindPreviousByPosition(int index)
    {
        if (index < 0 || index > size)
            throw "Index Out of Range";
        SatirNode *prv = head;
        int i = 0;
        for (SatirNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
        {
            prv = prv->next;
        }
        return prv;
    }

    SatirListesi::SatirListesi()
    {
        head = new SatirNode(-1);
        size = 0;
    }
    bool SatirListesi::isEmpty() const{
        return size == 0;
    }
    int SatirListesi::Count() const{
			return size;
	}
    void SatirListesi::add(const int &data)
    {
        insert(size, data);
    }

    void SatirListesi::insert(int index, const int &data)
    {
        if (index < 0 || index > size)
            throw "Index out of Range";

        if (index == 0)
        { // insert at the beginning of the Linked List
            head->next = new SatirNode(data);
            // if(head->next != NULL) head->next->prev = head;
        }
        else
        { // insert somewhere between nodes not in the beginning or the last
            SatirNode *prv = FindPreviousByPosition(index);
            prv->next = new SatirNode(data, prv);
            /*
            if(prv->next->next != NULL)// if we wanted to add node between nodes of List
                prv->next->next->prev = prv->next;
            */
        }
        size++;
    }

    void SatirListesi::removeAt(int index)
	{
			if(index < 0 || index >= size) throw "Index out of Range";
			SatirNode *del;
			if(index == 0){// delete node at the begining of the list
				del = head->next;
				head->next = del->next;
				if(head->next != NULL) head->next->prev = head;
			}
			else{// delete node at the last of the list
				SatirNode *prv = FindPreviousByPosition(index);
				del = prv->next;
				prv->next = del->next;
				if(del->next != NULL)// if we wanted to delete a node between nodes of List
					del->next->prev = prv;
			}
			delete del;
            size--;
		}

    SatirNode* SatirListesi::getSatirNodeAt(int index) 
	{
        if (index < 0 || index > size)
            throw "Index Out of Range";
        SatirNode *prv = head;
        int i = 0;
        for (SatirNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
        {
            prv = prv->next;
        }
        return prv->next;
    }

    const int& SatirListesi::elementAt(int index)
	{
        if (index < 0 || index >= size) throw "No Such Element";
        if (index == 0) return head->next->data;//head->data
        return FindPreviousByPosition(index)->next->data;
    }

    /*
    friend ostream &operator<<(ostream &screen, SatirListesi &right)
    {
        for (SatirNode *itr = right.head->next; itr != NULL; itr = itr->next)
        {
            screen << itr->data;
            if (itr->next != NULL)
                screen << "  <-->  ";
        }
        if (right.isEmpty())
            screen << "The list is empty!";

        return screen;
    }
    */

    void SatirListesi::printSatirListesi(int x,int y)
	{
        int y_index=y; 
        CursorPosition.gotoxy(x,y_index);
        cout<<"vvvvvvvvvvv\n"; 
        for (SatirNode *itr = head->next; itr != NULL; itr = itr->next) {
            CursorPosition.gotoxy(x,++y_index);
            cout<<setw(3)<<itr<<"\n";
            
            CursorPosition.gotoxy(x,++y_index);
            cout<<"-----------\n";
            CursorPosition.gotoxy(x,++y_index);
            cout<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
            CursorPosition.gotoxy(x,++y_index);
            cout<<"-----------\n";
            CursorPosition.gotoxy(x,++y_index);
            if(itr->next == 0) {
                cout<<"|"<<setw(5)<<itr->next<<setw(6)<<"|\n";
            } else{
                cout<<"|"<<itr->next<<setw(3)<<"|\n";
            }
            CursorPosition.gotoxy(x,++y_index);
            cout<<"-----------\n\n";
        }
    }
    void SatirListesi::clear(){
        while(!isEmpty()) removeAt(0);
    }
    SatirListesi::~SatirListesi()
	{
        clear();
    }