#include <iostream>
using namespace std;
int main()
{
    long int arraySize, windowSize, temp, sum = 0;
    cin >> arraySize;
    cin >> windowSize;
    vector<int> vector_list1;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> temp;
        sum = sum + temp;
        vector_list1.push_back(temp);
    }
    make_heap(vector_list1.begin(), vector_list1.end());
    long int maximum = 0, res = 0;
    for (int i = 0; i < windowSize; i++)
    {
        maximum = vector_list1.front();
        sum -= maximum;
        pop_heap(vector_list1.begin(), vector_list1.end());
        vector_list1.pop_back();
        res = maximum / 2;
        sum += res;
        vector_list1.push_back(res);
        push_heap(vector_list1.begin(), vector_list1.end());
    }
    cout << sum;
}
