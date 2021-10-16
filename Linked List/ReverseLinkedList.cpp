#include<bits/stdc++.h>

using namespace std;

#define ll                          long long
#define mod                         1000000007
#define f                           first
#define s                           second
#define pb                          push_back
#define mk                          make_pair
#define gcd(a,b)                    __gcd(a,b)
#define lcm(a,b)                    a/gcd(a,b)*b
#define fast_io                     ios_base::sync_with_stdio(false);\
                                    cin.tie(NULL)
#define PI                          3.1415926535897932384626
#define INF                         1e18
#define NINF                        -1e18

bool flg = false;

const int dir4[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

const int dir8[8][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};

/*--------------------------------------------------------code starts here--------------------------------------------------------------*/


void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}


Node* head = NULL;


void reverse(Node* curNode,Node* prevNode){
	if(curNode == NULL){
		return;
	}
	if(curNode->next == NULL)
		head = curNode;
	reverse(curNode->next,curNode);
	curNode->next = prevNode;
}

int main() {
    
    while (1) {
        cout << "1.Add Node\n2.Display List\n3. Reverse\n4.Exit\n";
        cout << "Enter Choice : ";
        int choice , data;
        Node* tmp = NULL ;
		Node* prevNode = NULL;
		Node* nextNode = NULL;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Data : ";
            cin >> data;
            if (head == NULL) {
                head = createNode(data);
            }
            else {
                tmp = head;
                while (tmp->next) {
                    tmp = tmp->next;
                }
                tmp->next = createNode(data);
            }
            break;
        case 2:
            tmp = head;
            cout << "Linked List: ";
            while (tmp) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << "\n";
            break;
        case 3:
			// Iterative
			
			// if(head == NULL || head->next == NULL) break;
			// Node* tmp = head;
			// prevNode = tmp;
			// tmp = tmp->next;
			// prevNode->next = NULL;
			// while(tmp){
			// 	nextNode = tmp->next;
			// 	tmp->next = prevNode;
			// 	prevNode = tmp;
			// 	tmp = nextNode;
			// }
			// head = prevNode;

			// Recurssive
			
			tmp = head;
			reverse(tmp,NULL);
            break;
        }
        if (choice >= 4)break;
    }
    return 0;
}
