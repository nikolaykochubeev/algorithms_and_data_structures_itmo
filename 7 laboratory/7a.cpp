#include <fstream>
#include <vector>
using namespace std;


struct node
{
    int key;
    int height;
    int children[2];
    node(int key, int left, int right) : key(key), height(0)
    {
        children[0] = left;
        children[1] = right;
    }
};

struct avl_Tree
{
    vector<node *> tree;

    int is_balance(int v)
    {
        return (tree[v]->children[1] != -1 ? tree[tree[v]->children[1]]->height : 0) -
               (tree[v]->children[0] != -1 ? tree[tree[v]->children[0]]->height : 0);
    }
    int height_right(node *v)
    {
        return v->children[1] == -1 ? 0 : tree[v->children[1]] -> height;
    }

    int height_left(node *v)
    {
        return v->children[0] == -1 ? 0 : tree[v->children[0]] -> height;
    }

    void count_height()
    {
        if (tree.empty())
            return ;
        dfs(tree[0]);
    }

    void dfs(node * v)
    {
        for (int child : v->children)
        {
            if (child != -1)
                dfs(tree[child]);
        }
        v->height = max(height_left(v), height_right(v)) + 1;
    }
};

int main()
{
    ifstream in("balance.in");
    ofstream out("balance.out");
    size_t n;
    in >> n;
    auto avl = new avl_Tree();
    for (int i = 0; i < n; i++)
    {
        int key;
        int left, right;
        in >> key >> left >> right;
        avl->tree.push_back(new node(key, left - 1, right - 1));
    }

    avl->count_height();
    for (int i = 0; i < avl->tree.size(); i++)
    {
        out << avl->is_balance(i) << endl;
    }
}