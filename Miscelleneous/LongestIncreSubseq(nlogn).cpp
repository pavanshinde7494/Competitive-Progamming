
int LISnlogn(int arr[], int no) {
    int len = 0;
    int tmp[no] , track[no];

    memset(tmp, -1, sizeof(tmp));
    memset(track, -1, sizeof(track));

    tmp[0] = 0;

    for (int i = 1; i < no; i++) {
        if (arr[i] >= arr[tmp[len]]) {
            len++;
            tmp[len] = i;
            track[i] = tmp[len - 1];
        }
        else if (arr[i] < arr[tmp[0]]) {
            tmp[0] = i;
        }
        else {
            int left = 0 , right = len , res = -1;
            while (left <=  right) {
                int mid = (left + right) / 2;
                if (arr[tmp[mid]] >= arr[i]) {
                    res = mid;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            tmp[res] = i;
            track[i] = tmp[res - 1];
        }
    }
    for (int i = 0; i < no; i++)
        cout << tmp[i] << " ";
    cout << "\n";
    for (int i = 0; i < no; i++)
        cout << track[i] << " ";
    cout << "\n";
    return len + 1;
}



int main() {
    fast_io;
    file();
    int no;
    cin >> no;
    int arr[no];
    for (int i = 0; i < no; i++)
        cin >> arr[i];

    cout << LISnlogn(arr, no);
    return 0;
}
