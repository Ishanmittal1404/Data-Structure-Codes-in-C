#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct treenode
{
    struct treenode* left;
    int data;
    struct treenode* right;
};
void preorder(struct treenode*);
void postorder(struct treenode*);
void inorder(struct treenode*);
int countleafnode(struct treenode*);
int countnode(struct treenode*);
int count(struct treenode*);
void create(struct treenode**,int);
int main()
{
    struct treenode *root;
    root = NULL;
    int num, choice, ans = 1;
    while(ans)
    {
        printf("\nFollowing operation can be performed:\n1. To Insert a Node\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Count Number of nodes in Tree\n6. Count Number of leaf nodes in Tree\n7. Count Number of non-leaf nodes in Tree\n8. Count Number of nodes with one child\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&num);
                create(&root,num);
                break;
            case 2:
                printf("The Traversal in Inorder is:\n");
                inorder(root);
                break;
            case 3:
                printf("The Traversal in Preorder is:\n");
                preorder(root);
                break;
            case 4:
                printf("The Traversal in Postorder is:\n");
                postorder(root);
                break;
            case 5:
                printf("Total Number of Nodes are: %d\n",count(root));
                break;
            case 6:
                printf("Total Number of Leaf Nodes are: %d\n",countleafnode(root));
                break;
            case 7:
                printf("Total Number of Non-leaf Nodes are: %d\n",count(root)-countleafnode(root));
                break;
            case 8:
                printf("Total Number of Nodes with One-Child are: %d\n",countleafnode(root)-countnode(root));
        }
        printf("\nDo you wish to continue:\n1. Yes\n0. No\nEnter your choice: ");
        scanf("%d",&ans);
    }
}
void create(struct treenode** root,int n)
{
    struct treenode* temp = (struct treenode*)malloc(sizeof(struct treenode));
    struct treenode* current,*prev;
    int i;
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    if(*root==NULL)
    {
        *root = temp;
    }
    else
    {
    current = *root;
    while(current!=NULL)
    {
        prev = current;
        if(temp->data > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    if(prev->data > temp->data)
    {
        prev->left = temp;
    }
    else
    {
        prev->right = temp;
    }
    }
}

void inorder(struct treenode* root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}

void preorder(struct treenode* root)
{
    if(root==NULL)
        return ;
    printf(" %d ",root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct treenode* root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    inorder(root->right);
    printf(" %d ",root->data);
}

int count(struct treenode *root)
{

    if (root ==NULL)
        return 0;

    else
    {
        return 1+count(root->left)+count(root->right);
    }
}

int countleafnode(struct treenode* root)
{
    if(root==NULL)
    {
        return 0;
    }
        if(((root->left) == NULL)&&((root->left) == NULL))
            return 1;
        else
        {
            return countleafnode(root->left)+countleafnode(root->right);
        }

}

int countnode(struct treenode* root)
{
    if(root==NULL)
    {
        return 0;
    }
        if(((root->left) == NULL)||((root->left) == NULL))
            return 1;
        else
        {
            return countleafnode(root->left)+countleafnode(root->right);
        }

}
