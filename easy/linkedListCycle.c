/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#pragma GCC optmize("O3", "unroll-loops")
bool hasCycle(struct ListNode *head) {
    if (!head) return false;
    struct ListNode *ff = head, *ss = head;
    do {
        if (!ff->next || !ff->next->next)
            return false;
        ff = ff->next->next;
        ss = ss->next;

        if (ff==ss)
            return true;
    } while (1);
    return false;
}
