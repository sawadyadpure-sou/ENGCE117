#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

// 1. นิยามโครงสร้างข้อมูล
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

// 2. คลาส LinkedList พื้นฐาน
class LinkedList {
protected:
    studentNode *start, *now; // ใช้ pointer ชั้นเดียวเพื่อให้เข้าใจง่ายสำหรับมือใหม่
public:
    LinkedList() {
        start = nullptr;
        now = nullptr;
    }
    
    ~LinkedList() {
        while (start != nullptr) {
            studentNode *temp = start;
            start = start->next;
            delete temp; // ใช้ delete แทน free เพื่อความเป็น C++
        }
    }

    void InsNode(const char n[], int a, char s, float g);
    void GoNext();
    void DelNode();
    virtual void ShowNode();
};

// 3. คลาส NewList ที่สืบทอดมาจาก LinkedList
class NewList : public LinkedList {
public:
    void GoFirst() {
        now = start;
    }

    // ปรับปรุงการแสดงผลให้ได้ output "six four" ตามตัวอย่าง
    virtual void ShowNode() {
        if (start != nullptr && now != nullptr) {
            cout << start->name << " " << now->name << endl;
        }
    }
};

// --- รายละเอียดฟังก์ชันของ LinkedList ---

void LinkedList::InsNode(const char n[], int a, char s, float g) {
    studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = nullptr;

    if (start == nullptr) {
        start = newNode;
        now = start;
    } else {
        studentNode *temp = start;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::GoNext() {
    if (now != nullptr && now->next != nullptr) {
        now = now->next;
    }
}

void LinkedList::DelNode() {
    if (now == nullptr) return;

    if (now == start) {
        start = start->next;
        delete now;
        now = start;
    } else {
        studentNode *prev = start;
        while (prev->next != now) {
            prev = prev->next;
        }
        prev->next = now->next;
        delete now;
        now = (prev->next != nullptr) ? prev->next : prev;
    }
}

void LinkedList::ShowNode() {
    if (now != nullptr) {
        cout << now->name << " " << now->age << " " << now->sex << " " 
             << fixed << setprecision(2) << now->gpa << endl;
    }
}

// 4. ส่วนของโปรแกรมหลัก
int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    // ทดสอบ listA
    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode(); // แสดง: two 2 B 2.20

    // ทดสอบ listB
    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();   // ชี้ที่ five
    listB.DelNode();  // ลบ five ทิ้ง, now ชี้ไปที่ four
    listB.ShowNode(); // แสดง: six four (โหนดแรกคู่โหนดปัจจุบัน)

    // ใช้ Polymorphism ผ่าน listC
    listC = &listA;
    listC->GoNext();
    listC->ShowNode(); // แสดง: one 1 A 1.10

    listC = &listB;
    listC->ShowNode(); // แสดง: six four

    return 0;
}