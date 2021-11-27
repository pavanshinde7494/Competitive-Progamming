// VVVIMP veriation of nearest greater to right
// Problem Link ->https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/


void solve(int arr[], int no) {
    stack<int>stk;
    vector<pair<int, int>>index;

    for (int i = 0; i < no; i++) {
        index.push_back({arr[i], i});
    }

    sort(index.begin(), index.end());


    int track[no];
    memset(track, -1, sizeof(track));

    for (int i = no - 1; i >= 0; i--) {
        while (!stk.empty()) {
            if (index[i].second > index[stk.top()].second)
                stk.pop();
            else {
                track[index[i].second] = index[stk.top()].second;
                break;
            }
        }

        stk.push(i);
    }
    for (int i = 0; i < no; i++) {
        if (track[i] != -1)
            cout << arr[track[i]] << " ";
        else cout << -1 << " ";
    }
}
