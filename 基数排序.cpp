
#include <stdio.h>
#include <string.h>

const int MAXN = 100005;          // (1) ���������Ԫ�������� 
const int MAXT = 10;              // (2) ����Ԫ�ص����ֵ����λ�� 
const int BASE = 10;              // (3) ����Ԫ�صĽ��ƣ�����Ϊ ʮ���� 
int PowOfBase[MAXT];              // (4) BASE �� i ���� 
int RadixBucket[BASE][MAXN];      // (5) �� i ��������
int RadixBucketTop[BASE];         // (6) �� i �������۵Ķ��� 


void InitPowOfBase() {
    int i;
    PowOfBase[0] = 1;
    for(i = 1; i < MAXT; ++i) {
        PowOfBase[i] = PowOfBase[i-1] * BASE;
    }
}

void Input(int n, int *a) {
    int i;
    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

void Output(int n, int *a) {
    int i; 
    for(i = 0; i < n; ++i) {
        if(i)
            printf(" ");
        printf("%d", a[i]);
    }
    puts("");
}

int getRadix(int value, int pos) {
    return value / PowOfBase[pos] % BASE; 
}

void RadixSort(int n, int *a) {   
    int i, j, top = 0, pos = 0;
    while (pos < MAXT) {
        memset(RadixBucketTop, 0, sizeof(RadixBucketTop));
        for(i = 0; i < n; ++i) {
            int rdx = getRadix(a[i], pos);
            RadixBucket[ rdx ][ RadixBucketTop[rdx]++ ] = a[i];
        }
        top = 0;
        for(i = 0; i < BASE; ++i) {
            for(j = 0; j < RadixBucketTop[i]; ++j) {
                a[top++] = RadixBucket[i][j];
            }
        }
        ++pos; 
    }
}

int a[MAXN];

int main() {
    int n;
    InitPowOfBase();
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        RadixSort(n, a);
        Output(n, a);
    }
    return 0;
} 
/*
15
3221 1 10 9680 577 9420 7 5622 4793 2030 3138 82 2599 743 4127
*/
