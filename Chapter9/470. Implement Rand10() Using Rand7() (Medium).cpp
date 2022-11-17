class Solution {
public:
    int rand10() {
        int a, b, c;
        while (true) {
            a = rand7();
            b = rand7();
            c = (a - 1) * 7 + b;
            if (c <= 40) return 1 + (c - 1) % 10;

            a = c - 40; // 1 - 9
            b = rand7();
            c = (a - 1) * 7 + b; // 1 - 63
            if (c <= 60) return 1 + (c - 1) % 10;

            a = c - 60; // 1 - 3
            b = rand7();
            c = (a - 1) * 7 + b; // 1 - 21
            if (c <= 20) return 1 + (c - 1) % 10;
        }
        return -1;
    }
};
