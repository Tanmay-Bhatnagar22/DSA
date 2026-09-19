class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        // Calculate squared distance from circle center to that closest point
        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;
        
        return dx * dx + dy * dy <= (long long)radius * radius;
    }
};