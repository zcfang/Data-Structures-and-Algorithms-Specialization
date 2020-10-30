#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
        this->parent = nullptr;
    }

    Node(int value) {
        this->key = value;
        this->parent = nullptr;
    }

    Node(int value, Node *the_parent) {
        this->key = value;
        this->parent = the_parent;
    }

    void set_parent(Node *the_parent) {
        parent = the_parent;
        parent->children.push_back(this);
    }
};


int main(int argc, char const *argv[]) {
    std::queue<Node*> levels;
    std::vector<Node*> nodes;
    int output = 0;
    int n;
    int root;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Node *node = new Node(i);
        nodes.push_back(node);
    }
    for (int i = 0; i < n; i++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[i]->set_parent(nodes[parent_index]);
        else
            root = i;
    }
    levels.push(nodes[root]);
    levels.push(nullptr);

    while (!levels.empty()) {
        while (levels.front()) {
            Node *front = levels.front();
            levels.pop();
            for (Node *child : front->children) {
                levels.push(child);
            }
        }
        levels.pop();
        if (!levels.empty()) {
            levels.push(nullptr);
        }
        output++;
    }
    std::cout << output << "\n";

    return 0;
}
