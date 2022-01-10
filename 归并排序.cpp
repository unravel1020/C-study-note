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

void MergeSort(int *nums, int l, int r) {
    int i, mid, p, lp, rp;
    int *tmp = (int *)malloc( (r-l+1) * sizeof(int) );    // (1) ����һ���������飬���ڶ�ԭ������й鲢����  
    if(l >= r) {
        return ;                                          // (2) ֻ��һ��Ԫ�أ�����û��Ԫ�ص����������Ҫ����
    }
    mid = (l + r) >> 1;                                   // (3) �������Ϊ [l, mid] �� [mid+1, r] ������
    MergeSort(nums, l, mid);                              // (4) �ݹ����� [l, mid] ����
    MergeSort(nums, mid+1, r);                            // (5) �ݹ����� [mid+1, r] ����
    p = 0;                                                // (6) ����Ҫ��������黺�浽 tmp �У��� p ��Ϊ�α�
    lp = l, rp = mid+1;                                   // (7) ��ʼ�����������ָ��
    while(lp <= mid || rp <= r) {                         // (8) ������ָ�붼û�е���β�����������
        if(lp > mid) {
            tmp[p++] = nums[rp++];                        // (9) ֻʣ���ұߵ����飬ֱ����
        }else if(rp > r) {
            tmp[p++] = nums[lp++];                        // (10) ֻʣ�����ұߵ����飬ֱ����
        }else {
            if(nums[lp] <= nums[rp]) {                    // (11) ȡС���Ǹ��Ƚ� tmp ����
                tmp[p++] = nums[lp++];
            }else {
                tmp[p++] = nums[rp++];
            }
        }
    }
    for(i = 0; i < r-l+1; ++i) {
        nums[l+i] = tmp[i];                              // (12) �����˽�����õ����ݿ�����ԭ����
    } 
    free(tmp);                                           // (13) �������ͷ���ʱ���ݣ�������ڴ�й©�ˣ�����
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        MergeSort(a, 0, n-1);
        Output(n, a);
    }
    return 0;
} 
