// LEETCODE: 127. Word Ladder ( BFS )

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        queue<pair<string,int>> qu;
        qu.push({beginWord,1});

        while(!qu.empty())
        {
          string word=qu.front().first;
          int steps=qu.front().second;
          qu.pop();

         if(word==endWord) return steps;
          for(int i=0;i<word.size();i++)
          {  
          char original_char=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                 word[i]=ch;
                 if(st.find(word)!=st.end())
                 {
                    st.erase(word);
                    qu.push({word,steps+1});
                 }
                 word[i]=original_char; // reassign the original character
            }
          }
        }
        
        return 0;
    }
};

// Time Complexity: O(N * L * 26) = O(N * L)

// At each level, you try changing each character (L positions) to 26 letters, so:
// You generate up to L * 26 possible words per word.
// In worst case, you visit all N words (since we avoid revisits using st).

//  Space Complexity: O(N * L)

// Set st holds all N words ⇒ O(N)
// Queue can grow up to N elements (in worst case) ⇒ O(N)
// Each word has length L, so stored strings take O(L) each.
