


bool isPermutation(queue<int>input, queue<int>output) {
    stack<int>inter;
    while (!input.empty()) {

        if (!inter.empty() && inter.top() == output.front()) {
            while (!inter.empty() && !output.empty() && inter.top() == output.front()) {
                inter.pop();
                output.pop();
            }
        }
        inter.push(input.front());
        input.pop();
    }

    while (!inter.empty() && !output.empty() && inter.top() == output.front()) {
        inter.pop();
        output.pop();
    }
    if (inter.empty() && output.empty())return true;
    return false;
}

int main() {
    fast_io;
    file();
    int no;
    cin >> no;
    queue<int>input;
    queue<int>output;
    for (int i = 0; i < no; i++) {
        int ele;
        cin >> ele;
        input.push(ele);
    }

    for (int i = 0; i < no; i++) {
        int ele;
        cin >> ele;
        output.push(ele);
    }
    cout << isPermutation(input, output);
}
