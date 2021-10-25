#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m)
    {
        vector<int> v[n + 1];
        int V[n + 1] = {0}, D[n + 1] = {0}, R[n + 1] = {0}, A = 0;
        for (auto i : dependency)
        {
            v[i.first].push_back(i.second);
            D[i.second]++;
        }
        vector<int> q;
        for (int i = 0; i < n; i++)
        {
            if (D[i] == 0)
            {
                V[i] = 1;
                q.push_back(i);
            }
            R[i] = duration[i];
            A = max(A, R[i]);
        }
        while (q.size())
        {
            int node = q.back();
            q.pop_back();
            for (auto i : v[node])
            {
                D[i]--;
                R[i] = max(R[node] + duration[i], R[i]);
                if (D[i] == 0)
                {
                    q.push_back(i);
                    V[i] = 1;
                    A = max(A, R[i]);
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (V[i] == 0)
                return -1;
        return A;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++)
            cin >> duration[i];
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}
