#include <iostream>

using namespace std;

struct Node{
    int parent;
    int sum;
    int under;
};

Node tree[30010];

int getRoot(int a){
    if(tree[a].parent != a){
        int root = getRoot(tree[a].parent);
        tree[a].under += tree[tree[a].parent].under;
        tree[a].parent = root;
    }

    return tree[a].parent;
}

void merge(int a, int b){
    int root_a = getRoot(a);
    int root_b = getRoot(b);
    if(root_a == root_b)
        return;
    tree[root_a].parent = root_b;
    tree[root_a].under += tree[root_b].sum;
    tree[root_b].sum += tree[root_a].sum;
}

int main(){
    for(int i = 0; i < 30010; ++i){
        tree[i].parent = i;
        tree[i].sum = 1;
        tree[i].under = 0;
    }

    int p;
    cin >> p;
    for(int i = 0; i < p; ++i){
        char mc;
        int a, b;
        cin >> mc;
        if(mc == 'M'){
            cin >> a >> b;
            merge(a, b);
        }else{//not M then it's C
            cin >> a;
            getRoot(a);
            cout << tree[a].under << endl;
        }
    }
    return 0;
}
