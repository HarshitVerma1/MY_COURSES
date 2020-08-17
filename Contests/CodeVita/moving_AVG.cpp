#include <iostream>
using namespace std;
int main()
{
    int Length_1, Length_2;
    int n;
    cin >> Length_1 >> Length_2 >> n;
    double price[n];
    for (int i = 0; i < n; ++i)
        cin >> price[i];

    double max_size_1[n - Length_1 + 1], max_size_2[n - Length_2 + 1];
    double size_of_Sum = 0.0, sum_Length_2 = 0.0;

    for (int i = 0; i < Length_1; ++i)
        size_of_Sum += price[i];
    for (int i = 0; i < Length_2; ++i)
        sum_Length_2 += price[i];

    max_size_1[0] = size_of_Sum / Length_1;
    max_size_2[0] = sum_Length_2 / Length_2;
    int j = 1;
    for (int i = Length_1; i < n; ++i)
    {
        size_of_Sum += (-price[i - Length_1] + price[i]);
        max_size_1[j++] = size_of_Sum / Length_1;
    }
    j = 1;
    for (int i = Length_2; i < n; ++i)
    {
        sum_Length_2 += (price[i] - price[i - Length_2]);
        max_size_2[j++] = sum_Length_2 / Length_2;
    }

    int above = 0, count = 0;
    if (max_size_1[Length_2 - Length_1] > max_size_2[0])
        above = 1;
    if (max_size_1[Length_2 - Length_1] < max_size_2[0])
        above = -1;

    for (int i = 1; i < n - Length_2 + 1; ++i)
    {
        if (max_size_1[Length_2 - Length_1 + i] < max_size_2[i] && above == 1)
        {
            count++;
            above = -1;
        }
        else if (max_size_1[Length_2 - Length_1 + i] > max_size_2[i] && above == -1)
        {
            count++;
            above = 1;
        }
    }
    cout << count << endl;
}