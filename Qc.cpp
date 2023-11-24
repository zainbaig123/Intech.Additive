
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    long long trappingWater(int arr[], int n)
    {
        long long int t = 0, i, sum = 0, output = 0, c = 0, save;
        for (i = 0; i < n; i++)
        {
            if (arr[i] > t)
            {
                save = i;
                t = arr[i];
                break;
            }
        }
        sum = arr[i];
        c = c + 1;

        for (i + 1; i < n; i++)
        {
            if (arr[i] >= t)
            {
                output = output + (((c + 1) * t) - (sum + t));
                c = 1;
                sum = arr[i];
                t = arr[i];
                save = i;

                continue;
            }
            sum = sum + arr[i];
            c = c + 1;
        }
        t = 0;
        for (i = n - 1; i >= save; i--)
        {
            if (arr[i] > t)
            {
                t = arr[i];
                break;
            }
        }
        sum = arr[i];
        c = 1;
        for (i - 1; i >= save; i--)
        {
            if (arr[i] >= t)
            {
                output = output + (((c + 1) * t) - (sum + t));
                c = 1;
                sum = arr[i];
                t = arr[i];
                continue;
            }
            sum = sum + arr[i];
            c = c + 1;
        }
        return output;
    }
};

int main()
{

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution obj;

    cout << obj.trappingWater(a, n) << " Units of water will be trapped ." << endl;

    return 0;
}