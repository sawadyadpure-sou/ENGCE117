#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std ;

struct studentNode {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    studentNode *next ;
} ;


class LinkedList {
protected:
    studentNode *start, *now ; 
public:
    LinkedList() {
        start = nullptr ;
        now = nullptr ;
    }
    
    ~LinkedList() {
        while (start != nullptr) {
            studentNode *temp = start ;
            start = start->next ;
            delete temp ; 
        }
    }

    void InsNode(const char n[], int a, char s, float g) ;
    void GoNext() ;
    void DelNode() ;
    virtual void ShowNode() ;
} ;

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = start ;
    }

    virtual void ShowNode() {
        if (start != nullptr && now != nullptr) {
            cout << start->name << " " << now->name << endl ;
        }
    }
} ;


void LinkedList::InsNode(const char n[], int a, char s, float g) {
    studentNode *newNode = new studentNode ;
    strcpy(newNode->name, n) ;
    newNode->age = a ;
    newNode->sex = s ;
    newNode->gpa = g ;
    newNode->next = nullptr ;

    if (start == nullptr) {
        start = newNode ;
        now = start ;
    } else {
        studentNode *temp = start ;
        while (temp->next != nullptr) {
            temp = temp->next ;
        }
        temp->next = newNode ;
    }
}

void LinkedList::GoNext() {
    if (now != nullptr && now->next != nullptr) {
        now = now->next ;
    }
}

void LinkedList::DelNode() {
    if (now == nullptr) return ;

    if (now == start) {
        start = start->next ;
        delete now ;
        now = start ;
    } else {
        studentNode *prev = start ;
        while (prev->next != now) {
            prev = prev->next ;
        }
        prev->next = now->next ;
        delete now ;
        now = (prev->next != nullptr) ? prev->next : prev ;
    }
}

void LinkedList::ShowNode() {
    if (now != nullptr) {
        cout << now->name << " " << now->age << " " << now->sex << " " 
             << fixed << setprecision(2) << now->gpa << endl ;
    }
}

int main() {
    LinkedList listA ;
    NewList listB ;
    LinkedList *listC ;

    listA.InsNode("one", 1, 'A', 1.1) ;
    listA.InsNode("two", 2, 'B', 2.2) ;
    listA.InsNode("three", 3, 'C', 3.3) ;
    listA.GoNext() ;
    listA.ShowNode() ;

    listB.InsNode("four", 4, 'D', 4.4) ;
    listB.InsNode("five", 5, 'E', 5.5) ;
    listB.InsNode("six", 6, 'F', 6.6) ;
    listB.GoNext() ;   
    listB.DelNode() ;  
    listB.ShowNode() ; 

    listC = &listA ;
    listC->GoNext() ;
    listC->ShowNode() ; 
    listC = &listB ;
    listC->ShowNode() ; 

    return 0 ;
}