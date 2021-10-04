#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int ans = 1;
            int clen = 0;
            int adr = 0;
            int cdot = 0;
            int n = s.length();
            for(int i=0;i<n;i++){
                if(s[i] == '.'){
                    cdot++;
                    if(clen>3 || clen < 1){
                        ans = 0;
                        break;
                    }else if(clen == 3 && (adr < 100 || adr >255)){
                        ans = 0;
                        break;
                    }else if(clen == 2 && (adr < 10 || adr >99)){
                        ans = 0;
                        break;
                    }else if(clen == 1 && (adr < 0 || adr > 9)){
                        ans = 0;
                        break;
                    }else{
                        clen = 0;
                        adr = 0;
                    }
                }else{
                    clen++;
                    if(s[i]>='0' && s[i]<='9'){
                        adr=adr*10+(s[i]-'0');
                    }else{
                        ans = 0;
                        break;
                    }
                }
            }
            if(clen>3 || clen < 1){
                        ans = 0;
                    }else if(clen == 3 && (adr < 100 || adr >255)){
                        ans = 0;
                    }else if(clen == 2 && (adr < 10 || adr >99)){
                        ans = 0;
                    }else if(clen == 1 && (adr < 0 || adr > 9)){
                        ans = 0;
                    }else{
                        clen = 0;
                        adr = 0;
                    }
            if(cdot != 3)
                ans = 0;
            return ans;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends