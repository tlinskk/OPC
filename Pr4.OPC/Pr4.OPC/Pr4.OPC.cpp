#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

struct SubjectInfo {
    string group;
    string subject;
    string teacher;
    double averageMark;
};

class SubjectBase {
protected:
    vector<SubjectInfo> subjects;

public:
    void inputData() {
        int n;
        cout << "Введіть кількість записів: ";
        cin >> n;
        subjects.resize(n);

        for (int i = 0; i < n; ++i) {
            cout << "\nЗапис #" << i + 1 << ":\n";
            cout << "Група: ";
            cin >> subjects[i].group;
            cout << "Предмет: ";
            cin >> subjects[i].subject;
            cout << "Викладач: ";
            cin >> subjects[i].teacher;

            double mark;
            do {
                cout << "Середній бал (від 1 до 5): ";
                cin >> mark;
                if (mark < 1.0 || mark > 5.0) {
                    cout << "Помилка! Середній бал має бути в діапазоні від 1 до 5.\n";
                }
            } while (mark < 1.0 || mark > 5.0);
            subjects[i].averageMark = mark;
        }
    }

    void showData() {
        cout << "\n--- Список предметів ---\n";
        for (const auto& s : subjects) {
            cout << "Група: " << s.group
                << ", Предмет: " << s.subject
                << ", Викладач: " << s.teacher
                << ", Середній бал: " << s.averageMark << endl;
        }
    }

    vector<SubjectInfo>& getSubjects() {
        return subjects;
    }
};

class SubjectSorter : public SubjectBase {
public:
    void sortByAverageDescending() {
        sort(subjects.begin(), subjects.end(), [](const SubjectInfo& a, const SubjectInfo& b) {
            return a.averageMark > b.averageMark;
            });
    }

    void showBestPhysicsGroup() {
        vector<SubjectInfo> physicsSubjects;

        for (const auto& s : subjects) {
            if (s.subject == "фізика") {
                physicsSubjects.push_back(s);
            }
        }

        if (physicsSubjects.empty()) {
            cout << "\nНе знайдено записів з предметом «Фізика».\n";
            return;
        }

        double maxMark = max_element(physicsSubjects.begin(), physicsSubjects.end(),
            [](const SubjectInfo& a, const SubjectInfo& b) {
                return a.averageMark < b.averageMark;
            })->averageMark;

        cout << "\nГрупи з найвищим середнім балом з фізики (" << maxMark << "):\n";
        for (const auto& s : physicsSubjects) {
            if (s.averageMark == maxMark) {
                cout << "Група: " << s.group << endl;
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SubjectSorter sorter;
    sorter.inputData();
    sorter.showData();
    sorter.showBestPhysicsGroup();

    return 0;
}
