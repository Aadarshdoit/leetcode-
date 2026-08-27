class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Try making this position just slightly bigger
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string candidate = target.substr(0, i);
                    candidate += char('a' + c);

                    cnt[c]--;

                    // Put remaining characters in smallest order
                    for (int j = 0; j < 26; j++) {
                        while (cnt[j] > 0) {
                            candidate += char('a' + j);
                            cnt[j]--;
                        }
                    }

                    ans = candidate;

                    // Restore counts
                    cnt[c]++;
                    for (char ch : candidate.substr(i + 1)) {
                        cnt[ch - 'a']++;
                    }

                    break;
                }
            }

            // Continue matching target[i]
            if (cnt[x] == 0) {
                break;
            }

            cnt[x]--;
        }

        return ans;
    }
};