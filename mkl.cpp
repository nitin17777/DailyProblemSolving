#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(NULL) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* mergeLists(Node* l1, Node* l2) {
    Node dummy("0");
    Node* tail = &dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;
    return dummy.next;
}

Node* buildList(int n) {
    if (n <= 0) return NULL;
    string val;
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        cin >> val;
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

int main() {
    int n1, n2;
    cin >> n1;
    Node* list1 = buildList(n1);
    cin >> n2;
    Node* list2 = buildList(n2);
    Node* merged = mergeLists(list1, list2);
    printList(merged);
    return 0;
}