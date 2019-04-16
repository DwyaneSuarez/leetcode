class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string name;
        string ans = "/";
        int len = path.size();
        for (int i = 0; i < len; i++) {
            if (path[i] == '/') {
                if (!name.empty()) {
                    if (name == "..") {
                        if (!s.empty())
                            s.pop();
                    } else if (name != ".")
                        s.push(name);
                }
                name = "";
            } else {
                name += path[i];
            }
        }
        if (name == "..") {
            if (!s.empty())
                s.pop();
        } else if (!name.empty() && name != ".")
            s.push(name);
        vector<string> names;
        while (!s.empty()) {
            string t = s.top();
            names.push_back(t);
            s.pop();
        }
        reverse(names.begin(), names.end());
        len = names.size();
        for (int i = 0; i < len; i++) {
            if (i)
                ans += "/";
            ans += names[i];
        }
        return ans;
    }
};
