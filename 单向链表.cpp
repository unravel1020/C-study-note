#include <stdio.h>
#include <malloc.h>

typedef int DataType;
 
 // ������ 
struct ListNode {
    DataType data;
    ListNode *next;
};

// ��������ͷ��㣬��ӡ���� 
void ListPrint(ListNode *head) {
    ListNode *vtx = head;
    while(vtx) {                      // (1) ��ͷ��㿪ʼ��ѭ���������н�㣻 
        printf("%d -> ", vtx->data);  // (2) �������Ľ�㣬������ ������ ����```->```�����;
        vtx = vtx->next;              // (3) ����ǰ���ָ��ǰ���ĺ�̽�㣻 
    }
    printf("NULL\n");                 // (4) ������һ��```NULL```������һ������������
}

// ����һ�������� 
ListNode *ListCreateNode(DataType data) {
    ListNode *node = (ListNode *) malloc ( sizeof(ListNode) );
    node->data = data;
    node->next = NULL;
    return node;
}


// ��ȡ����� i ����� 
// 1��  head Ϊ����ͷ������ͷ����������� 
// 2��  i >= 0
ListNode *ListGetNode(ListNode *head, int i) {
    ListNode *temp = head;       // (1) temp ���������ͷ��ʼ���α�ָ�� 
    int j = 0;                   // (2) j ����ǰ���ʵ��˵ڼ������ 
    while(temp && j < i) {       // (3) ����α�ָ��ǿգ����� j < i 
        temp = temp->next;       // (4) �α�ָ��ָ�����ĺ�̽�� 
        ++j;                     // (5) j = j + 1 
    }
    if(!temp || j > i) {
        return NULL;             // (6) �ܵ��������˵���������� i ������������ 
    }
    return temp;                 // (7) ��󣬷����ҵ��ĵ� i ����� 
}

// ����������ֵΪ v �ĵ�һ����� 
// 1��  head Ϊ����ͷ������ͷ����������� 
ListNode *ListFindNodeByValue(ListNode *head, DataType v) {
    ListNode *temp = head;       // (1) temp ���������ͷ��ʼ���α�ָ��
    while(temp) {                // (2) ����α�ָ��ǿգ�����ѭ�� 
        if(temp->data == v) {
            return temp;         // (3) һ������ֵ��ȣ��������ظý�� 
        } 
        temp = temp->next;       // (4) �α�ָ��ָ�����ĺ�̽�� 
    }
    return NULL;                 // (5) �Ҳ��������� NULL 
}



// �ڵ� i �����������һ�����ݣ�����ֵΪ v 
// ����˵����  
// 1��  Head Ϊ����ͷ������ͷ����������� 
// 2��  i >= 0
ListNode *ListInsertNode(ListNode *head, int i, DataType v) {
    ListNode *pre, *aft, *vtx;                     // (1) ������Ϻ�  pre -> vtx -> aft 
    int j = 0;                                     // (2) ����һ������������ j == i ʱ�������ҵ�Ҫ�����λ�� 
    pre = head;                                    // (3) ������ͷ��ʽ 
    while(pre && j < i) {                          // (4) �����û�е�����β������û���ҵ�����λ�������ѭ�� 
        pre = pre->next;                           // (5) �α�ָ��ָ�����ĺ�̽�� 
        ++j;                                       // (6) �������� 1 
    }
    if(!pre) { 
        return NULL;                               // (7) Ԫ�ظ������㣬�޷��ҵ�����λ�ã����� NULL 
    }
    vtx = ListCreateNode(v);                       // (8) ����һ��ֵΪ v �ĹĹ������ 
    aft = pre->next;                               // (9) - (11) Ϊ�˴���  pre -> vtx -> aft 
    vtx->next = aft;                               // (10)
    pre->next = vtx;                               // (11)
    return vtx;                                    // (12) ���ز�����Ǹ���� 
}

// Ҫ������� 
// ���� Index �����ɾ�������ҽ�ֵ�洢�� deleteData �� 
// ����˵���� 
// 1��  Head Ϊ����ͷ������ͷ����������� 
// 2��  i >= 0 
ListNode *ListDeleteNode(ListNode *head, int i) {
    ListNode *pre, *del, *aft;
    int j = 0;
    if(head == NULL) {
        return NULL;              // (1) �������޷�ִ��ɾ����ֱ�ӷ��� 
    }
    if(i == 0) {                  // (2) ��Ҫɾ������� 0 ����� 
        del = head;               // (3) ����� 0 �����       
        head = head->next;        // (4) ���µ�����ͷ����Ϊ��ǰͷ���ĺ�̽�� 
        free(del);                // (5) ����ϵͳ�⺯�� free �ͷ��ڴ� 
        return head;              // (6) �����µ�����ͷ��� 
    }
    
    pre = head;                   // (7) ִ������������� 
    while(pre && j < i - 1) {     // (8) �ҵ���Ҫ��ɾ������ǰ����� 
        pre = pre->next;
        ++ j;
    }
    if(!pre || !pre->next) {      // (9) ���ǰ�����Ϊ�գ�������Ҫ��ɾ���Ľ��Ϊ�գ���ֱ�ӷ��ص�ǰ����ͷ 
        return head;
    }
    del = pre->next;              // (10) ������Ҫɾ���Ľ�㵽 del 
    aft = del->next;              // (11) ����ɾ�����ĺ�̽�㵽 aft 
    pre->next = aft;              // (12) ����Ҫɾ���Ľ���ǰ�����ָ�����ĺ�̽�� 
    free(del);                    // (13) �ͷ���Ҫɾ�������ڴ�ռ� 
    return head;                  // (14) �����µ�����ͷ��� 
} 

