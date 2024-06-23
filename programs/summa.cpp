    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int n;
        cin >> n;
        int count = 0;
        while (n != 0)
        {
            int digit = n % 10;
            if (digit == 7  || digit == 4)
            {
                count++;
            }
            n /= 10;
        }
        if (count == 7  || count == 4)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }