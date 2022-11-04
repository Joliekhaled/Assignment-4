//
//  Classes.h
//  A4
//
//  Created by Jolie Khaled on 26/10/2022.
//

#ifndef Classes_h
#define Classes_h
#include <iostream>
using namespace std;
class Employee
{
    
private:
    string name;
    int age;
    int salary;
    int yearsofexperience;
    
public:
    Employee()
    {
        name = "";
        age = 0;
        salary = 0;
        yearsofexperience = 0;
    }
    Employee (string NameN, int AgeA, int SalaryS, int Years )
    {
        name= NameN;
        age = AgeA;
        salary = SalaryS;
        yearsofexperience = Years;
        
    }
    void setname(string N)
    {
        name = N;
        
    }
    void setage(int A)
    {
        age = A;
    }
    void setsalary (int S)
    {
        salary = S;
    }
    void setyears (int Y)
    {
        yearsofexperience = Y;
    }
    string getname()
    {
        return name;
    }
    int getage()
    {
        return age;
    }
    int getsalary()
    {
        return salary;
    }
    int getyears()
    {
        return yearsofexperience;
    }
    
    void printall()
    {
        cout << "The name of the employee is " << name << endl;
        cout << "Employee's age is " << age << endl;
        cout << "Employee's salary is " << salary << endl;
        cout << "Employee's years of experience " << yearsofexperience<< endl;
        
    }
    
};

#endif /* Classes_h */
