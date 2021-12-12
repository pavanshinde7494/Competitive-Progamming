int arr[10001];
int freeE = 0;
int nextE[10001];
int top[10001];

void push(int sn, int item) {
    if (freeE == -1) {
        cout << "Stack is Full";
        return ;
    }
    int i = freeE;
    freeE = nextE[i];

    nextE[i] = top[sn];
    top[sn] = i;

    arr[i] = item;

}

int pop(int sn) {
    if (top[sn] == -1) {
        cout << "Stack is empty";
        return -1;
    }
    int i = top[sn];

    int res = arr[i];

    top[sn] = nextE[i];
    nextE[i] = freeE;
    freeE = i;

    return res;
}



int main() {
    fast_io;
    file();

    for (int i = 0; i < 10001; i++)top[i] = -1;

    for (int i = 0; i < 10000; i++)nextE[i] = i + 1;

    nextE[10000] = -1;

    push(1, 1);
    push(2, 11);
    push(2, 22);
    push(1, 2);
    push(2, 33);
    push(1, 3);
    push(1, 4);
    push(2, 44);

    cout << pop(1) << "\n";
    cout << pop(1) << "\n";
    cout << pop(1) << "\n";
    cout << pop(1) << "\n";
    cout << pop(2) << "\n";
    cout << pop(2) << "\n";
    cout << pop(2) << "\n";
    cout << pop(2) << "\n";

}
