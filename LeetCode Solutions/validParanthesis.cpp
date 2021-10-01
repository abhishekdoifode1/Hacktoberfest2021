class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open,star;
        int len = s.length();
        
        for(int i=0;s[i]!='\0';++i)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        //Now process leftover opening brackets
        while(!open.empty())
        {
            if(star.empty())
                return false;
            else if(open.top() < star.top())
            {
                open.pop();
                star.pop();
            }
            else    //CASE: open.top() > star.top()
                return false;
        }
        return true;
    }
};