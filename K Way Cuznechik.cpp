#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
map<int, long long int>solved; // Хеш-таблица для мемоизации наших данных
int cuzcounter = 0;
int cuz2counter = 0;
int cuz3counter = 0;

long long int cuz(int i, int k)
{
    vector<long long int> dp(max(i, k) + 1);
    dp[1] = 1;

    for(int i = 2; i < dp.size(); i++)
    { dp[i] = 0;}

    for (int j = 1; j <= k; j++)
    {
        for(int l = 1; l < j; l++)  // Интересный цикл
        {
            dp[j] += dp[l];             // Суммируем элементы массива будто k равен
            cout<<"dp[j] "<<dp[j]<<" += dp[l] "<<dp[l]<<"  ";
            cout<<"\n";
        }
    }

    cout<<"\n\n";
    for(int j = k + 1; j <= i; j++)
    {
        for(int l = 1; l <= k; l++)
        {
            cout<<"dp[j] до += dp[j - l] "<<dp[j]<<"  ";
            dp[j] += dp[j - l];   // Ищем ответ на нашу задачу
            cout<<"| dp[j] += dp[j - l] "<<dp[j]<<"  ";     // То есть мы в прошлом цикле суммировали элементы а в этом цикле делаем их под k
            cout<<"\n";
        }
    }
    cout<<"\n";
    return dp[i];
}

int main(){
   int i, k;
   cin>>i>>k;
   cout<<cuz(i, k);
}
