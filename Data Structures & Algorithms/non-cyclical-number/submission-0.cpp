class Solution {
public:
    int sumOfSquares(int n) {
        int output = 0;
        while (n != 0) {
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquares(n);

        while(slow != fast){
            fast = sumOfSquares(fast);
            fast = sumOfSquares(fast);
            slow = sumOfSquares(slow);
        }

        return fast == 1;
    }
};
