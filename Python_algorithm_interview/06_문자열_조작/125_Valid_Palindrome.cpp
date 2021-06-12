class Solution
{
public:
    bool isPalindrome(string s)
    {
        deque<char> dq;
        for (char c : s)
        {
            if (isalnum(c))
                dq.push_back(tolower(c));
        }

        while (dq.size() >= 2)
        {
            if (dq.front() == dq.back())
            {
                dq.pop_front();
                dq.pop_back();
            }
            else
                return false;
        }
        return true;
    }
};

// isalnum, tolower
// deque 사용