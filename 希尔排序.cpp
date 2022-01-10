#include <stdio.h>
#include <malloc.h>
 
#define maxn 1000001

int a[maxn];

void Input(int n, int *a) {
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

void Output(int n, int *a) {
    for(int i = 0; i < n; ++i) {
        if(i)
            printf(" ");
        printf("%d", a[i]);
    }
    puts("");
}

void ShellSort(int n, int a[]){
    int i, j, tmp, gap;
    for(gap = n / 2; gap > 0; gap /= 2) {      // (1)   ÿ��gap������Ϊһ�飬gap = n/2, n/4, n/8, ..., 1
        for(i = gap; i < n; ++i) {             // (2)   �ӵ� gap ������ʼ 
            tmp = a[i];
            for(j = i; j >= gap; j -= gap) {   // (3)   ��ǰһ����� gap �����Ƚ� 
                if(tmp < a[j - gap]) {         // (4)   ���С�����������Ʋ�������һ��������Ųһ��λ�� 
                    a[j] = a[j - gap];
                }else {
                    break;                     // (5)   ��������ѭ�� 
                }
            }
            a[j] = tmp;                        // (6)   �� j  ��λ�þ����������Ҫ�����λ�� 
        }
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        ShellSort(n, a);
        Output(n, a);
    }
    return 0;
} 
