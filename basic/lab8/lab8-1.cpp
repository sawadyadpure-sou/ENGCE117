#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std ;

struct studentNode {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

class LinkedList {
protected:
    struct studentNode *start, **now ;
public:
    LinkedList() {
        start = NULL ;
        now = &start ;
    }
    
    ~LinkedList() {
        GoFirst() ;
        while (*now != NULL) DelNode() ;
    }

    void InsNode(const char n[], int a, char s, float g) ;
    void DelNode() ;
    void GoNext() ;
    void GoFirst() { now = &start ; }
    void GoLast() ;
    void ShowAll() ;
    int FindNode(const char n[]) ;
    struct studentNode *NowNode() { return *now ; }
    void EditNode(const char n[], int a, char s, float g) ;
} ;

void AddData(LinkedList *ll) ;
void EditData(LinkedList *ll) ;
void FindData(LinkedList *ll) ;
void readfile(LinkedList *ll) ;
void writefile(LinkedList *ll) ;

int main() {
    LinkedList listA ;
    int menu ;

    readfile(&listA) ; 

    do {
        cout << "\n Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ;
        cin >> menu ;

        switch (menu) {
            case 1: AddData(&listA) ; break ;
            case 2: EditData(&listA) ; break ;
            case 3: listA.DelNode() ; cout << "Deleted current node." << endl ; break ;
            case 4: FindData(&listA) ; break ;
            case 5: listA.ShowAll() ; break ;
        }
    } while (menu != 0) ;

    writefile(&listA) ; 
    return 0 ;
}

void LinkedList::InsNode(const char n[], int a, char s, float g) {
    studentNode *newNode = new studentNode ;
    strcpy(newNode->name, n) ;
    newNode->age = a ;
    newNode->sex = s ;
    newNode->gpa = g ;
    newNode->next = *now ;
    *now = newNode ;
}

void LinkedList::DelNode() {
    if (*now != NULL) {
        studentNode *tmp = *now ;
        *now = (*now)->next ;
        delete tmp ;
    }
}

void LinkedList::GoNext() {
    if (*now != NULL && (*now)->next != NULL)
        now = &((*now)->next) ;
}

void LinkedList::GoLast() {
    GoFirst() ;
    while (*now != NULL && (*now)->next != NULL)
        now = &((*now)->next) ;
}

void LinkedList::ShowAll() {
    studentNode *temp = start ;
    cout << "\n" << left << setw(15) << "Name" << setw(5) << "Age" << setw(5) << "Sex" << "GPA" << endl ;
    while (temp != NULL) {
        cout << left << setw(15) << temp->name << setw(5) << temp->age 
             << setw(5) << temp->sex << fixed << setprecision(2) << temp->gpa << endl ;
        temp = temp->next ;
    }
}

int LinkedList::FindNode(const char n[]) {
    GoFirst() ;
    while (*now != NULL) {
        if (strcmp((*now)->name, n) == 0) return 1 ;
        GoNext() ;
    }
    return 0 ;
}

void LinkedList::EditNode(const char n[], int a, char s, float g) {
    if (*now != NULL) {
        strcpy((*now)->name, n) ;
        (*now)->age = a ;
        (*now)->sex = s ;
        (*now)->gpa = g ;
    }
}

void AddData(LinkedList *ll) {
    char n[20], s ; int a ; float g ;
    cout << "Enter Name: " ; cin >> n ;
    cout << "Enter Age: " ; cin >> a ;
    cout << "Enter Sex (M/F): " ; cin >> s ;
    cout << "Enter GPA: " ; cin >> g ;
    ll->GoLast() ;
    ll->InsNode(n, a, s, g) ;
}

void EditData(LinkedList *ll) {
    char n[20], newN[20], s ; int a ; float g ;
    cout << "Search name to edit: " ; cin >> n ;
    if (ll->FindNode(n)) {
        cout << "Enter New Name: " ; cin >> newN ;
        cout << "Enter New Age: " ; cin >> a ;
        cout << "Enter New Sex: " ; cin >> s ;
        cout << "Enter New GPA: " ; cin >> g ;
        ll->EditNode(newN, a, s, g) ;
    } else cout << "Not found!" << endl ;
}

void FindData(LinkedList *ll) {
    char n[20] ;
    cout << "Search name: " ; cin >> n ;
    if (ll->FindNode(n)) {
        studentNode *sn = ll->NowNode() ;
        cout << "Found: " << sn->name << " Age: " << sn->age << " GPA: " << sn->gpa << endl ;
    } else cout << "Not found!" << endl ;
}

void writefile(LinkedList *ll) {
    ofstream out("student_data.txt") ;
    ll->GoFirst() ;
    while (ll->NowNode() != NULL) {
        studentNode *sn = ll->NowNode() ;
        out << sn->name << " " << sn->age << " " << sn->sex << " " << sn->gpa << endl ;
        ll->GoNext() ;
    }
    out.close() ;
}

void readfile(LinkedList *ll) {
    ifstream in("student_data.txt") ;
    char n[20], s ; int a ; float g ;
    while (in >> n >> a >> s >> g) {
        ll->GoLast() ;
        ll->InsNode(n, a, s, g) ;
    }
    in.close() ;
}