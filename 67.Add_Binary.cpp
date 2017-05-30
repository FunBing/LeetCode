//After I saw the solution
class Solution {
public:
    string addBinary(string a, string b) {
        int posA = a.size() - 1, posB = b.size() - 1;
        int carry = 0;
        int count = 0;
        string result;
        while(posA >= 0 || posB >= 0 || carry == 1)
        {
            count = 0;
            if(posA >= 0)count += a[posA--] - '0';
            if(posB >= 0)count += b[posB--] - '0';
            count += carry;
            result = to_string(count % 2) + result;
            carry = count / 2;
        }

        return result;


    }
};
