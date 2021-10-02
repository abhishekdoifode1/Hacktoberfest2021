class Solution {
    public String reversePrefix(String word, char ch) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < word.length(); ++i) {
            if (word.charAt(i) == ch) {
                int temp = i;
                while (temp >= 0) {
                    res.append(word.charAt(temp));
                    temp--;
                }
                int temp2 = i + 1;
                while (temp2 < word.length()) {
                    res.append(word.charAt(temp2));
                    temp2++;
                }
                return res.toString();

            }
        }
        return word;
    }
}

//https://leetcode.com/problems/reverse-prefix-of-word/