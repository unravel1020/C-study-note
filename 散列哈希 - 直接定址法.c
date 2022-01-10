/******************** ��ϣ�� ƫ�Ʒ� ********************/
#define maxn ((1<<17)-1)
#define DataType int
#define Boolean int
#define NULLKEY (maxn+maxn)    /* �ղ۱�ǲ�����-1���ᵼ������ֵҲΪ-1�����*/
#define Base 100002

typedef struct {
    DataType data[maxn + 1];
}HashTable;

void HashInit(HashTable *ht) {
    int i;
    for(i = 0; i < maxn + 1; ++i) {
        ht->data[i] = NULLKEY;
    }
}

int HashInsert(HashTable *ht, DataType key) {
    int addr = key + Base;
    ht->data[addr] = key;
    return addr;
}

Boolean HashSearchKey(HashTable *ht, DataType key, int *addr) {
    *addr = key + Base;
    return ht->data[*addr] == key;
}

/******************** ��ϣ�� ���˷� ********************/
