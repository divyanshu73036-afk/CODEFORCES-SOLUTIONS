class Solution {
public:
    int longestValidParentheses(string s) {
            stack<int>st;
            st.push(-1);
            int maxlen=0;
           // int cnt=0;
            for(int i=0;i<s.length();i++){
                        if(s[i]=='('){
                                    st.push(i);
                        }
                        
                        else{
                                    st.pop();
                              if(st.empty())st.push(i);
                              else{
                                          int len=i-st.top();
                                          if(len>maxlen){
                                                      maxlen=len;
                                                  //    cnt=1;
                                          }
                                          
                                          //else{
                                          //            if(maxlen==len)
                                           //           cnt++;
                                                      
                                        //  }
                         }
                        }
            }
            return maxlen;
        

    }
};