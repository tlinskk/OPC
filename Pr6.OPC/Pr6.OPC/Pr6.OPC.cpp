/*//Програма 1
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <windows.h> 

using namespace std;


void printVector(const vector<char>& v) {
    cout << "Вміст вектору: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}


void printMap(const map<int, char>& m) {
    cout << "Вміст мапи: ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << "[" << it->first << "]=" << it->second << " ";
    }
    cout << endl;
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<char> vec;
    int n;

    
    cout << "1. Введіть кількість елементів для вектору: ";
    cin >> n;
    cout << "Введіть " << n << " символів:\n";
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        vec.push_back(c);
    }

   
    cout << "\n2. Початковий вектор:\n";
    printVector(vec);

    
    cout << "\n3. Видалення першого елементу та заміна другого на '@' (якщо існує):\n";
    if (!vec.empty()) {
        vec.erase(vec.begin()); // видалити перший
        if (!vec.empty()) vec[0] = '@'; // замінити новий перший
    }

   
    cout << "\n4. Перегляд вектору з використанням ітераторів:\n";
    printVector(vec);

    
    map<int, char> m;
    int mCount;
    cout << "\n5. Введіть кількість елементів для мапи: ";
    cin >> mCount;
    cout << "Введіть " << mCount << " символів:\n";
    for (int i = 0; i < mCount; ++i) {
        char c;
        cin >> c;
        m[i] = c;
    }

   
    int delCount;
    cout << "\n6. Скільки елементів видалити після першого елементу вектору? ";
    cin >> delCount;

    if (vec.size() > 1) {
        int start = 1;
        int end = min((int)vec.size(), start + delCount);
        vec.erase(vec.begin() + start, vec.begin() + end);
    }

    
    for (auto it = m.begin(); it != m.end(); ++it) {
        vec.push_back(it->second);
    }

    
    cout << "\n7. Перший (вектор) після змін:\n";
    printVector(vec);

    cout << "\nДругий (мапа):\n";
    printMap(m);

    return 0;
}
*/






//2 програма

/*#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <windows.h>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    void input() {
        cout << "Введіть ім'я: ";
        cin >> name;
        cout << "Введіть вік: ";
        cin >> age;
    }

    void print() const {
        cout << name << " (" << age << " років)";
    }
};

void printVector(const vector<Person>& vec) {
    cout << "Вміст вектору:\n";
    for (const auto& person : vec) {
        person.print();
        cout << "  ";
    }
    cout << "\n";
}

void printMap(const map<int, Person>& m) {
    cout << "Вміст мапи:\n";
    for (const auto& pair : m) {
        cout << "[" << pair.first << "] = ";
        pair.second.print();
        cout << "  ";
    }
    cout << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Person> people;

    int n;
    cout << "1. Введіть кількість елементів для вектору: ";
    cin >> n;
    cout << "Введіть " << n << " осіб:\n";
    for (int i = 0; i < n; ++i) {
        Person p;
        p.input();
        people.push_back(p);
    }

    cout << "\n2. Початковий вектор:\n";
    printVector(people);

    cout << "\n3. Видалення першого елементу та заміна другого на 'Іван (99 років)':\n";
    if (!people.empty()) {
        people.erase(people.begin());
    }
    if (people.size() >= 1) {
        people[0] = Person("Іван", 99);
    }

    cout << "\n4. Перегляд вектору з використанням ітераторів:\n";
    cout << "Вміст вектору:\n";
    for (auto it = people.begin(); it != people.end(); ++it) {
        it->print();
        cout << "  ";
    }
    cout << "\n";

    map<int, Person> peopleMap;
    int m;
    cout << "\n5. Введіть кількість елементів для мапи: ";
    cin >> m;
    cout << "Введіть " << m << " осіб:\n";
    for (int i = 0; i < m; ++i) {
        Person p;
        p.input();
        peopleMap[i] = p;
    }

    int toDelete;
    cout << "\n6. Скільки елементів видалити після першого елементу вектору? ";
    cin >> toDelete;

    if (people.size() > 1) {
        auto it = people.begin() + 1;
        int remaining = people.end() - it;
        int count = min(toDelete, remaining);
        people.erase(it, it + count);
    }

    for (const auto& pair : peopleMap) {
        people.push_back(pair.second);
    }

    cout << "\n7. Перший (вектор) після змін:\n";
    printVector(people);

    cout << "\nДругий (мапа):\n";
    printMap(peopleMap);

    return 0;
}*/


//3 програма


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <windows.h>

class Person {
public:
    std::string name;
    int age;

    Person() : name(""), age(0) {}  

    Person(std::string name_, int age_) : name(name_), age(age_) {}

    bool operator<(const Person& other) const {
        return age < other.age;
    }

    bool operator>(const Person& other) const {
        return age > other.age;
    }

    void print() const {
        std::cout << "Ім'я: " << name << ", Вік: " << age << std::endl;
    }
};


bool isOver25(const Person& p) {
    return p.age > 25;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Person> vec;
    int n;

    std::cout << "1. Введіть кількість елементів для вектору: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string name;
        int age;
        std::cout << "Введіть ім'я та вік #" << i + 1 << ": ";
        std::cin >> name >> age;
        vec.push_back(Person(name, age));
    }

    
    std::sort(vec.begin(), vec.end(), std::greater<Person>());

  
    std::cout << "\n2. Відсортований по спаданню вектор:\n";
    for (const auto& p : vec) {
        p.print();
    }

    auto found = std::find_if(vec.begin(), vec.end(), isOver25);
    if (found != vec.end()) {
        std::cout << "\n3. Знайдено першу особу з віком > 25:\n";
        found->print();
    }
    else {
        std::cout << "\n3. Немає особи з віком > 25.\n";
    }

    std::map<int, Person> personMap;
    int index = 0;
    for (const auto& p : vec) {
        if (isOver25(p)) {
            personMap[index++] = p;
        }
    }

    std::cout << "\n4. Контейнер map з елементами, вік яких > 25:\n";
    for (const auto& pair : personMap) {
        std::cout << "[" << pair.first << "] ";
        pair.second.print();
    }

    std::sort(vec.begin(), vec.end());

    std::cout << "\n5. Вектор після сортування по зростанню:\n";
    for (const auto& p : vec) {
        p.print();
    }

    std::cout << "\n6. Map залишився без змін:\n";
    for (const auto& pair : personMap) {
        std::cout << "[" << pair.first << "] ";
        pair.second.print();
    }

    std::vector<Person> merged = vec;
    for (const auto& pair : personMap) {
        merged.push_back(pair.second);
    }

    
    std::cout << "\n7. Третій контейнер (злиття першого і другого):\n";
    for (const auto& p : merged) {
        p.print();
    }

    
    int count = std::count_if(merged.begin(), merged.end(), isOver25);
    std::cout << "\n8. Кількість елементів з віком > 25 у третьому контейнері: " << count << std::endl;

   
    bool exists = std::any_of(merged.begin(), merged.end(), isOver25);
    std::cout << "9. Чи є особа з віком > 25 у третьому контейнері? "
        << (exists ? "Так" : "Ні") << std::endl;

    return 0;
}
