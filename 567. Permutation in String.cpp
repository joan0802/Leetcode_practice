class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        if(l2 < l1)
            return false;
        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i < l1; i++) {
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
        }
        if(mp1 == mp2)
            return true;
        for(int i = l1; i < l2; i++) {
            mp2[s2[i]-'a']++;
            if(mp2[s2[i-l1]-'a'] == 1)
                mp2.erase(s2[i-l1]-'a');
            else
                mp2[s2[i-l1]-'a']--;
            if(mp1 == mp2)
                return true;
        }
        return false;
    }
};