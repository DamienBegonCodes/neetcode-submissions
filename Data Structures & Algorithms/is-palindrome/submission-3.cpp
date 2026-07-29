class Solution {
public:
    bool isPalindrome(string s) 
    {
        string::reverse_iterator rit = s.rbegin();
        string::iterator it = s.begin();

        while(it != s.end() && rit != s.rend())
        {
            if (!(isalpha(*it) || isdigit(*it)))
            {
                ++it;
                continue;
            }
            if (!(isalpha(*rit) || isdigit(*rit)))
            {
                ++rit;
                continue;
            }
            cout << (char) tolower(*(it)) << " " << (char) tolower(*(rit)) << endl;

            if (tolower(*(it++)) != tolower(*(rit++)))
            {
                return false;
            }
        }
        return true;
    }
};
