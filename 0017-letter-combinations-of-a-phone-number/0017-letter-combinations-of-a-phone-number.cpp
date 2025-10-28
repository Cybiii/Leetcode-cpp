class Solution {
        unordered_map<int, string> num_to_letters = {
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
public:
    vector<string> letterCombinations(string digits) {

        string subset;
        vector<string> result;
        backtrack(0, subset, digits, result);
        return result;
    }
private:
    void backtrack(int index, string& subset, string& digits, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(subset);
            return;
        }

        for (char letter : num_to_letters[digits[index]]) {
            subset.push_back(letter);
            backtrack(index + 1, subset, digits, result);
            subset.pop_back();
        }
    
    }
};
