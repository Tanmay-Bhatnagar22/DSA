class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, prevIdx = -1;
        int minDist = INT_MAX;
        int idx = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr->next != nullptr) {
            bool isMax = curr->val > prev->val && curr->val > curr->next->val;
            bool isMin = curr->val < prev->val && curr->val < curr->next->val;
            
            if (isMax || isMin) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - prevIdx);
                }
                prevIdx = idx;
            }
            
            prev = curr;
            curr = curr->next;
            idx++;
        }
        
        if (firstIdx == -1 || firstIdx == prevIdx) {
            return {-1, -1};
        }
        
        int maxDist = prevIdx - firstIdx;
        return {minDist, maxDist};
    }
};