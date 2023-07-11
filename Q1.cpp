/* Read input from STDIN. Print your output to STDOUT*/
// Stop the Shame (100 Marks)
/*
The general public often body shame the people who are obese or not beautiful as per their standard of weight. They do not even consider that it might be a medical condition for some people. Because of this, the people start doubting themselves and start cutting them off from the general discussions or the public places. To fight body shaming and spread awareness about the issue, an event is conducted in the city where people are participating and are ranked according to their weights from highest to lowest. The people with the same weights are ranked the same.


There are N people who have already participated. The official has noted their weight and has ranked them. The problem is, he has fallen sick and there are still P people who are left to rank and participate. Considering this, you are expected to finish the process and provide the rank of the P people. Once the person is ranked, his weight is included in the category and the weight of the new person will have to consider this weight also to be ranked. To help you out, the new P people are organized in a queue in increasing order of their weights.

5 3
120 100 100 90 60
40 40 80

5
5
4

*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write code here
    int n, p;
    cin >> n;
    cin >> p;

    vector<int> res(n + p, 0);
    vector<int> ans;
    vector<int> v(n);
    vector<int> u(p);

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (k == 0)
        {
            res[k] = v[i];
            k++;
        }
        if (k > 0 and res[k - 1] != v[i])
        {
            res[k] = v[i];
            k++;
        }
    }
    k--;

    for (int i = 0; i < p; i++)
    {
        cin >> u[i];
    }

    int i = 0;

    while (i < p)
    {
        if (k >= 0)
        {
            if (res[k] > u[i])
            {
                int r = k + 1 + 1;
                cout << r << endl;
                i++;
                while (i < p and u[i] == u[i - 1])
                {
                    cout << r << endl;
                    i++;
                }
            }
            else if (res[k] == u[i])
            {
                int r = k + 1;
                cout << r << endl;
                i++;
                while (i < p and u[i] == u[i - 1])
                {
                    cout << r << endl;
                    i++;
                }
            }
            else if (res[k] < u[i] and k >= 0)
            {
                while (k >= 0 and res[k] < u[i])
                    k--;
            }
        }
        else
        {
            while (i < p)
            {
                cout << 1 << endl;
                i++;
                while (i < p and u[i] == u[i - 1])
                {
                    cout << 1 << endl;
                    i++;
                }
            }
        }
    }
}
