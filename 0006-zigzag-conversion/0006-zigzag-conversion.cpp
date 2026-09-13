class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||s.size()==1)return s;
        string ans="";
        int n=s.size();
        int numcharinsection = 2 * numRows - 2;
        for(int i=0;i<numRows;i++)
        {
          int index =i;
          while(index<n)
          {
            ans+=s[index];
            if(i!=0&&i!=numRows-1)
            {
                int charinbtw=numcharinsection-2*i;
                int secondindx=index+charinbtw;
                if(secondindx<n)ans+=s[secondindx];
            }
            index+=numcharinsection;

          }

        }
        return ans;
    }
};