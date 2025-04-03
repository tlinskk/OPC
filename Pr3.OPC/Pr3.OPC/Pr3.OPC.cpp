#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

struct Subject {
    int id;
    std::string name;
    std::string examType;
    std::string teacher;
    std::string group;
    double averageScore;

    // Явне перетворення в рядок
    explicit operator std::string() const {
        return name + " - " + group + " - " + std::to_string(averageScore);
    }
};

class SubjectArray {
private:
    std::vector<Subject> subjects;

public:
    // Конструктор за замовчуванням
    SubjectArray() {}

    // Конструктор копіювання
    SubjectArray(const SubjectArray& other) : subjects(other.subjects) {}

    // Додавання предмета з перевантаженням
    void addSubject(const Subject& subject) {
        subjects.push_back(subject);
    }

    void addSubject(const std::string& name, const std::string& group, const std::string& examType, const std::string& teacher, double averageScore) {
        Subject sub;
        sub.id = static_cast<int>(subjects.size() + 1);
        sub.name = name;
        sub.group = group;
        sub.examType = examType;
        sub.teacher = teacher;
        sub.averageScore = averageScore;
        subjects.push_back(sub);
    }

    void inputSubjects() {
        std::vector<std::string> groups = { "ОА-11", "СМ-11", "ЕП-11" };
        std::vector<std::string> subjectsNames = { "Фізика", "Хімія", "ТММ" };

        for (const auto& group : groups) {
            for (size_t i = 0; i < subjectsNames.size(); ++i) {
                Subject sub;
                sub.id = static_cast<int>(subjects.size() + 1);
                sub.name = subjectsNames[i];
                sub.group = group;

                std::cout << "\nВведіть дані для предмету: " << sub.name << " (група: " << group << ")\n";
                std::cout << "Тип заліку (залік/екзамен): ";
                std::cin >> sub.examType;
                std::cout << "Прізвище викладача: ";
                std::cin >> sub.teacher;

                // Перевірка введеного середнього балу
                do {
                    std::cout << "Введіть середній бал (2 - 5): ";
                    std::cin >> sub.averageScore;
                    if (sub.averageScore < 2 || sub.averageScore > 5) {
                        std::cout << "Невірний бал! Середній бал повинен бути в діапазоні від 2 до 5.\n";
                    }
                } while (sub.averageScore < 2 || sub.averageScore > 5);

                subjects.push_back(sub);
            }
        }
    }

    void printSubjects() const {
        for (const auto& sub : subjects) {
            std::cout << "\nID: " << sub.id
                << "\nНазва предмету: " << sub.name
                << "\nТип заліку: " << sub.examType
                << "\nВикладач: " << sub.teacher
                << "\nГрупа: " << sub.group
                << "\nСередній бал: " << sub.averageScore << "\n";
        }
    }

    // Пошук груп з найвищим балом із фізики
    std::vector<std::string> findBestPhysicsGroups() const {
        double maxScore = 0;
        std::vector<std::string> bestGroups;

        // Максимальний бал з фізики
        for (const auto& sub : subjects) {
            if (sub.name == "Фізика") {
                if (sub.averageScore > maxScore) {
                    maxScore = sub.averageScore;
                    bestGroups.clear();
                    bestGroups.push_back(sub.group);
                }
                else if (sub.averageScore == maxScore) {
                    bestGroups.push_back(sub.group);
                }
            }
        }

        return bestGroups;
    }

    // Сортування предметів за групою (по алфавіту)
    void sortByGroup() {
        std::sort(subjects.begin(), subjects.end(), [](const Subject& a, const Subject& b) {
            return a.group < b.group;
            });
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SubjectArray subjects;
    subjects.inputSubjects();
    subjects.sortByGroup();
    subjects.printSubjects();

    // Знаходження групи з найвищим балом із фізики
    std::vector<std::string> bestPhysicsGroups = subjects.findBestPhysicsGroups();
    if (!bestPhysicsGroups.empty()) {
        std::cout << "\nГрупи з найвищим середнім балом із фізики: ";
        for (const auto& group : bestPhysicsGroups) {
            std::cout << group << " ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "\nЖодна група не має оцінок із фізики.\n";
    }

    return 0;
}


