#include <stdio.h>

#define MAXN 1024
#define DataType int

struct SeqList {
    DataType data[MAXN];
    int length;
}; 

DataType SeqListIndex(struct SeqList *sq, int i) {
    return sq->data[i];    
}

DataType SeqListFind(struct SeqList *sq, DataType dt) {
    int i;
    for(i = 0; i < sq->length; ++i) {
        if(sq->data[i] == dt) {
            return i;               // (1)
        }    
    }
    return -1;                      // (2)
}

DataType SeqListGetLength(struct SeqList *sq) {
    return sq->length; 
}

int SeqListInsert(struct SeqList *sq, int k, DataType v) {
    int i;
    if(sq->length == MAXN) {
        return 0;                        // (1) ����0�������ʧ�� 
    } 
    for(i = sq->length; i > k; --i) {
        sq->data[i] = sq->data[i-1];     // (2) �Ӻ���ǰ 
    }
    sq->data[k] = v;                     // (3) �� k ����� v 
    sq->length ++;                       // (4) ���鳤�ȼ�һ 
    return 1;                            // (5) ����1�������ɹ� 
}

int SeqListDelete(struct SeqList *sq, int k) {
    int i;
    if(sq->length == 0) {
        return 0;                        // (1) ����0����ɾ��ʧ�� 
    } 
    for(i = k; i < sq->length - 1; ++i) {
        sq->data[i] = sq->data[i+1];     // (2) ��ǰ����
    } 
    sq->length --;                       // (3) ���鳤�ȼ�һ 
    return 1;                            // (4) ����1����ɾ���ɹ� 
}


int main() {
    int i, j;
    struct SeqList sq;
    sq.length = 0;
     
    for(i = 0; i < 7; ++i) {
        SeqListInsert(&sq, 0, i);
    }
    
    for(j = 0; j < 5; ++j) {
        SeqListDelete(&sq, j);
        for(i = 0; i < 7; ++i) {    
            printf( "%d ", SeqListIndex( &sq, i) );
        }
        puts("");
    }

    
    return 0;
}
