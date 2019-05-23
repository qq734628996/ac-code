#include <cstdio>

const int MAXN  = 1e5+5;
char s[MAXN];
int next[MAXN];

int main()
{
    while (~scanf("%s", s+1)) { //以数组实现环形单链表
        int pre(0), last(0); //pre为上一个字符的下标，last为最后一个字符的下标
        next[0] = 0; //next[0]指向第一个字符的下标，规定最后一个字符next为0
        for (int i = 1; s[i] != '\0'; i++) {
            if (s[i] == '[') pre = 0;
            else if (s[i] == ']') pre = last;
            else { //在前一个字符（下标pre）和后一个字符（下标next[pre]）之间插入下标为i的字符
                if (pre == last) last = i; //如果上一个字符是最后一个字符，更新last
                next[i] = next[pre];
                next[pre] = i;
                pre = i;
            }
        }
        for (int i = next[0]; i; i = next[i]) putchar(s[i]);
        puts("");
    }
}
