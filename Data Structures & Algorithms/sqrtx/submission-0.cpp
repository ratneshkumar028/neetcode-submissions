class Solution {
public:
    int mySqrt(int x) {
       long e= x;
        long s=0;
        long ans =0;
        
        while(s<=e){
           long  m =s+(e-s)/2;
           if(m*m==x){
            return(int) m;
           }
           else if(m*m<x){
            ans =m;
            s= m+1;
           }
           else{
            e= m-1;
           }
        }
        return (int)ans;
    }
};