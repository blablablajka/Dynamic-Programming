#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
map<int, long long int>solved; // Хеш-таблица для мемоизации наших данных
int cuzcounter = 0;
int cuz2counter = 0;
int cuz3counter = 0;

long long int cuz(int i)
{
    cuzcounter++;
    if(i <= 2){
        return 1;                 // Метод через рекурсию. Самый долгий, потому что провоцирует дерево функций
    }
    if(i == 3)
        return 2;
                         // Экспоненциальный рост
    return cuz(i - 1) + cuz(i - 2) + cuz(i - 3);
}

long long int cuz2(int i)
{
    cuz2counter++;
    if(i <= 2)
        return 1;
    if(i == 3)
        return 2;
    if(solved.count(i))                            // В несколько раз быстрее чем рекурсию
        return solved[i];
    long long int ans = cuz2(i - 1) + cuz2(i - 2) + cuz(i - 3); // Принцип заключается в том, что мы сохраняем значения которые посчитали в map
    solved[i] = ans;                               // И из-за этого когда мы вызываем cuz2(i - 2), то это значение как-бы разбивается
    return ans;                                    // Если бы мы не использовали мемоизацию, нам бы пришлось эти значения снова считать и вызывать функцию
}
long long int cuz3(int i)
{
    vector<long long int> dp(i + 1);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int j = 3; j <= i; j++) // Начинаем отсчет с 3, потому что после 2 индекса идут не однерки
    {
        cuz3counter++;
        dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3]; // По-настоящему динамическая реализация, считаем каждый элемент массива по отдельности
    }                                  // То есть мы нашу задачу об нахождении значения числа количества способов найти путь до N кувшинки, разбиваем на некую подстроку
    return dp[i];
}

int main(){
   int cl;
   cin>>cl;
   cout<<cuz3(cl)<<" cuz3counter = "<<cuz3counter<<" Динамическая реализация\n";
   cout<<cuz2(cl)<<" cuz2counter = "<<cuz2counter<<" Рекурсия с мемоизацией\n";
   cout<<cuz(cl)<<" cuzcounter = "<<cuzcounter<<" Рекурсия";
}
