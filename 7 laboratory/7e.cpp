#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

enum side {right=0, left=1};

struct node
{
    int key;
    int height;
    node* children[2];

    node(int key, node * left, node * right) : key(key), height(1)
    {
        children[0] = left;
        children[1] = right;
    }
};

struct avl_tree
{
    node * root = nullptr;

    int count_balance(node * v)
    {
        if (v == nullptr)
            return 0;
        return (v->children[1] != nullptr ? v->children[1]->height : 0) -
               (v->children[0] != nullptr ? v->children[0]->height : 0);
    }

    void fix_height(node * v)
    {
        v->height = max(height_left(v), height_right(v)) + 1;
    }

    int height_right(node * v)
    {
        return v->children[1] == nullptr ? 0 : v->children[1]->height;
    }

    int height_left(node * v)
    {
        return v->children[0] == nullptr ? 0 : v->children[0]->height;
    }

    node * rotate(node * v, int side)
    {
        node * u = v->children[side == side::left ? 1 : 0];
        v->children[side == side::left ? 1 : 0] = u->children[side == side::left ? 0 : 1];
        u->children[side == side::left ? 0 : 1] = v;
        fix_height(v);
        fix_height(u);
        return u;
    }

    node * balance(node * v)
    {
        fix_height(v);
        if (count_balance(v) > 1)
        {

            if (count_balance(v->children[1]) < 0)
                v->children[1] = rotate(v->children[1], side::right);
            return rotate(v, side::left);
        }
        if (count_balance(v) < -1)
        {
            if (count_balance(v->children[0]) > 0)
                v->children[0] = rotate(v->children[0], side::left);
            return rotate(v, side::right);
        }
        return v;
    }

    node * insert(node * root, int key)
    {
        if (root == nullptr)
            return new node(key, nullptr, nullptr);
        root->children[key < root->key ? 0 : 1] = insert(root->children[key < root->key ? 0 : 1], key);
        return balance(root);
    }

    node * find_max(node * root)
    {
        return root->children[1] == nullptr ? root : find_max(root->children[1]);
    }

    node * remove(node * root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (key != root->key)
            root->children[key < root->key ? 0 : 1] = remove(root->children[key < root->key ? 0 : 1], key);
        else
        {
            if (root->children[0] == nullptr && root->children[1] == nullptr)
                return nullptr;
            if (root->children[0] == nullptr)
            {
                root = root->children[1];
                return balance(root);
            }
            node * r = find_max(root->children[0]);
            root->key = r->key;
            root->children[0] = remove(root->children[0],r->key);
        }
        return balance(root);
    }

    node * search(node * root, int key)
    {
        if (root == nullptr || key == root->key)
            return root;
        return search(root->children[key < root->key ? 0 : 1], key);
    }
};

int main()
{
    ifstream in("avlset.in");
    ofstream out("avlset.out");

    size_t n;
    in >> n;
    auto avl = new avl_tree();

    for (int i = 0; i < n; i++)
    {
        string cmd;
        int key;
        in >> cmd >> key;
        if (cmd == "A")
        {
            if (avl->search(avl->root, key) == nullptr)
                avl->root = avl->insert(avl->root, key);
            out << avl->count_balance(avl->root) << endl;
        }
        if (cmd == "D")
        {
            if (avl->search(avl->root, key) != nullptr)
                avl->root = avl->remove(avl->root, key);
            out << avl->count_balance(avl->root) << endl;
        }
        if (cmd == "C")
            out << ((avl->search(avl->root, key) != nullptr) ? "Y" : "N") << endl;
    }
}