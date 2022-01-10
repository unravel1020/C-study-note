/******************** ��ϣ�� ���Ŷ�ַ�� ********************/
#define maxn (1<<17)
#define mask (maxn-1)
#define DataType int
#define Boolean int
#define NULLKEY (1<<30)    /* �ղ۱�ǲ�����-1���ᵼ������ֵҲΪ-1�����*/

typedef struct {
    DataType data[maxn];
}HashTable;

void HashInit(HashTable *ht) {
    int i;
    for(i = 0; i < maxn; ++i) {
        ht->data[i] = NULLKEY;
    }
}

int HashGetAddr(DataType key) {
    return key & mask;        // ����������
}

Boolean HashSearchKey(HashTable *ht, DataType key, int *addr) {
    int startaddr = HashGetAddr(key);
    *addr = startaddr;
    while(ht->data[*addr] != key) {
        *addr = HashGetAddr(*addr + 1);
        if(ht->data[*addr] == NULLKEY) {
            return 0;                    // �����˿ղۣ�˵��û�ҵ������� 0
        }
        if(*addr == startaddr) {
            return 0;                    // ����һȦ��û�ҵ���ѭ����
        }
    }
    return 1;
}

int HashInsert(HashTable *ht, DataType key) {
    int addr = HashGetAddr(key);
    int retaddr;
    if ( HashSearchKey(ht, key, &retaddr ) ) {
        return retaddr;
    } 
    while(ht->data[addr] != NULLKEY)
        addr = HashGetAddr(addr + 1);
    ht->data[addr] = key;
    return addr;
}

int HashRemove(HashTable *ht, DataType key) {
    int addr;
    if ( !HashSearchKey(ht, key, &addr ) ) {
        return NULLKEY;
    } 
    ht->data[addr] = NULLKEY;
    return addr;
}

/******************** ��ϣ�� ���Ŷ�ַ�� ********************/
