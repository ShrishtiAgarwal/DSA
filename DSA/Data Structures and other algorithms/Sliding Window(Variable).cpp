/*
Question: https://leetcode.com/problems/minimum-window-substring/

*/


Solution:

class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(s=="" || t=="" ||s.length()<t.length())
            return "";
        unordered_map<char,int> tab;
        for(int i=0;i<t.length();i++)
        {
            tab[t[i]]++;
        }
        int left=0,len=INT_MAX,count=tab.size();
        string ans="";
        for(int right=0;right<s.length();right++)
        {
            if(tab.find(s[right])!=tab.end())
            {     tab[s[right]]--;
                   if(tab[s[right]]==0) count--;
            }
            while(count==0)
            {
                if(len>right-left)
                {  len=right-left+1;
                    ans=s.substr(left,right-left+1);
                }
                char st=s[left];
                if(tab.count(st)==1)
                {
                    tab[st]++;
                    if(tab[st]>0)
                        count++;
                }
                left++;
            }
        }
    
    return ans;
}
    
};