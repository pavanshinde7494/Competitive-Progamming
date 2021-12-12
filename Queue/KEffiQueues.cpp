
int arr[1001];
int front[1001];
int rear[1001];
int nextE[1001];
int freeE = 0;

void push(int no, int item) {
    if (freeE == -1) {
        cout << "Queue is Full";
        return;
    }
    int i = freeE;
    freeE = nextE[i];

    nextE[i] = -1;

    if (front[no] == -1)
        front[no] = i;

    else
        nextE[rear[no]] = i;


    rear[no] = i;
    arr[i] = item;
}


int pop(int no) {
    if (front[no] == -1) {
        cout << "Queue is empty";
        return -1;
    }
    int i = front[no];
    int res = arr[i];
    front[no] = nextE[i];

    nextE[i] = freeE;
    freeE = i;
    if (front[no] == -1)
        rear[no] = -1;

    return res;
}

int main() {
    fast_io;
    file();

    memset(front, -1, sizeof(front));
    memset(rear, -1, sizeof(rear));
    for (int i = 0; i < 1000; i++)nextE[i] = i + 1;
    nextE[1000] = -1;

    push(1, 1);
    push(2, 11);
    push(1, 2);
    push(2, 22);
    cout << pop(1) << "\n";
    cout << pop(1) << "\n";
    cout << pop(1) << "\n";
    cout << pop(2) << "\n";
    cout << pop(2) << "\n";



}




