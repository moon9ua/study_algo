bool isPalindrome(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    // ListNode* fast = head, slow = head; // 📝 안됨
    // ListNode *fast = head, *slow = head; // 📝 하려면 이렇게 해야함

    // 한칸 전까지 이동
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 남은 연결리스트 뒤집기
    ListNode *prev = 0, *next = 0, *curr = slow->next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    slow = prev;

    // 비교
    while (slow)
    {
        if (slow->val != head->val)
            return false;
        slow = slow->next;
        head = head->next;
    }

    return true;
}