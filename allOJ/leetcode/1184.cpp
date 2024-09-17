class Solution {
public:
    int sum[10010];
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        sum[0] = 0;
        for (int i = 0; i < distance.size(); ++i) {
            sum[i+1] = sum[i] + distance[i];
        }
        int a = abs(sum[destination] - sum[start]);
        int b = sum[distance.size()] - a;
        return min(a, b);
    }
};