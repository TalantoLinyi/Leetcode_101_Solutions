class Solution {
    struct Node {
        long long prod;
        int prime;
        int idx;
        Node(long long _prod, int _prime, int _idx): prod(_prod), prime(_prime), idx(_idx){
        }
    };
    struct Cmp {
        bool operator() (const Node& a, const Node& b) {
            return a.prod > b.prod;
        }
    };
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<Node, vector<Node>, Cmp> pq;
        for (int i = 0; i < primes.size(); ++i) {
            pq.push(Node(1, primes[i], 1));
        }
        vector<long long> ans(n + 1);
        for (int i = 1; i <= n;) {
            Node node = pq.top(); pq.pop();
            long long prod = node.prod;
            int prime = node.prime, idx = node.idx;

            if (prod != ans[i - 1]) {
                ans[i] = prod;
                i++;
            }
            pq.push(Node(ans[idx] * prime, prime, idx + 1));
        }
        return ans[n];
    }
};
