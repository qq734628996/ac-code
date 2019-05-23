#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
const int MAXN = 110010;
//字符串长度<MAXN
char str[MAXN];
char Ma[MAXN * 2];
int Mp[MAXN * 2];
int Manacher(char s[]) {
    int l = 0, len = strlen(s);
    Ma[l++] = '$';
    Ma[l++] = '#';
    for (int i = 0; i<len; i++)  {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0, maxlength = 0;
    for (int i = 0; i<l; i++)  {
        Mp[i] = mx>i ? std::min(Mp[2 * id - i], mx - i) : 1;
        while (Ma[i + Mp[i]] == Ma[i - Mp[i]])Mp[i]++;
        if (i + Mp[i]>mx)   {
            mx = i + Mp[i];    id = i;
        }
        maxlength = std::max(maxlength, Mp[i]);
    }
    return maxlength - 1;
}

int main()
{
    while (~scanf("%s", str)) {
        printf("%d\n", Manacher(str));
    }
    return 0;
}