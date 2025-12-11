#include<bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2)
{

    int m = s2.size();
    int n = s1.size();

    vector<vector<int>>dp(m+1, vector<int>(n+1,0));

    for(int j=0; j<=m;j++){
        dp[j][0]=0;
    }
    
    for(int i=0; i<=n;i++){
        dp[0][i]=0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<"Printing the table"<<endl;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    int len = dp[n][m];
    cout<<"Length of the LCS is = "<<len<<endl;

    string lcs;

    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else{
            j--;
        }

    }

    reverse(lcs.begin(),lcs.end());

    cout<<"lcs is "<<lcs;


}





int main()
{

    string s1="ABBABABA";
    string s2="AABABAAB";

    lcs(s1, s2);

}
