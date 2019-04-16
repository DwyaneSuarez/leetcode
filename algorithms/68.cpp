class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int len = words.size();
        if (len == 0)
            return ans;
        int width = words[0].size();
        int l = 0;
        for (int i = 1; i < len; i++) {
            if (width + 1 + words[i].size() <= maxWidth) {
                width += 1 + words[i].size();
            } else {
                int num = i - l;
                if (num == 1) {
                    string line;
                    line += words[l] + string(maxWidth - width, ' ');
                    ans.push_back(line);
                    width = words[i].size();
                    l = i;
                    continue;
                }
                int rest = maxWidth - width + num - 1;
                int space = rest / (num - 1);
                int rs = rest % (num - 1);
                string line;
                string spaces(space, ' ');
                for (int j = 0; j < num; j++) {
                    if (j)
                        line += spaces + (j <= rs ? " " : "");
                    line += words[l + j];
                }
                ans.push_back(line);
                width = words[i].size();
                l = i;
            }
        }
        if (width) {
            string lastLine;
            int lastWidth = 0;
            for (int i = l; i < len; i++) {
                lastLine += (i != l ? " " : "");
                lastWidth += i != l;
                lastLine += words[i];
                lastWidth += words[i].size();
            }
            string spaces(maxWidth - lastWidth, ' ');
            lastLine += spaces;
            ans.push_back(lastLine);
        }
        return ans;
    }
};
