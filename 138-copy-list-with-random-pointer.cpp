/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* createRandomListNode(RandomListNode* root){
        if(root==NULL){
            return NULL;
        }
        RandomListNode* ans = new RandomListNode(root->label);
        ans->next = createRandomListNode(root->next);
        return ans;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL){
            return NULL;
        }
        
        RandomListNode* ans = createRandomListNode(head);
        vector<RandomListNode*>originList;
        vector<RandomListNode*>ansList;
        RandomListNode* originNode = head;
        RandomListNode* ansNode = ans;
        while(originNode!=NULL){
            originList.push_back(originNode);
            originNode = originNode->next;
        }
        while(ansNode!=NULL){
            ansList.push_back(ansNode);
            ansNode = ansNode->next;
        }
        for(int i=0; i<originList.size(); i++){
            originNode = originList[i];
            ansNode = ansList[i];
            RandomListNode* random = originNode->random;
            if(random==NULL){
                continue;
            }
            int pos = find(originList.begin(), originList.end(), random) - originList.begin();
            ansNode->random = ansList[pos];
        }
        return ans;
    }
};