ListNode *ListCreateListByTail(int n, int a[]) {
    ListNode *head, *tail, *vtx;         // (1) head�洢ͷ���ĵ�ַ��tail�洢β���ĵ�ַ��vtx�洢��ǰ���ڲ�����ĵ�ַ�� 
    int idx;                              
    if(n <= 0)
        return NULL;                     // (2) ��Ԫ�ظ���Ϊ 0 ʱ��ֱ�ӷ��ؿ����� 
    idx = 0;
    vtx = ListCreateNode(a[0]);          // (3) ����һ��Ԫ��ֵΪ a[0] �������㣻 
    head = tail = vtx;                   // (4) ������ͷ �� ����β ����Ϊ vtx�� 
    while(++idx < n) {                   // (5) ѭ���������� �� 
        vtx = ListCreateNode(a[idx]);    // (6) �������г��˵�һ��Ԫ�����⣬���δ��������㣻 
        tail->next = vtx;                // (7) ����ǰ����β���ĺ�̽����Ϊ vtx�� 
        tail = vtx;                      // (8) �� vtx ��Ϊ�µ� ����β��㣻 
        
    } 
    return head;                         // (9) ��������ͷ��� 
} 

ListNode *ListCreateListByHead(int n, int *a) {
    ListNode *head = NULL, *vtx;       // (1) head�洢ͷ���ĵ�ַ����ʼΪ�գ� vtx�洢��ǰ���ڲ�����ĵ�ַ�� 
    while(n--) {                       // (2) �ܹ���Ҫ���� n ����㣬����� n ��ѭ���� 
        vtx = ListCreateNode(a[n]);    // (3) ����һ��Ԫ��ֵΪ a[i] �������㣬ע�⣬���� i ��ȡֵΪ $n-1 \to 0$�� 
        vtx->next = head;              // (4) ����ǰ�����Ľ��ָ�� �����ͷ��㣻 
        head = vtx;                    // (5) ������ͷ�����Ϊ vtx��
    } 
    return head;                       // (6) ��������ͷ��㣻 
} 

void ListDestroyList(ListNode **pHead) { // (1) ��������ö���ָ�룬��Ϊɾ������Ҫ������ͷ�ÿգ���ͨ�����޷�Ӱ���ⲿ������ 
    ListNode *head = *pHead;             // (2) ������ͷ�����ã� 
    while(head) {                        // (3) �������ǿգ������ѭ���� 
        head = ListDeleteNode(head, 0);  // (4) ��������ͷ�������ҷ��� ��̽�㣻 
        ListPrint(head);
    }
    *pHead = NULL;                       // (5) ������ͷ�ÿ� 
}

/*                     ����Ϊ��������                     */

void testListGetNode(ListNode *head) {
    int i;
    for(i = 0; i < 7; ++i) {
        ListNode *node = ListGetNode(head, i);
        if(!node)
            printf("index(%d) is out of range.\n", i);
        else 
            printf("node(%d) is %d.\n", i, node->data);
    }    
}

void testListFindNodeByValue(ListNode *head) {
    int i;
    for(i = 1; i <= 6; ++i) {
        ListNode *node = ListFindNodeByValue(head, i);
        if(!node)
            printf("value(%d) is not found!\n", i);
        else 
            printf("value(%d) is found!\n", i);
    }    
}

void testListInsertNode(ListNode *head) {
    ListPrint(head);
    printf("ִ�в��������\n"); 
    ListInsertNode(head, 1, 8);
    ListPrint(head);
}

void testListDeleteNode(ListNode *head) {
    ListPrint(head);
    printf("ִ�� 2 �Ž��ɾ��������\n"); 
    head = ListDeleteNode(head, 2);
    ListPrint(head);

    printf("ִ�� 0 �Ž��ɾ��������\n"); 
    head = ListDeleteNode(head, 0);
    ListPrint(head);
}

void testListDestroyList(ListNode **head) {
    ListPrint(*head);
    ListDestroyList(head); 
    ListPrint(*head);
}

int main() {    
    int a[5] = {1, 3, 8, 2, 6};
    ListNode *head = ListCreateListByHead(5, a);
    testListDestroyList(&head); 
    
        int n = 1032, m = 045;
        printf("%d", m+++n++);
    
    return 0;
}







