#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define mii map<int, int>
#define pb push_back
#define __mayuk                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int32_t main()
{
    __mayuk;
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}

// word ladder ......

// the beginword may or may not be the part of the wordlist but the ending word must be the part of the wordlist.....

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // put the entire wordlist into the set datastructure....
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    st.erase(beginWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        // at which point the value of word is equal to the endword we return the current steps as answer....
        if (word == endWord)
            return steps;

        for (int i = 0; i < word.size(); i++)
        {
            char originalcharacter = word[i];

            // this internal loop will traverse on each possible combination from a to z .....
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            // after completing the traversal for a particular character during returning we have to make the word similar to as the original word so that for next character traversal we can start from the original word ......
            word[i] = originalcharacter;
        }
    }

    // if after the queue is empty and we still not return any answer it means that last word is not possible to reach so return 0....
    return 0;
}