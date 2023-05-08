#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Client {
    int year;
    int month;
    int duration;
    int code;
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // зчитування даних з файлу
    vector<Client> clients;
    string name = "lab_9.3.txt";
    //cout << "Введіть назву файла: "; cin >> name;
    ifstream file(name);
    int year, month, duration, code;
    while (file >> year >> month >> duration >> code) {
        clients.push_back({ year, month, duration, code });
    }

    // груповання клієнтів за кодом
    map<int, int> total_durations;
    for (const auto& client : clients) {
        total_durations[client.code] += client.duration;
    }

    // сортування клієнтів за зменшенням сумарної тривалості та зростання коду
    vector<pair<int, int>> sorted_clients(total_durations.begin(), total_durations.end());
    sort(sorted_clients.begin(), sorted_clients.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        else {
            return a.second > b.second;
        }
        });

    // вивід результатів
    for (const auto& pair : sorted_clients) {
        cout << pair.second << " " << pair.first << endl;
    }

    return 0;
}