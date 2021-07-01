class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

// 벡터에 저장된 char 들을 뒤집는 문제.
// 새로운 벡터를 할당하지 않고 풀어야! (메모리 쓰면 통과 못하나?)

// 투 포인터 기법
// swap