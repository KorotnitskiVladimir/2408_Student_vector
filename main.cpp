//
//  main.cpp
//  23rd_2408
//
//  Created by Коротницкий Владимир on 24.08.2024.
//

#include <iostream>
#include <memory>
#include <vector>
#include <deque>
using namespace std;

class Student
{
private:
    string name;
    string surname;
    int year;
public:
    Student()
    {
        name = surname = "";
        year = 0;
    }
    Student(const char* n, const char* s, int y)
    {
        try
        {
            if (strlen(n)>0 && strlen(s)>0 && y>0 && y<6)
            {
                name = n;
                surname = s;
                year = y;
            }
            else
                throw "wrong input";
        }
        catch (const char* s)
        {
            cout << s << endl;
        }
    }
    Student(string n, string s, int y)
    {
        try
        {
            if (n!="" && s!="" && y>0 && y<6)
            {
                name = n;
                surname = s;
                year = y;
            }
            else
                throw "wrong input";
        }
        catch (const char* s)
        {
            cout << s << endl;
        }
    }
    void setName(const char* n)
    {
        if (strlen(n)>0)
            name = n;
    }
    void setSurname(const char* s)
    {
        if (strlen(s)>0)
            surname = s;
    }
    void setYear(int y)
    {
        if (y>0 && y<6)
            year = y;
    }
    string getName() const
    {
        return name;
    }
    string getSurname() const
    {
        return surname;
    }
    int getYear() const
    {
        return year;
    }
    Student& operator=(const Student& obj)
    {
        this->name = obj.name;
        this->surname = obj.surname;
        this->year = obj.year;
        
        return* this;
    }
};

ostream& operator<<(ostream& os, Student& obj)
{
    os << obj.getName() << endl;
    os << obj.getSurname() << endl;
    os << obj.getYear() << endl;
    
    return os;
}

void initRandom(vector<Student>& v, string* n, string* s, int* y, int size)
{
    int i = 0;
    while (i<size)
    {
        Student* obj = new Student(n[rand()%8], s[rand()%6], y[rand()%4]);
        v.push_back(*obj);
        delete obj;
        i++;
    }
}

void printGroup(vector<Student> v)
{
    for (auto ptr = v.begin(); ptr != v.end(); ptr++)
        cout << *ptr << endl;
}

void nameSort(vector<Student>& v)
{
    vector<Student>::iterator p1 = v.begin();
    while (p1!=v.end()-1)
    {
        vector<Student>::iterator p2 = v.begin();
        while (p2!=v.end()-1)
        {
            if (p2->getName()>(p2+1)->getName())
            {
                Student temp = *p2;
                v.insert(p2, *(p2+1));
                v.erase(p2+1);
                v.insert(p2+1, temp);
                v.erase(p2+2);
            }
            p2++;
        }
        p1++;
    }
}

void surnameSort(vector<Student>& v)
{
    vector<Student>::iterator p1 = v.begin();
    while (p1!=v.end()-1)
    {
        vector<Student>::iterator p2 = v.begin();
        while (p2!=v.end()-1)
        {
            if (p2->getSurname()>(p2+1)->getSurname())
            {
                Student temp = *p2;
                v.insert(p2, *(p2+1));
                v.erase(p2+1);
                v.insert(p2+1, temp);
                v.erase(p2+2);
            }
            p2++;
        }
        p1++;
    }
}

void yearSort(vector<Student>& v)
{
    vector<Student>::iterator p1 = v.begin();
    while (p1!=v.begin()+3)
    {
        vector<Student>::iterator p2 = v.begin();
        while (p2!=v.end()-1)
        {
            if (p2->getYear()>(p2+1)->getYear())
            {
                Student temp = *p2;
                v.insert(p2, *(p2+1));
                v.erase(p2+1);
                v.insert(p2+1, temp);
                v.erase(p2+2);
            }
            p2++;
        }
        p1++;
    }
}

int main()
{
//    vector<int> v1 {1,2,3,4,5};
//    v1.push_back(10);
//    v1.push_back(20);
//    int& last = v1.back();
//    int& first = v1.front();
//    vector<int>::iterator ptr = v1.begin();
//    for (;ptr != v1.end(); ptr++)
//        cout << *ptr << " ";
//    cout << endl;
//    for (auto ptr = v1.begin(); ptr != v1.end(); ptr++)
//        cout << *ptr << " ";
//    cout << endl;
//    cout << v1.max_size() << endl;
    srand(time(NULL));
    string names[] = {"Vladimir", "Euegene", "Ivan", "Vladislav", "Olena", "Irina", "Denys", "Alexey", "Olga"};
    string surnames[] = {"Petrov", "Ivanov", "Sidorov", "Mosunov", "Negrya", "Barabash", "Neychu"};
    int years[] = {1, 2, 3, 4, 5};
    
//    Student s1("Ivan", "Petrov", 3);
//    cout << s1 << endl;
    
    vector<Student> group;
    initRandom(group, names, surnames, years, 5);
    printGroup(group);
    nameSort(group);
    printGroup(group);
    surnameSort(group);
    printGroup(group);
    yearSort(group);
    printGroup(group);
    
    return 0;
}
