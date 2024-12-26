#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // ����ͷ�ļ����������������ʽ
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
};//����Student��Ĺ��캯����



class studentmanagementsystem {
private:
    vector<Student> students;
public:
    void Menu() {
        cout << "=====ѧ������ϵͳ=====" << endl;
        cout << "1.��������" << endl;
        cout << "2.�޸�����" << endl;
        cout << "3.�������" << endl;
        cout << "4.ɾ������" << endl;
        cout << "5.��������" << endl;
        cout << "6.�˳�ϵͳ" << endl;
    }

    void inputdata() {
        string id, name, class_name;
        double math_score, English_score, physics_score, c_score;

        cout << "������ѧ��" << endl;
        cin >> id;
        cout << "����������" << endl;
        cin >> name;
        cout << "������༶" << endl;
        cin >> class_name;
        cout << "����������ɼ�" << endl;
        cin >> math_score;
        cout << "������Ӣ��ɼ�" << endl;
        cin >> English_score;
        cout << "�������ѧ����ɼ�" << endl;
        cin >> physics_score;
        cout << "������C���Գɼ�" << endl;
        cin >> c_score;

        students.push_back(Student(id, name, class_name, math_score, English_score, physics_score, c_score));
        //��һ���µ� Student ������ӵ� students ������vector<Student>���С�
        cout << "����������" << endl;
    }

    void changedata() {
        string id;
        for (auto& student : students) {  //��Χ���� for ѭ�������ڱ��������е�ÿһ��Ԫ�ء�
            cout << "������ѧ���޸�";
            cin >> id;
            if (student.id == id) {
                cout << "�ҵ�ѧ���������µĳɼ�" << endl;
                cout << "����������ɼ�" << endl;
                cin >> student.math_score;
                cout << "������Ӣ��ɼ�" << endl;
                cin >> student.English_score;
                cout << "�������ѧ����ɼ�" << endl;
                cin >> student.physics_score;
                cout << "������C���Գɼ�" << endl;
                cin >> student.c_score;
                cout << "�����޸ĳɹ�" << endl;
                break;
            }
            else {
                cout << "δ�ҵ���ѧ��������������" << endl;
            }
        }
    }
    void outdeta() {
        if (students.empty()) {
            cout << "û���κ�ѧ����Ϣ"<<endl;
        }
        else {
            cout << "\n===== ѧ����Ϣ =====" << endl;
            cout << left << setw(15) << "ѧ��"  //left������룬setw����������
                << setw(20) << "����"
                << setw(15) << "�༶"
                << setw(10) << "����"
                << setw(10) << "Ӣ��"
                << setw(15) << "��ѧ����"
                << setw(10) << "C����" << endl;
            cout << "----------------------------------------" << endl;

            for (auto& student : students) {
                cout << left << setw(15) << student.id
                    << setw(20) << student.name
                    << setw(15) << student.class_name
                    << setw(10) << student.math_score
                    << setw(10) << student.English_score
                    << setw(15) << student.physics_score
                    << setw(10) << student.c_score << endl;
           /* cout << "ѧ����Ϣ����" << endl;
            for (auto& student : students) {
                cout << "ѧ�ţ�" << student.id;
                cout << "������" << student.name;
                cout << "�༶��" << student.class_name;
                cout << "�����ɼ���" << student.math_score;
                cout << "Ӣ��ɼ���" << student.English_score;
                cout << "��ѧ����ɼ���" << student.physics_score;
                cout << "c���ԣ�" << student.c_score << endl;*/
            }

        }
        
    }

    void deletedeta()
    {
        string id;
        cout << "������ɾ��ѧ����ѧ��"<<endl;
        cin >> id;

        auto it = students.begin();//��������ʼ��һ�������� it����ָ�� students �����ĵ�һ��Ԫ�ء�
        bool found = false;

        for (;it != students.end();++it) {
            if (it->id == id) {
                found = true;
                break;
            }
        }
        if (found) {
            students.erase(it);//eraseɾ��itָ���Ԫ��
            cout << "��ɾ����ѧ��������" << endl;
        }
        else {
            cout << "δ�ҵ���ѧ����ɾ��ʧ��" << endl;
        }
    }






    void searchdate() {
        string id;
        string name;
        int way;
        start://gotoλ��
        cout << "��������Ĳ��ҷ�ʽ��1��ѧ�ţ�2������" << endl;
        cin >> way;
        if (way ==1) {
            for (auto& student : students) {
               
                cout << "������ѧ�Ų���";
                cin >> id;
                if (student.id == id) {
                    cout << "�����ɼ���" << student.math_score << endl;;
                    cout << "Ӣ��ɼ���" << student.English_score << endl;;
                    cout << "��ѧ����ɼ���" << student.physics_score << endl;
                    cout << "c���ԣ�" << student.c_score << endl;
                    break;
                }
                else {
                    cout << "δ�ҵ���ѧ������ѡ�����������1���������룻�������ز˵�" << endl;
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
        
                cout << "��������������";
                cin >> name;
                if (student.name == name) {
                    cout << "�����ɼ���" << student.math_score << endl;
                    cout << "Ӣ��ɼ���" << student.English_score << endl;;
                    cout << "��ѧ����ɼ���" << student.physics_score << endl;;
                    cout << "c���ԣ�" << student.c_score << endl;
                    break;
                }
                else {
                    cout << "δ�ҵ���ѧ������ѡ�����������1���������룻�������ز˵�" << endl;
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
            cout << "������Ч" << endl;
        }


    }

};















int main() {
    studentmanagementsystem sms;//��studentmanagementsystem����Ϊsms
    int chioce;
    while (true) {
        sms.Menu();
        cout << "��ѡ�����"<<endl;
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
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default :
            cout << "������Ч������������" << endl;
            break;








        }



















    }
    system("pause");
    return 0;
}