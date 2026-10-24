class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto toDay = [&](const string& s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));
            int total = 0;
            for (int i = 0; i < month - 1; i++) total += days[i];
            return total + day;
        };

        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end = min(toDay(leaveAlice), toDay(leaveBob));

        return max(0, end - start + 1);
    }
};