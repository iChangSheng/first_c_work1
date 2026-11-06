#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string name;
    double chinese;
    double math;
    double english;
    double avg;
};

int main()
{
    int n;
    cin >> n;
    Student* stu = new Student[n];

    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].avg = (stu[i].chinese + stu[i].math + stu[i].english) / 3.0;
    }

    cout << left << setw(10) << "姓名"
         << setw(8) << "语文"
         << setw(8) << "数学"
         << setw(8) << "英语"
         << setw(10) << "平均分"
         << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << stu[i].name
             << setw(8) << stu[i].chinese
             << setw(8) << stu[i].math
             << setw(8) << stu[i].english
             << setw(10) << stu[i].avg;
        if (stu[i].avg >= 90)
            cout << "Excellent";
        cout << endl;
    }
    delete[] stu;
    return 0;
}

