//
//  main.cpp
//  A4
//
//  Created by Jolie Khaled on 26/10/2022.
//

#include <iostream>
#include "Employee.h"
#include "Hash using dynamic.h"
#include "Hash using LL.h"
using namespace std;

int main()
{
    Employee a[] = { Employee("Mina", 30, 10000, 4), Employee("Fawzy", 45, 5000, 8),
        Employee("Yara", 19, 2000, 0), Employee("Mariam", 32, 8000, 2),
        Employee("Ayman", 33, 4000, 8), Employee("Roshdy", 28, 9000, 3),
        Employee("Aya", 26, 6000, 3), Employee("Abdallah", 29, 7000, 4),
        Employee("Fatma", 21, 3000, 1)
    
    };
    
    Hashtable h;
    Hashtable1 h1;

    for(auto employee : a)
    {
        
        h.Insert(employee);
        h1.Insert(employee);
    }
    cout << "This is the output of all Employees with their information using dynamic array: " << endl;
    cout << endl;
    h.Print();
    cout << "--------------------------------------------------------\n";
    cout << endl;
    cout << "This is the output of all Employees with their information using Linked list: " << endl;
    cout << endl;
    h1.Print();
   
   
    
    return 0;
}
