bool isPalindrome(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    // ListNode* fast = head, slow = head; // ๐ ์๋จ
    // ListNode *fast = head, *slow = head; // ๐ ํ๋ ค๋ฉด ์ด๋ ๊ฒ ํด์ผํจ

    // ํ์นธ ์ ๊น์ง ์ด๋
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // ๋จ์ ์ฐ๊ฒฐ๋ฆฌ์คํธ ๋ค์ง๊ธฐ
    ListNode *prev = 0, *next = 0, *curr = slow->next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    slow = prev;

    // ๋น๊ต
    while (slow)
    {
        if (slow->val != head->val)
            return false;
        slow = slow->next;
        head = head->next;
    }

    return true;
}