// STL container : priority_queue. Always give largest element.
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    priority_queue<string> q;
    priority_queue<int> maxi;                            // give maximum first
    priority_queue<int, vector<int>, greater<int>> mini; // give minimum first

    maxi.push(5);
    maxi.push(2);
    maxi.push(1);
    maxi.push(3);
    maxi.push(4);

    while (!maxi.empty())
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    cout << "Size of priority_queue maxi-> " << maxi.size() << endl;
    cout << "empty or not -> " << (maxi.empty() ? "Yes" : "No") << endl;
    cout << endl;

    mini.push(5);
    mini.push(2);
    mini.push(1);
    mini.push(3);
    mini.push(4);

    while (!mini.empty())
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
    cout << "Size of priority_queue mini-> " << mini.size() << endl;
    cout << "empty or not -> " << (mini.empty() ? "Yes" : "No") << endl;
    cout << endl;

    q.push("Jai");
    q.push("Loves");
    q.push("His");
    q.push("Dad");

    int n = q.size();
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    cout << "Size of priority_queue q-> " << q.size() << endl;
    cout << "empty or not -> " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
