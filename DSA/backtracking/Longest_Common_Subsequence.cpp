    int longestCommonSubsequence(string text1, string text2) 
    {
        text1=" "+text1;
        text2=" "+text2;
        int arr[text1.length()][text2.length()];
        for(int i=0;i<text2.length();i++)
        {
            arr[0][i]=0;
        }
        for(int j=0;j<text1.length();j++)
        {
            arr[j][0]=0;
        }
        for(int i=1;i<text1.length();i++)
        {
            for(int j=1;j<text2.length();j++)
            {
                if(text1[i]==text2[j])
                    arr[i][j]=1+arr[i-1][j-1];
                else
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
        return arr[text1.length()-1][text2.length()-1];
    }