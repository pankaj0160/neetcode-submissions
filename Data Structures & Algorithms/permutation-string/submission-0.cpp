

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 1. Edge Case: If s1 is longer than s2, it can't be a substring.
        if (s1.length() > s2.length()) {
            return false;
        }

        // 2. Initialize frequency arrays for both strings (size 26 for 'a'-'z').
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // 3. Build the initial window of size s1.length()
        //    We count characters in s1 AND the first window of s2.
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;      // Count char in s1
            s2Count[s2[i] - 'a']++;      // Count char in the first window of s2
        }

        // 4. Calculate how many characters have matching frequencies initially.
        //    If 'matches' reaches 26, every character count is identical.
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        // 5. Slide the window across s2
        //    'l' is the left index (character leaving the window)
        //    'r' is the right index (character entering the window)
        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            
            // If all 26 counts match, we found a permutation!
            if (matches == 26) {
                return true;
            }

            // --- Step A: Add the new character (s2[r]) to the window ---
            int rightCharIndex = s2[r] - 'a';
            
            // If counts were equal, adding a char makes them unequal (decrement matches)
            if (s1Count[rightCharIndex] == s2Count[rightCharIndex]) {
                matches--;
            }
            
            s2Count[rightCharIndex]++; // Add the character
            
            // If counts become equal after adding, increment matches
            if (s1Count[rightCharIndex] == s2Count[rightCharIndex]) {
                matches++;
            }

            // --- Step B: Remove the old character (s2[l]) from the window ---
            int leftCharIndex = s2[l] - 'a';
            
            // If counts were equal, removing a char makes them unequal (decrement matches)
            if (s1Count[leftCharIndex] == s2Count[leftCharIndex]) {
                matches--;
            }
            
            s2Count[leftCharIndex]--; // Remove the character
            
            // If counts become equal after removing, increment matches
            if (s1Count[leftCharIndex] == s2Count[leftCharIndex]) {
                matches++;
            }

            // Move the left pointer to slide the window forward
            l++;
        }

        // 6. Final Check: Check if the last window was a match
        return matches == 26;
    }
};