#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<int, long long int>solved; // Хеш-таблица для мемоизации наших данных
int fibcounter = 0;
int fib2counter = 0;
int fib3counter = 0;
// Число фибоначчи.

long long int fib(int i)
{
    fibcounter++;
    if(i <= 2){
        return 1;                 // Метод через рекурсию. Самый долгий, потому что провоцирует дерево функций
    }                             // Экспоненциальный рост
    return fib(i - 1) + fib(i - 2);
}

long long int fib2(int i)
{
    fib2counter++;
    if(i <= 2)
        return 1;
    if(solved.count(i))                            // В несколько раз быстрее чем рекурсию
        return solved[i];
    long long int ans = fib2(i - 1) + fib2(i - 2); // Принцип заключается в том, что мы сохраняем значения которые посчитали в map
    solved[i] = ans;                               // И из-за этого когда мы вызываем fib2(i - 2), то это значение как-бы разбивается
    return ans;                                    // Если бы мы не использовали мемоизацию, нам бы пришлось эти значения снова считать и вызывать функцию
}
long long int fib3(int i)
{
    vector<long long int> dp(i + 1);
    dp[1] = 1;
    dp[2] = 1;
    for (int j = 3; j <= i; j++) // Начинаем отсчет с 3, потому что после 2 индекса идут не однерки
    {
        fib3counter++;
        dp[j] = dp[j - 1] + dp[j - 2]; // По-настоящему динамическая реализация, считаем каждый элемент массива по отдельности
    }                                  // То есть мы нашу задачу об нахождении значения числа фибоначчи, разбиваем на подстроку
    return dp[i];
}

int main(){
   cout<<fib3(16)<<" fib3counter = "<<fib3counter<<" Динамическая реализация\n";
   cout<<fib2(16)<<" fib2counter = "<<fib2counter<<" Рекурсия с мемоизацией\n";
   cout<<fib(16)<<" fibcounter = "<<fibcounter<<" Рекурсия";
}
