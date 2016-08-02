class Solution {
public:
    bool isPalindrome(int x) {
         if( x < 0 )
             return false;
         if( x < 10)
             return true;
         int digit = 0;
         int tmp = x;
         while( tmp >= 1 )
         {
             tmp/=10;
             ++digit;
         }
         for(int i = 0; i < digit/2; ++i)
         {
             if( ( (int)(x/pow(10,i) )%10) != (int)( x/pow(10,digit-i-1) )%10 )
                 return false;
         }
        return true;
    }
};