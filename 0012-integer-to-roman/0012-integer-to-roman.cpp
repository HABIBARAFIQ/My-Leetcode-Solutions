class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mp;

        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";

        string s = "";

        int p = 1000;

        while (num > 0) {

            int digit = num / p;
            int value = digit * p;

            if (mp.contains(value)) {
                s += mp[value];
            }
            else {
                if (digit >= 5) {
                    s += mp[5 * p];

                    for (int i = 0; i < digit - 5; i++)
                        s += mp[p];
                }
                else {
                    for (int i = 0; i < digit; i++)
                        s += mp[p];
                }
            }

            num %= p;
            p /= 10;
        }

        return s;
    }
};