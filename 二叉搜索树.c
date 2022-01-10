#include <stdio.h>

#define bool int

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
// BST �ĵݹ���� 
bool find(struct TreeNode* now, int val) {                      // (1) ```find```����������ڲ���```now```����������Ƿ����```val```������;
    if(now == NULL) {
        return 0;                                               // (2) �����ǲ����ܴ���```val```������ģ��򷵻�```false```;
    }
    if(now->val == val) {
        return 1;                                               // (3) һ��������```val```��ֱ�ӷ���```true```��
    }
    if(val < now->val) {
        return find(now->left, val);                            // (4) �������������ʣ�������ֱȵ�ǰ���С���ݹ�������������
    }else {
        return find(now->right, val);                           // (5) �������������ʣ�������ֱȵ�ǰ���󣬵ݹ�������������
    }
}
