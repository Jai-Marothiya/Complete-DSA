// STl container : Stack. follow LIFO mechanism (i.e. last in first out)
#include <iostream>
#include <stack>

using namespace std;

void PrintStack(stack<string> s)
{
    // If stack is empty then return
    if (s.empty())
        return;

    string x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

int main()
{
    stack<string> st;

    st.push("Jai");
    st.push("Loves");
    st.push("His");
    st.push("Dad");

    PrintStack(st);
    cout << endl;

    cout << "Top element -> " << st.top() << endl;
    st.pop();
    cout << "Top element -> " << st.top() << endl;

    cout << "Size of Stack -> " << st.size() << endl;
    cout << "empty or not -> " << (st.empty() ? "Yes" : "No") << endl;
    return 0;
}
