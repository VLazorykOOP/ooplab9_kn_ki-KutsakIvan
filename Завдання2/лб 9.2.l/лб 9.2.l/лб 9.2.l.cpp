#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string name = "lab_9.2.txt";
    vector<int> V;
    //cout << "Bведіть назву файла: "; cin >> name;
    //vector<int> V = { 1, 2, 3, 4, 3, 1 }; 

    int n = 1, number;
    while (n % 2 != 0)
    {
        cout << "Введіть кількість чисел(парне число): "; cin >> n;
        if (n % 2 != 0)cout << "Ви ввели не парне число." << endl;
    }

    cout << "Введіть " << n << " чисел" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        V.push_back(number);
    }

    // створимо два допоміжні контейнера
    set<int> first_half(V.begin(), V.begin() + V.size() / 2);
    set<int> second_half(V.begin() + V.size() / 2, V.end());

    // Знаходимо перетин множин
    set<int> intersection;
    set_intersection(first_half.begin(), first_half.end(), second_half.begin(), second_half.end(),
        inserter(intersection, intersection.begin()));

    // Записуємо результат в файл
    cout << "\n=====================================================\n";
    ofstream outfile(name);
    if (outfile.is_open()) {
        copy(intersection.begin(), intersection.end(), ostream_iterator<int>(outfile, " "));
        outfile.close();
        cout << "Результати записані в файл " << name << endl;
    }
    else {
        cout << "Помилка відкриття файла " << name << endl;
    }

    return 0;
}