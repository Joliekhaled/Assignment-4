//
//  Hash using dynamic.h
//  A4
//
//  Created by Jolie Khaled on 26/10/2022.
//

#ifndef Hash_using_dynamic_h
#define Hash_using_dynamic_h
#include <iostream>
#include "Employee.h"
#include <string>
#include <vector>
using namespace std;


struct Entry{
    int key;
    Employee value;
    Entry (Employee v)
    {
        this->key=(int)v.getname()[0];
        this->value= v;
    }
    Entry()= default;
};
class Vector{
private:
    // How many more elements I can put inside the array
    int capacity;
    // How many elements are inside the array
    int size;

    
public:
    Entry* Al;
    Vector(int capacity)
    {
        Al = new Entry[capacity];
        size = 0;
        this->capacity = capacity;
    }
    Vector ()
    {
        
    }
    /*void setcapacity (int C)
    {
        Al = new Entry[C];
        size = 0;
        this->capacity = C;
    }*/
    void push_back(Employee data,int key)
    {
        if (size == capacity)
            Reallocate(capacity * 1.5f);  // to do
        
        // arr -> vector of (Entries)
        // arr[0] -> An entry
        
        //arr[size] = new Entry(data, key);
        //arr[size] = new Entry;
        Al[size].value = data;
        Al[size].key = key;
        
        size++;
    }

    void Reallocate(int newCapacity)
    {
        Entry* temp = new Entry[newCapacity];

        for (int i = 0; i < capacity; i++)
            temp[i].key = Al[i].key;

        delete[] Al;

        Al = temp;
        capacity = newCapacity;
    }
};




class Hashtable
{
private:
    const int CELL_EMPTY = -1;
    const int CELL_TOMPSTONE = -3;
    int capacity = 13;
    int size = 0;
    
    Entry* arr;
    int* Collisioncount;
    
    int Hash(int key)
    {
        return key % capacity;
    }

    void Reallocate(int newCapacity)
    {
        Entry* temp = new Entry[newCapacity];
        int* colTemp = new int[newCapacity];
        
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = arr[i];
            colTemp[i] = Collisioncount[i];
        }
        for (int i = capacity; i < newCapacity; i++)
        {
            temp[i].key = CELL_EMPTY;
            colTemp[i] = 0;
        }
        delete[] arr;
        delete[] Collisioncount;

        arr = temp;
        Collisioncount = colTemp;
        capacity = newCapacity;
    }
    
public:
    static const int KEY_NOT_FOUND;
    Hashtable()
    {
        arr = new Entry[13];
        Collisioncount = new int[13];
        capacity = 13;
        size = 0;
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = Entry();
            arr[i].key = CELL_EMPTY;
            Collisioncount[i] = 0;
        }
        
    }

    // INSERT
    bool Insert(Employee em)
    {
        Entry e(em);
        int index = Hash(e.key);
        int count =0;
        int startedIndex = index;
        
        // Linear Propeing
        // WE CAN NOT HAVE DUPLICATE KEYS
//        if (Lookup(e.key) != KEY_NOT_FOUND){
//            return false;
//        }

        while(arr[index].key != CELL_EMPTY && arr[index].key != CELL_TOMPSTONE)
        {   
            index = (index + 1) % capacity;
            count++;
        }
        
        if (index != startedIndex)
            Collisioncount[startedIndex]++;
        
        arr[index] = e;
        size++;
        if (size == capacity)
            Reallocate(capacity * 1.5f);
        return true;
    }

    // DELETE
    bool Delete(int key)
    {
        int index = Hash(key);
 
        int startedIndex = index;

        // Linear Propeing
        while(arr[index].key != key)
        {
            index = (index + 1) % capacity;
            if (index == startedIndex)
                return false;
        }
        arr[index].key = CELL_TOMPSTONE;
        size--;
        return true;
    }

    // LOOK UP (Find)
    int Lookup(int key)
    {
        int index = Hash(key);


        int startedIndex = index;

        // Linear Propeing that solves a collision for dynamic array
        while(arr[index].key != key)
        {
            index = (index + 1) % capacity;
            // Key not found
            if (index == startedIndex)
                return KEY_NOT_FOUND;
        }

        return index;
    }

    // PRINT
    void Print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i].key != CELL_EMPTY && arr[i].key != CELL_TOMPSTONE)
            {cout << "{" <<" The key is " << arr[i].key << " , and all the employee's information is listed below: ";
                cout << endl;
            arr[i].value.printall() ;
                cout << "}" << endl;}
        }
        
        cout << "Collision Count for the hash table using dynamic array:\n";
        
        for(int i = 0; i < capacity; i++)
        {
            if (Collisioncount[i] > 0)
                cout << i << ": " << Collisioncount[i] << endl;
        }
    }

    ~Hashtable()
    {
        delete[] arr;
        delete[] Collisioncount;
    }

};

const int Hashtable::KEY_NOT_FOUND = -10;



#endif /* Hash_using_dynamic_h */
