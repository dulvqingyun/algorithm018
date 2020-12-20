    string reverseStr(string s, int k) {
       int len = s.length();
       for(int i =0; i<len;i+=2*k){
           int left = i;
           int right = min(i+k-1,len-1);
           while(left < right)
            swap(s[left++], s[right--]);
       } 
       return s;