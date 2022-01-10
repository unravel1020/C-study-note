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
    int i, j; 
    int idx = l + rand() % (r - l + 1);        // (1) ���ѡ��һ����׼ 
    Swap(&a[l], &a[idx]);                      // (2) ����׼������ߵ�ֵ���� 
    i = l, j = r;                              // (3) ��ʼ���� [l, r]
    int x = a[i];                              // (4) ����� x ��һ��ʼ��������Ǹ���׼ֵ 
    while(i < j){
        while(i < j && a[j] > x)               // (5) ���������ң���һ������  a[j] <= x��׼ֵ �ģ��˳�ѭ�� 
            j--;
        if(i < j) 
             Swap(&a[i], &a[j]), ++i;          // (6) ��� a[j] <= x��׼ֵ ����  a[j] ����� x ��������������  a[j] �ڻ�׼ֵ���
                                               // �Ҵ�ʱ��׼ֵ�� a[i]�������꣬��׼ֵ���ԭ�ȵ� a[j]���� i ��Ҫ����һ�Σ� 
                                            
        while(i < j && a[i] < x)               // (7) ���������ң���һ������  a[i] >= x��׼ֵ �ģ��˳�ѭ�� 
            i++;
        if(i < j)
            Swap(&a[i], &a[j]), --j;           // (8) ��� a[i] >= x��׼ֵ���� a[i] ����� x ��������������  a[i] �ڻ�׼ֵ�ұ�
                                               // �����꣬��׼ֵ�ֱ��Ϊ a[i]������������ 
    }
    a[i] = x;
    return i;
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
