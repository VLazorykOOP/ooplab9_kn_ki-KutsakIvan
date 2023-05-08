#include <iostream>
#include <list>
//#include <algorithm>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //list<int> L = { 1, 2, -3, 4, -5, 6, 7, -8, 9 };
    list<int> L;
    int number, n;
    cout << "Введіть кількість чисел: "; cin >> n;
    cout << "Введіть числа: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        L.push_back(number);
    }
    cout << endl;

    // Знаходимо перший від'ємний елемент
    auto first_neg = find_if(L.begin(), L.end(), [](int x) { return x < 0; });

    // Якщо список не включає в себе від'ємних елементів, то не міняємо його
    if (first_neg == L.end()) {
        return 0;
    }

    // знаходимо другий від'ємний елемент
    auto second_neg = find_if(next(first_neg), L.end(), [](int x) { return x < 0; });

    // Якщо від'ємний елемент лише один, то видаляємо всі елементи після нього
    if (second_neg == L.end()) {
        L.erase(next(first_neg), L.end());
    }
    else {
        // видалення всіх чисел між першим та другим від'ємним елементом
        L.erase(next(first_neg), second_neg);
    }

    // Результат
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}