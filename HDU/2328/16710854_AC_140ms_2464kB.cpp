#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

const int MAXN = 26;
const int MAXM = 1007;
const int oo = 1e9+7;

struct node
{
    int times;
    node *next[MAXN];
};

int BuildTrie(node *head, char s[], int x)
{
    int i, k, depth = 0;
    node *P = head;

    for(i=0; s[i]; i++)
    {
        k = s[i] - 'a';
        if(P->next[k] == NULL)
        {
            if(x != 1)
                break;
            P->next[k] = new node();
        }

        P = P->next[k];

        if(P->times + 1 >= x)
        {///如果此节点是本个串访问过或者上个节点访问过
            P->times = x;
            depth++;
        }
        else break;
    }

    return depth;
}
void clearTrie(node *head)
{///销毁树
    node *P = head;

    for(int i=0; i<MAXN; i++)
    {
        if(P->next[i] != NULL)
            clearTrie(P->next[i]);
    }

    free(P);
}

int main()
{
    int i, j, N;

    while(scanf("%d", &N), N)
    {
        node *head = new node();
        char s[MAXM]={0}, ans[MAXM]={0};

        for(i=1; i<N; i++)
        {
            scanf("%s", s);
            for(j=0; s[j] != '\0'; j++)
                BuildTrie(head, s+j, i);
        }
        scanf("%s", s);

        int Max = 0;

        for(j=0; s[j] != '\0'; j++)
        {
            int len = BuildTrie(head, s+j, N);
            char p[MAXM] = {0};

            strncpy(p, s+j, len);

            if(Max < len || (Max==len && strcmp(ans, p) > 0))
                strcpy(ans, p), Max = len;
        }

        if(ans[0] == 0)
            printf("IDENTITY LOST\n");
        else
            printf("%s\n", ans);

        clearTrie(head);
    }

    return 0;
}