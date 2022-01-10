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

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int a[], int l, int r){
    int i, j, pivox; 
    int idx = l + rand() % (r - l + 1);        // (1) ���ѡ��һ����׼ 
    pivox = a[idx];                            // (2) pivox �����׼ֵ 
    Swap(&a[l], &a[idx]);                      // (3) ����׼������ߵ�ֵ���� 
    i = j = l + 1;                             // (4) i �� j ������ͬ��ָ�룬���� l+1 ��ʼ  
                                               // j-1 �Ժ�������Ǵ��ڵ��� ��׼ֵ �� 
    while( i <= r ) {                          // (5) ��ʼ���������������䣬i һ���� j �ߵĿ죬�� i �������ұߵ�λ��ʱ������������ 
        if(a[i] < pivox) {                     // (6) ����Ȼ�׼ֵС�ģ����� i �� j���������� j 
            Swap(&a[i], &a[j]);                
            ++j;                               
        }
        ++i;                                   // (7) ÿ�α��� i ����Ҫ���� 
    }
    Swap(&a[l], &a[j-1]);                      // (8) �� j ��Ԫ���Ժ��ǲ��Ȼ�׼ֵС��Ԫ�� 
    return j-1;
}


//�ݹ���л���
void QuickSort(int a[], int l, int r){
    if(l < r){
        int mid = Partition(a, l, r);
        QuickSort(a, l, mid-1);
        QuickSort(a, mid+1, r);
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        QuickSort(a, 0, n-1);
        Output(n, a);
    }
    return 0;
} 
