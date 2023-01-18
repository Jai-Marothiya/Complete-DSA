// Recursion questions : Count Ways To Reach The N-th Stairs if you either take 1 or 2 steps at a time.
#include <bits/stdc++.h>
using namespace std;

int countDistinctWays(int nStairs)
{
    //  base case.
    if (nStairs == 0)
        return 1;

    if (nStairs < 0)
        return 0;

    return (countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2));
}

int main()
{
    int n;
    cout << "Enter stair at which you are : ";
    cin >> n;

    cout << "Total number of ways to each " << n << "th stair is : " << countDistinctWays(n);

    return 0;
}