#include <iostream>
#include <string>
using namespace std;

class node
{
public:
  int info;
  node *left;
  node *right;

  node(int val)
  {
    info = val;
    left = NULL;
    right = NULL;
  }
};

node *parent(node *curr, node *p, node *par)
{
  if (curr == NULL)
  {
    return NULL;
  }
  if (curr == p)
  {
    return par;
  }
  else
  {
    node *t = NULL;
    t = parent(curr->left, p, curr);

    if (t != NULL)
    {
      return t;
    }
    else
    {
      t = parent(curr->right, p, curr);
      return t;
    }
  }
}

node *print_ancestors(node *root, node *c)
{
  if (root == NULL)
  {
    return NULL;
  }
  node *t = NULL;
  t = parent(root, c, NULL);

  if (t == NULL)
  {
    cout<<"No more ancestors.";
  }
  else
  {
    cout<<t->info;
    print_ancestors(root,t);
  }

}


  int main()
  {
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(9);
    root->left->right = new node(3);
    root->left->left->left = new node(6);
    root->right->right = new node(4);

    // finding uncle
    node *p = root->left->left->left; // p = 6

    node *n = parent(root, p, NULL); // n = parent of p
    if (n != NULL)
      cout << "Parent of p is : " << n->info << endl;

    node *pn = parent(root, n, NULL); // pn = parent of n
    if (pn != NULL)
      cout << "Grandparent of p is : " << pn->info << endl;

    node *uncle = NULL;
    if (pn != NULL)
    {
      if (pn->left == n)
        uncle = pn->right;
      else
        uncle = pn->left;

      if (uncle != NULL)
        cout << "Uncle of p is : " << uncle->info << endl;
      else
        cout << "No uncle" << endl;
    }

    // finding cousin
    if (uncle != NULL)
    {
      if (uncle->right != NULL)
        cout << "Cousin : " << uncle->right->info << endl;
      if (uncle->left != NULL)
        cout << "Cousin : " << uncle->left->info << endl;
    }
    else
    {
      cout << "No uncle → no cousins" << endl;
    }

    // ancestors;

    node *c = root->left->left->left;
    node *an = print_ancestors(root, c);

    return 0;
  }