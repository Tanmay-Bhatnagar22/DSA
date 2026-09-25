class Solution {
public:
    string s;
    int pos;

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> res = parseExpr();
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (pos < (int)s.size() && s[pos] == ',') {
            pos++; // skip ','
            set<string> t = parseTerm();
            result.insert(t.begin(), t.end());
        }
        return result;
    }

    // term = factor+  -> cartesian-product concatenation of factors
    set<string> parseTerm() {
        vector<set<string>> factors;
        while (pos < (int)s.size() && s[pos] != ',' && s[pos] != '}') {
            factors.push_back(parseFactor());
        }

        set<string> combined = {""};
        for (auto& f : factors) {
            set<string> next;
            for (auto& prefix : combined)
                for (auto& w : f)
                    next.insert(prefix + w);
            combined = move(next);
        }
        return combined;
    }

    // factor = '{' expr '}' | letter
    set<string> parseFactor() {
        if (s[pos] == '{') {
            pos++; // skip '{'
            set<string> res = parseExpr();
            pos++; // skip '}'
            return res;
        } else {
            string w(1, s[pos]);
            pos++;
            return {w};
        }
    }
};