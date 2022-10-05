#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct bst
{
    node *root = nullptr;

    node *find(int value)
    {
        return find_imp1(root, value);
    }

private:
    node *find_imp1(node *current, int value)
    {
        if (!current)
        {
            cout << endl;
            return NULL;
        }

        if (current->data == value)
        {
            cout << value << "을 찾았습니다." << endl;
            return current;
        }

        if (value < current->data)
        {
            cout << current->data << "to move left: ";
            return find_imp1(current->left, value);
        }

        cout << current->data << "to move right: ";
        return find_imp1(current->right, value);
    }

public:
    void insert(int value)
    {
        if (!root)
            root = new node{value, NULL, NULL};

        else
            insert_imp1(root, value);
    }

private:
    void insert_imp1(node *current, int value)
    {
        if (value < current->data)
        {
            if (!current->left)
                current->left = new node{value, NULL, NULL};
            else
                insert_imp1(current->left, value);
        }
        else
        {
            if (!current->right)
                current->right = new node{value, NULL, NULL};
            else
                insert_imp1(current->right, value);
        }
    }

public:
    void inorder()
    {
        inorder_imp1(root);
    }

private:
    void inorder_imp1(node *start)
    {
        if (!start)
            return;
        inorder_imp1(start->left);
        cout << start->data << " ";
        inorder_imp1(start->right);
    }
};

int main()
{
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    cout << "inorder";
    tree.inorder();
    cout << endl;
}