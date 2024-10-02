#include<iostream>
#include<set>
#include<cmath>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.length() <= 1) return s.length();
        set<char> my_set;
        int i = 0, j = 0, Max = 0;
        while(i < s.length())
        {
            char c = s[i];
            while(my_set.find(c) != my_set.end()) //not in my_set
            {
                my_set.erase(s[j]);
                j++;
            }
            my_set.insert(c);
            Max = max(Max, i - j + 1);
            i++;
        }
        return Max;
    }
};

int main()
{
    Solution *sl = new Solution();
    int num = sl->lengthOfLongestSubstring("abcabcbb");
    cout << "Result = " << num << "\n";
    return 0;
}