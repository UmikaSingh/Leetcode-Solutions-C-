class Solution {
public:
    string reverseWords(string s) {
        string res="",word="";
        int begin=-1,n=s.length();
        int end=n;
        
        while(++begin < n && s[begin]==' '); //trimming leading spaces
        while(--end>=0 && s[end]==' '); //trimming trailing spaces
        
        s=s.substr(begin,end+1-begin); //new string with spaces(leading and trailing) removed
        int n2=s.length(); //length of new string
        for(int i=n2-1;i>=0;i--){
            
            if(s[i]!=' ') 
                word.push_back(s[i]); //storing word by word
            
            else if(s[i]==' ' && s[i-1]!=' '){  //2nd condition will ignore extra spaces in between words
                 reverse(word.begin(), word.end()); 
                res.append(word);
                res+=" ";
                word=""; //making this temp variable empty for storing new word
                
            }
            
        }
        //last word needs to be added too
         reverse(word.begin(), word.end()); 
        res.append(word);
        
        return res;
    }
};
