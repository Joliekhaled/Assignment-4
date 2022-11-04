//
//  Hash using LL.h
//  A4
//
//  Created by Jolie Khaled on 26/10/2022.
//

#ifndef Hash_using_LL_h
#define Hash_using_LL_h
#include <iostream>
#include "Employee.h"
#include <string>
//#include <vector>
using namespace std;

struct Entry1 {
    int key;
    Employee value;
    Entry1* next = nullptr;
    Entry1 (Employee v)
    {
        this->key=(int)v.getname()[0];
        this->value= v;
    }
    Entry1() = default;
    
};
class Vector1{
private:
    // How many more elements I can put inside the array
    int capacity;
    // How many elements are inside the array
    int size;

    Entry1* arr;
public:
    Vector1(int capacity)
    {
        arr = new Entry1[capacity];
        size = 0;
        this->capacity = capacity;
    }

    void push_back(Entry1 data)
    {
        if (size == capacity)
            Reallocate(capacity * 1.5f);

        arr[size] = data;
        size++;
    }

    void Reallocate(int newCapacity)
    {
        Entry1* temp = new Entry1[newCapacity];

        for (int i = 0; i < capacity; i++)
            temp[i] = arr[i];

        delete[] arr;

        arr = temp;
        capacity = newCapacity;
    }
};




class Hashtable1
{
private:
    const int CELL_EMPTY = -1;
    const int CELL_TOMPSTONE = -3;

    int capacity;
    Entry1* arr;
    int* CollisionCount;
    int Hash(int key)
    {
        return key % capacity;
    }
public:
    static const int KEY_NOT_FOUND;
    Hashtable1()
    {
        capacity = 13;
        arr = new Entry1[capacity];
        CollisionCount = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i].key = CELL_EMPTY;
            CollisionCount[i] =0;
        }
        
    }

    // INSERT
    bool Insert(Employee em)
    {   Entry1 e(em);
        int index = Hash(e.key);
        e.next = nullptr;
        

        // Seperate Chaining that solves a collision for the linked list 
        /// WE CAN NOT HAVE DUPLICATE KEYS
        if (Lookup(e.key).key != KEY_NOT_FOUND)
            return false;

        if (arr[index].key != CELL_EMPTY && arr[index].key != CELL_TOMPSTONE)
        {
            Entry1* p = &arr[index];
            while (p->next != nullptr)
                p = p->next;

            p->next = new Entry1;
            *p->next = e;
            
            CollisionCount[index]++;
        }
        else
            arr[index] = e;

        return true;
    }

    // DELETE
    bool Delete(int key)
    {
        int index = Hash(key);

        if (arr[index].key == key)
        {
            // We want to delete the very first key
           
            Entry1* p = &arr[index];
            if (p->next != nullptr)
            {
                arr[index] = *p;
                delete p;
            }
            else
            {
                arr[index].key = CELL_TOMPSTONE;
            }
        }
        else
        {
            Entry1* p = &arr[index];
            Entry1* q = &arr[index];
            while(p->next != nullptr && p->key != key)
            {
                q = p;
                p = p->next;
            }

            if (p->key == key)
            {
                // Delete this node
                q->next = p->next;
                delete p;
            }
            else
            {
                // We did not find it anywhere
                return false;
            }
        }
        
        return true;
    }

    // LOOK UP (Find)
    Entry1 Lookup(int key)
    {
        int index = Hash(key);

        Entry1* p = &arr[index];

        while(p != nullptr && p->key != key)
        {
            p = p->next;
        }

        if(p != nullptr){
            Entry1 K;
            K.key=key;
            K.value=p->value;
            return K;
            
        }
        else
        {   Entry1 k;
            k.key= KEY_NOT_FOUND;
            return k;}
    }

    // PRINT
    void Print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i].key != CELL_EMPTY && arr[i].key != CELL_TOMPSTONE)
            {
                Entry1* p = &arr[i];
                bool flag = false;
                while(p != nullptr)
                {
                    if (flag)
                    cout << "-->";

                   cout << "{ The key is " << p->key << ", " <<  "and all the employee's information is listed below: ";
                    cout << endl;
                p->value.printall() ;
                    cout << "}" <<endl;
                    p = p->next;
                    flag = true;
                }
                
                
                
                for(int i = 0; i < capacity; i++)
                {
                    if (CollisionCount[i] > 0)
                        cout << i << ": " << CollisionCount[i] << endl;
                }
                    
            }
            
        }
        cout << "Collision Count for the hash table using linked list:\n";
    }

    ~Hashtable1()
    {
        for (int i = 0; i < capacity; i++)
        {
            while(arr[i].next != nullptr)
            {
                Entry1* p = arr[i].next;
                arr[i] = *arr[i].next;
                delete p;
            }
        }
        delete[] arr;
        delete[] CollisionCount;
    }


    
};

const int Hashtable1::KEY_NOT_FOUND = -10;


#endif /* Hash_using_LL_h */
