// Масив a із 22 цілих елементів, значення з діапазону [-10; 35].
// Критерій: x > 0 або x не кратне 3, ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// Критерій відбору елемента: додатний АБО не кратний 3
bool Satisfies(int x)
{
    return x > 0 || x % 3 != 0;
}

// Заповнює масив випадковими числами з діапазону [low; high]
void Create(int a[], const int n, const int low, const int high)
{
    for (int i = 0; i < n; i++)
        a[i] = low + rand() % (high - low + 1);
}

// Виводить масив у рядок (кожен елемент у полі шириною 4)
void Print(const int a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Повертає кількість елементів, що задовольняють критерій
int Count(const int a[], const int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (Satisfies(a[i]))
            count++;
    return count;
}

// Повертає суму елементів, що задовольняють критерій
int Sum(const int a[], const int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (Satisfies(a[i]))
            sum += a[i];
    return sum;
}

// Замінює нулями елементи, що задовольняють критерій
void Zero(int a[], const int n)
{
    for (int i = 0; i < n; i++)
        if (Satisfies(a[i]))
            a[i] = 0;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));

    const int n = 22;
    const int low = -10;
    const int high = 35;
    int a[n];

    Create(a, n, low, high);
    cout << "Початковий масив:" << endl;
    Print(a, n);

    // кількість і сума обчислюються ДО заміни елементів нулями
    cout << "Кількість елементів: " << Count(a, n) << endl;
    cout << "Сума елементів: " << Sum(a, n) << endl;

    Zero(a, n);
    cout << "Модифікований масив:" << endl;
    Print(a, n);

    return 0;
}