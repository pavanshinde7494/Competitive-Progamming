


int LISnlogn(int arr[], int no) {
    int len = 0;

    // tmp array gives best possible element for increasing subseq. of particular length
    int tmp[no] ;
    // Track array used to keep track of LIS
    int track[no];
    // both above arrays keeps indices not elements


    memset(tmp, -1, sizeof(tmp));
    memset(track, -1, sizeof(track));


    tmp[0] = 0;

    for (int i = 1; i < no; i++) {
        // check curr ele is >= min possible ele of increasing subseq of length = len
        if (arr[i] >= arr[tmp[len]]) {
            len++;
            tmp[len] = i;
            track[i] = tmp[len - 1];
        }

        // check curr ele is < min possible ele of increaing subseq of length = 0
        else if (arr[i] < arr[tmp[0]]) {
            tmp[0] = i;
        }

        // if both above cases fails
        // means curr ele should be placed between 0 and len
        // curr ele should be replaced by its ceil
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
