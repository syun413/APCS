#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int parent[100001];
int height[100001];
int n;
int count = 0;
int h(int x)
{
	int max = 0;
    count++;
    int temp = 0;
	for(int i = 1;i <= n;i++)
	{
		if(parent[i] == x && height[i] == -1 && max <= (temp=h(i)))
			max = temp+1;
        else if(parent[i] == x  && max <= height[i])
            max = height[i]+1;
	}
    //sleep(1);
    height[x] = max;
   
	return max;
}
int main(int argv, char **argc)
{
	int sum,k,root;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		parent[i] = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&k); 
		for(int j = 0;j < k;j++)
		{
			int c;
			scanf("%d",&c);
			parent[c] = i;
		}
	}	
	for(int i = 1;i <= n;i++)
	{
		if(parent[i] == 0)
		{
			{
				root = i;
				break;
			}
		}
	}
    
    for(int i = 0; i < 100001; i++)
    {
        height[i] = -1;
    }
    int u = h(root);

	for(int i = 1;i <= n;i++)
    {

		sum += height[i];
    }
	printf("%d\n%d\n%d\n",root,sum,count);			
		

		
	return 0;
}

