// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";

        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0 ))
            ans+= '-';

        long long a = abs(numerator);
        long long b = abs(denominator);

        long long num = abs(a/b);

        ans+=to_string(num);

        long long rem = abs(a%b);

        if(rem==0){
            return ans;
        }

        ans.push_back('.');

        // Now We will calculate decimal part
        // we will store mapping of remainder with its appearing index 
        // ex : 1/10 => rem = 1 its index will be 0

        string dec = "";
        unordered_map<int, int> m;

        while(rem){
            if(m.find(rem)!=m.end()){
            // iF We come across any remainder which is present in mapping 
            // it means the recurring part start from that remainder and we will get its index 
            // and process the result
                int index  = m[rem];
                string recurring = dec.substr(index);
                dec.erase(index);
                dec += '(' + recurring + ')';
                break;
            }else{
                // If Remainder dont exist in map we will continue dividing and storing next remainder till it becomes zero
                m[rem]=dec.size();
                dec+=to_string(rem*10/b);
                rem=(rem*10)%b;
            }
        }

        ans+=dec;

        return ans;
    }
};