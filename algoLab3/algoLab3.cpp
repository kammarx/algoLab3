#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;


const int N = 25;
int arr[N], k = 0;

struct node {
    int Key;
    node* left;
    node* right;
};


class TREE
{
private:
    node* root;
public:
    TREE() {
        root = NULL;
    }
    node** GetRoot() {
        return &root;
    }
    node* Tree(int, node**);
    void outputF(node**, int);
};

void printSym(node** node) {
    if (*node == NULL)return;
    printSym(&((**node).right));
    cout << ((**node).Key)<<" ";
    printSym(&((**node).left));
}


int main() {
    TREE D;
    srand(time(nullptr));
    for (int i = 0; i < N; i++) {
       arr[i] = 100 * (rand() % 9 + 1) + rand() % 100;
    }
    for ( int i = 0; i <N; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << "\n\n";
    D.Tree(N, D.GetRoot());
    D.outputF(D.GetRoot(), 0);
    cout << endl << endl;
    printSym(D.GetRoot());

    return 0;
}

node* TREE::Tree(int n, node** t) {
    node* cur;
    int x, nl, nr;
    cur = *t;
    if (n == 0)*t = nullptr;
    else {
        nl = n / 2;
        nr = n - nl - 1;
        x=arr[k];
        k++;
        cur = new node;
        cur->Key = x;
        Tree(nl, &(cur->left));
        Tree(nr, &(cur->right));
        *t = cur;
    }
    return nullptr;
}

void TREE::outputF(node** q, int a) {
    if (*q != NULL) {
        outputF(&((**q).right), a+1);
        for (int i = 1; i <= a; i++) {
            cout << "\t";
        }
        cout << (**q).Key << endl;
        outputF(&((*q)->left), a+1);
    }
}
