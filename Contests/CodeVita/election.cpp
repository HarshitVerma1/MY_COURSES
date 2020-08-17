#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string string_1;
    cin >> string_1;
    int i = 0;
    int Voter_A = 0;
    int Voter_B = 0;
    int j = 0;
    while (string_1[j] != '\0')
    {
        if (string_1[j] == 'A')
            Voter_A++;
        else if (string_1[j] == 'B')
            Voter_B++;
        j++;
    }
    while (string_1[i] == '-')
    {
        i++;
    }
    if (string_1[i] == 'A')
    {
        Voter_A += i;
    }
    int start = i;
    for (; i < n;)
    {
        while (string_1[i] == '-' && i < n)
        {
            i++;
        }
        if (i == n)
        {
            break;
        }
        if (string_1[i] == 'A')
        {
            if (start == i)
            {
                i++;
                continue;
            }
            Voter_A = Voter_A + (i - start - 1);
            start = i;
            i++;
            continue;
        }
        start = i;
        i++;
        while (string_1[i] == '-' && i < n)
        {
            i++;
        }
        if (i == n)
            Voter_B = Voter_B + (i - start - 1);
        else
        {
            if (string_1[i] == 'A')
            {
                Voter_A = Voter_A + (i - start - 1) / 2;
                Voter_B = Voter_B + (i - start - 1) / 2;
                start = i;
                i++;
            }
            else
            {
                Voter_B = Voter_B + (i - start - 1);
            }
        }
    }
    if (Voter_A > Voter_B)
    {
        cout << "A" << endl;
    }
    else if (Voter_A == Voter_B)
    {
        cout << "Coalition government" << endl;
    }
    else
    {
        cout << "B" << endl;
    }
}