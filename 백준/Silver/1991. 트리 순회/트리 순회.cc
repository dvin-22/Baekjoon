#include <iostream>
using namespace std;

struct node {
  node *left;
  node *right;
  char cha;
  node(char c, node *l, node *r) {
    cha = c;
    left = l;
    right = r;
  }
};

node* find(node *p, char c) {
  if (p == NULL) return NULL;
  if (p->cha == c)
    return p;
  node *found = find(p->left, c);
  if (found == NULL) {
    found = find(p->right, c);
  }
  return found;
}

void Pr(node *p) {
  if (p->cha != '.' && p != NULL){
    printf("%c", p->cha);
    Pr(p->left);
    Pr(p->right);
  }
}
void In(node *p) {
  if (p->cha == '.' || p == NULL)
    return;
  In(p->left);
  printf("%c", p->cha);
  In(p->right);
}
void Po(node *p) {
  if (p->cha == '.' || p == NULL)
    return;
  Po(p->left);
  Po(p->right);
  printf("%c", p->cha);
}

int main() {
  int N;
  scanf("%d", &N);
  node *root = new node('A', NULL, NULL);

  for (int i = 0; i < N; i++) {
    char n1, n2, n3;
    scanf(" %c %c %c", &n1, &n2, &n3);
    node* n=find(root, n1);
    n->left = new node(n2, NULL, NULL);
    n->right = new node(n3, NULL, NULL);
  }

  Pr(root);
  printf("\n");
  In(root);
  printf("\n");
  Po(root);

  return 0;
}