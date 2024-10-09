class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        for (int i = 0; i < k; i++) {
            totalSum += cardPoints[i];
        }     
        int maxScore = totalSum;
        for (int i = 0; i < k; i++) {
            totalSum = totalSum - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            maxScore = max(maxScore, totalSum);
        }        
        return maxScore;
    }
};
