class Solution {
public:
    int power(int base, int exp, int m) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > m) return 2; // early exit if exceeds M
        }
        if (result == m) return 1;
        return 0;
    }

    int NthRoot(int N, int M) {
        int low = 1, high = M;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int powCheck = power(mid, N, M);

            if (powCheck == 1) return mid;        // mid^N == M
            else if (powCheck == 0) low = mid + 1; // mid^N < M
            else high = mid - 1;                  // mid^N > M
        }
        return -1;
    }
};