#include <stdio.h>
int g[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int delete();
void add(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();

void main()
{
  int n,i,j,s,choice;
  printf("Enter the number of vertices: ");
  scanf("%d",&n);
  printf("Enter: 1 if True\n       0 if Flase \n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%d has a node with %d: ",i,j);
      scanf("%d",&a[i][j]);
    }
  }
  printf("The adjacency matrix is: \n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%d",a[i][j]);
    }
    printf("\n");
  }
  int ans = 1;
  do
  {
    for(i=1;i<=n;i++)
    vis[i]=0;
    printf("\nFollowing operation can be performed:\n1. BFS\n2. DFS\n");
    printf("Enter your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      bfs(s,n);
      break;
      case 2:
      dfs(s,n);
      break;
    }
    printf("\nDo you wish to continue:\n1. Yes\n0. No\nEnter your choice: ");
    scanf("%d",&ans);
  }while(ans == 1);
}

void bfs(int s,int n)
{
  int p,i;
  add(s);
  vis[s] = 1;
  p = delete();
  if(p != 0)
  {
    printf("%d",p);
  }
  while( p != 0)
  {
    for(i = 1;i <= n;i++)
    {
      if((a[p][i] != 0) && (vis[i] == 0))
      {
        add(i);
        vis[i] = 1;
      }
    }
    p = delete();
    if(p != 0)
    {
      printf("%d",p);
    }
  }
  for(i = 1;i <= n;i++)
  {
    if(vis[i] == 0)
    {
      bfs(i,n);
    }
  }
}

void add(int item)
{
  if(rear == 19)
  {
    printf("Queue is Full");
  }
  else
  {
    if(rear == -1)
    {
      g[++rear] = item;
      front++;
    }
    else
    {
      g[++rear] = item;
    }
  }
}

int delete()
{
  int k;
  if((front > rear) || (front == -1))
  {
    return 0;
  }
  else
  {
    k = g[front ++ ];
    return(k);
  }
}

void dfs(int s,int n)
{
  int i,k;
  push(s);
  vis[s] = 1;
  k = pop();
  if(k != 0)
  {
    printf("%d",k);
  }
  while(k != 0)
  {
    for(i = 1;i <= n;i++)
    {
      if((a[k][i] != 0) && (vis[i] == 0))
      {
        push(i);
        vis[i] = 1;
      }
    }
    k = pop();
    if(k != 0)
    {
      printf("%d",k);
    }
  }
  for(i = 1;i <= n;i++)
  {
    if(vis[i] == 0)
    {
      dfs(i,n);
    }
  }
}

void push(int item)
{
  if(top == 19)
  {
    printf("Stack overflow");
  }
  else
  {
    stack[++top] = item;
  }
}

int pop()
{
  int k;
  if(top == -1)
  {
    return(0);
  }
  else
  {
    k = stack[top--];
    return(k);
  }
}
