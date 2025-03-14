#include <vector>
#include <iostream>
#include <set>

typedef struct {
    int id, pi;
    char color;
    std::vector<int> adj;
} node;

std::vector<node> tree;

bool checkCycles(), visit(node n);

void DFS_reset(), DFS_Visit1(int v), DFS_Visit2(int v);

int main() {
    int v1, v2, node_n, edges_n, s, d;

    if (scanf("%d", &v1) == 0 || scanf("%d", &v2) == 0 || scanf("%d", &node_n) == 0 || scanf("%d", &edges_n) == 0)
        return 0;

    for (int i = 1; i <= node_n; i++) {
        node n;
        n.id = i;
        n.color = 'w';
        n.pi = 0;
        tree.push_back(n);
    }

    for(int i = 0; i < edges_n; i++) {
        if (scanf("%d", &s) == EOF || scanf("%d", &d) == EOF)
            return 0;
        tree[d - 1].adj.push_back(s);
    }

    if (checkCycles()) {
        printf("0\n");
        return 0;
    }

    std::set<int> common;

    DFS_reset();

    DFS_Visit1(v1);

    if (tree[v2 - 1].color == 'b')
        tree[v2 - 1].color = 'a';

    DFS_Visit2(v2);

    for (node n : tree)
        if (n.color == 'a')
            common.insert(n.id);

    std::vector<int> remove;
    node n;
    std::set<int>::iterator it;

    for (int el : common) {
        n = tree[el - 1];
        it = common.find(n.pi);
        if (n.pi != 0 && it != common.end())
            remove.push_back(el);
    }

    for (int el : remove)
        common.erase(el);

    if (common.size() == 0) {
        printf("-\n");
    } else {
        for (int p : common)
            printf("%d ", p);
        printf("\n");
    }

    return 0;
}

bool visit(node n) {
    tree[n.id - 1].color = 'g';

    for (int num : n.adj)
        if (tree[num - 1].color == 'w') {
            tree[num - 1].pi = n.id;
            if (visit(tree[num - 1]))
                return true;
        } else if (tree[num - 1].color != 'b')
            return true;

    tree[n.id - 1].color = 'b';

    return false;
}

bool checkCycles() {
    int size = tree.size();

    for (int i = 0; i < size; i++) {
        tree[i].pi = 0;
        tree[i].color = 'w';
    }

    for (node n : tree)
        if (n.color == 'w' && visit(n))
            return true;

    return false;
}

void DFS_Visit1(int i) {
    tree[i - 1].color = 'g';

    for (int w : tree[i - 1].adj)
        if (tree[w - 1].color == 'w') {
            tree[w - 1].pi = i;
            DFS_Visit1(w);
        }

    tree[i - 1].color = 'b';
}

void DFS_Visit2(int i) {
    for (int w : tree[i - 1].adj) {
        if (tree[w - 1].color == 'b' || tree[w - 1].color == 'a') {
            tree[w - 1].color = 'a';
            if (tree[tree[w - 1].pi - 1].color != 'a' && tree[i - 1].color == 'a')
                tree[w - 1].pi = i;
        }
        if (tree[w - 1].color != 'g')
            DFS_Visit2(w);
    }
}

void DFS_reset() {
    int size = tree.size();

    for (int i = 0; i < size; i++) {
        tree[i].color = 'w';
        tree[i].pi = 0;
    }
}