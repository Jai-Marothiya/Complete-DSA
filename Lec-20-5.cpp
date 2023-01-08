// STl container : Queue. follow FIFO mechanism (i.e. first in first out)
#include <iostream>
#include <queue>

using namespace std;
void printQueue(queue<string> gq)
{
    queue<string> g = gq;
    while (!g.empty())
    {
        cout << g.front() << " ";
        g.pop();
    }
    cout << '\n';
}

int main()
{
    queue<string> q;

    q.push("Jai");
    q.push("Loves");
    q.push("His");
    q.push("Dad");

    printQueue(q);

    cout << "First element before pop-> " << q.front() << endl;
    q.pop();
    cout << "First element after pop -> " << q.front() << endl;

    cout << "Size of Queue -> " << q.size() << endl;
    cout << "empty or not -> " << (q.empty() ? "Yes" : "No") << endl;
    return 0;
}
