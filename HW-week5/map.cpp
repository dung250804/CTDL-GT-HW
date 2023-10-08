    #include <iostream>
#include <map>
using namespace std;

class Student {
private:
    int id;
    string name = new char[100];
    string stuClass = new char[30];
public:
    Student(int id, string name, string stuClass) {
        this->id = id;
        this->name = name;
        this->stuClass = stuClass;
    }

    int getId(){
        return this->id;
    }

    string getName() {
        return this->name;
    }

    string getClass() {
        return this->stuClass;
    }
};

class StuManagement {
private:
    map<int, Student*> stuList;
public:
    void insertStu(int id, string name, string classs) {
        stuList[id] = new Student(id, name, classs);
    }

    void deleteStu(int id) {
        stuList[id] = nullptr;
        stuList.erase(id);
    }

    string findStuInfo(int id) {
        if(stuList.find(id) != stuList.end()
        && stuList.count(id) > 0
        && stuList[id] != nullptr)
            return stuList[id]->getName() + ", " + stuList[id]->getClass();
        else
            return "NA, NA";
    }
};


int main(){
    StuManagement test;
    for(;;) {
        string s;
        cin >> s;
        if(s == "insert" || s == "Insert") {
            int id;
            string name;
            string classs;
            cin >> id >> name >> classs;
            test.insertStu(id, name, classs);
        }
        if(s == "delete" || s == "Delete") {
            int id;
            cin >> id;
            test.deleteStu(id);;
        }
        if(s == "infor" || s == "Infor") {
            int id;
            cin >> id;
            cout << test.findStuInfo(id) << endl;
        }
    }
}
