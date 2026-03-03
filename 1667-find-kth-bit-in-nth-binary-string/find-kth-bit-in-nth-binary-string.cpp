class Solution {
public:
    char findKthBit(int n, int k) {
        // Function to recursively find the k-th bit in the nth sequence
        return findKthBitHelper(n, k);
    }
    
    char findKthBitHelper(int n, int k) {
        // Base case: if n is 1, the only bit is '0'
        if (n == 1) return '0';
        
        int length = (1 << n) - 1;  // Length of S_n = 2^n - 1
        int mid = length / 2 + 1;   // Middle index (1-based)
        
        if (k == mid) {
            // Middle bit is always '1'
            return '1';
        } else if (k < mid) {
            // If k is in the left part, it's the same as in S_{n-1}
            return findKthBitHelper(n - 1, k);
        } else {
            // If k is in the right part, it's in the reverse(invert(S_{n-1}))
            // Find the corresponding position in the left part
            int corresponding_pos = length - k + 1;
            // Invert the result of S_{n-1} at the corresponding position
            char result = findKthBitHelper(n - 1, corresponding_pos);
            return result == '0' ? '1' : '0';
        }
    }
};