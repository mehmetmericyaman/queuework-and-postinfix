#include <iostream>
#include <queue>

using namespace std;

void add(queue<int> &q, int element) {
    q.push(element);
    cout << element << " added." << endl;
}

void remove(queue<int> &q) {
    if (!q.empty()) {
        cout << q.front() << " removed." << endl;
        q.pop();
    } else {
        cout << "Queue is empty, no element to remove." << endl;
    }
}

bool search(queue<int> q, int element) {
    while (!q.empty()) {
        if (q.front() == element)
            return true;
        q.pop();
    }
    return false;
}

int main() {
    queue<int> q;

    add(q, 10);
    add(q, 20);
    add(q, 30);
    add(q, 40);
    add(q, 50);

    cout << "Search Result: " << (search(q, 30) ? "Found" : "Not Found") << endl;
    cout << "Search Result: " << (search(q, 60) ? "Found" : "Not Found") << endl;

    remove(q);
    remove(q);
    remove(q);
    remove(q);
    remove(q);
    remove(q);

    return 0;
}
