#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // 引入头文件，用于设置输出格式
using namespace std;

class Student {
public:
    string id;
    string name;
    string class_name;
    double math_score;
    double English_score;
    double physics_score;
    double c_score;

    Student(string id, string n, string c, double m, double e, double p, double cl)
        : id(id), name(n), class_name(c), math_score(m), English_score(e), physics_score(p), c_score(cl) {}
};//创造Student类的构造函数。



class studentmanagementsystem {
private:
    vector<Student> students;
public:
    void Menu() {
        cout << "=====学生管理系统=====" << endl;
        cout << "1.输入数据" << endl;
        cout << "2.修改数据" << endl;
        cout << "3.输出数据" << endl;
        cout << "4.删除数据" << endl;
        cout << "5.查找数据" << endl;
        cout << "6.退出系统" << endl;
    }

    void inputdata() {
        string id, name, class_name;
        double math_score, English_score, physics_score, c_score;

        cout << "请输入学号" << endl;
        cin >> id;
        cout << "请输入姓名" << endl;
        cin >> name;
        cout << "请输入班级" << endl;
        cin >> class_name;
        cout << "请输入高数成绩" << endl;
        cin >> math_score;
        cout << "请输入英语成绩" << endl;
        cin >> English_score;
        cout << "请输入大学物理成绩" << endl;
        cin >> physics_score;
        cout << "请输入C语言成绩" << endl;
        cin >> c_score;

        students.push_back(Student(id, name, class_name, math_score, English_score, physics_score, c_score));
        //将一个新的 Student 对象添加到 students 向量（vector<Student>）中。
        cout << "数据已输入" << endl;
    }

    void changedata() {
        string id;
        for (auto& student : students) {  //范围基的 for 循环，用于遍历容器中的每一个元素。
            cout << "请输入学号修改";
            cin >> id;
            if (student.id == id) {
                cout << "找到学生，输入新的成绩" << endl;
                cout << "请输入高数成绩" << endl;
                cin >> student.math_score;
                cout << "请输入英语成绩" << endl;
                cin >> student.English_score;
                cout << "请输入大学物理成绩" << endl;
                cin >> student.physics_score;
                cout << "请输入C语言成绩" << endl;
                cin >> student.c_score;
                cout << "数据修改成功" << endl;
                break;
            }
            else {
                cout << "未找到该学生，请重新输入" << endl;
            }
        }
    }
    void outdeta() {
        if (students.empty()) {
            cout << "没有任何学生信息"<<endl;
        }
        else {
            cout << "\n===== 学生信息 =====" << endl;
            cout << left << setw(15) << "学号"  //left向左对齐，setw设置输入间隔
                << setw(20) << "姓名"
                << setw(15) << "班级"
                << setw(10) << "高数"
                << setw(10) << "英语"
                << setw(15) << "大学物理"
                << setw(10) << "C语言" << endl;
            cout << "----------------------------------------" << endl;

            for (auto& student : students) {
                cout << left << setw(15) << student.id
                    << setw(20) << student.name
                    << setw(15) << student.class_name
                    << setw(10) << student.math_score
                    << setw(10) << student.English_score
                    << setw(15) << student.physics_score
                    << setw(10) << student.c_score << endl;
           /* cout << "学生信息如下" << endl;
            for (auto& student : students) {
                cout << "学号：" << student.id;
                cout << "姓名：" << student.name;
                cout << "班级：" << student.class_name;
                cout << "高数成绩：" << student.math_score;
                cout << "英语成绩：" << student.English_score;
                cout << "大学物理成绩：" << student.physics_score;
                cout << "c语言：" << student.c_score << endl;*/
            }

        }
        
    }

    void deletedeta()
    {
        string id;
        cout << "请输入删除学生的学号"<<endl;
        cin >> id;

        auto it = students.begin();//声明并初始化一个迭代器 it，它指向 students 容器的第一个元素。
        bool found = false;

        for (;it != students.end();++it) {
            if (it->id == id) {
                found = true;
                break;
            }
        }
        if (found) {
            students.erase(it);//erase删除it指向的元素
            cout << "已删除该学生的数据" << endl;
        }
        else {
            cout << "未找到该学生，删除失败" << endl;
        }
    }






    void searchdate() {
        string id;
        string name;
        int way;
        start://goto位置
        cout << "请输入你的查找方式，1、学号；2、姓名" << endl;
        cin >> way;
        if (way ==1) {
            for (auto& student : students) {
               
                cout << "请输入学号查找";
                cin >> id;
                if (student.id == id) {
                    cout << "高数成绩：" << student.math_score << endl;;
                    cout << "英语成绩：" << student.English_score << endl;;
                    cout << "大学物理成绩：" << student.physics_score << endl;
                    cout << "c语言：" << student.c_score << endl;
                    break;
                }
                else {
                    cout << "未找到该学生，请选择下面操作，1、重新输入；其他返回菜单" << endl;
                    int operate;
                    cin >> operate;
                    if (operate == 1) {
                        goto start;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else if (way == 2) {
            for (auto& student : students) {
        
                cout << "请输入姓名查找";
                cin >> name;
                if (student.name == name) {
                    cout << "高数成绩：" << student.math_score << endl;
                    cout << "英语成绩：" << student.English_score << endl;;
                    cout << "大学物理成绩：" << student.physics_score << endl;;
                    cout << "c语言：" << student.c_score << endl;
                    break;
                }
                else {
                    cout << "未找到该学生，请选择下面操作，1、重新输入；其他返回菜单" << endl;
                    int operate;
                    cin >> operate;
                    if (operate == 1) {
                        goto start;
                    }
                    else
                    {
                        break;
                    }
                  


                }
            }
        }
        else
        {
            cout << "输入无效" << endl;
        }


    }

};















int main() {
    studentmanagementsystem sms;//将studentmanagementsystem改名为sms
    int chioce;
    while (true) {
        sms.Menu();
        cout << "请选择操作"<<endl;
        cin >> chioce;

        switch (chioce)
        {
        case 1:
            sms.inputdata();
            break;
        case 2:
            sms.changedata();
            break;
        case 3:
            sms.outdeta();
            break;
        case 4:
            sms.deletedeta();
            break;
        case 5:
            sms.searchdate();
            break;
        case 6:
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default :
            cout << "输入无效，请重新输入" << endl;
            break;








        }



















    }
    system("pause");
    return 0;
}