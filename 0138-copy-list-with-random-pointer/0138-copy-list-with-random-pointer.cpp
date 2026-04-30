class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> node_map;
        Node* cur = head;
        while(cur) {
         node_map[cur] = new Node(cur->val);
         cur = cur->next;
        }
        cur = head;
        while (cur) {
         Node* copy = node_map[cur];
         copy->next = node_map[cur->next];
         copy->random = node_map[cur->random];
         cur = cur->next;
        }
        return node_map[head];
    }
};