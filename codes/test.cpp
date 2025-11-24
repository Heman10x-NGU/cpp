#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Convert vector to set for O(1) fast lookups.
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // 2. Edge case: If endWord isn't in the dictionary, impossible to reach.
        if (wordSet.find(endWord) == wordSet.end()) return {};
        
        // 3. 'parent' map stores the graph relationships. 
        // Key = child, Value = list of parents. ex: parent["dot"] = {"hot", "lot"}
        unordered_map<string, vector<string>> parent;
        
        // 4. 'visited' tracks words we have finished processing in PREVIOUS levels.
        unordered_set<string> visited;
        
        // 5. Standard BFS Queue.
        queue<string> q;
        
        // 6. Initialize BFS.
        q.push(beginWord);
        visited.insert(beginWord);
        
        bool found = false;
        
        // 7. Loop while queue has items AND we haven't found the endWord yet.
        // (If we found endWord, we finish this level then stop).
        while (!q.empty() && !found) {
            
            // 8. SNAPSHOT: How many nodes are in the current layer?
            // We only run the loop 'levelSize' times to keep levels separate.
            int levelSize = q.size();
            
            // 9. Temporary set to track words seen JUST IN THIS LEVEL.
            // Prevents duplicates in queue, but allows multiple parents to claim them.
            unordered_set<string> levelVisited; 
            
            // 10. Process exactly the number of nodes in this level.
            for (int i = 0; i < levelSize; i++) {
                string curr = q.front(); 
                q.pop();
                
                string temp = curr;
                // 11. Try changing every character (h*t, *ot, ho*)
                for (int j = 0; j < curr.size(); j++) {
                    char orig = curr[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == orig) continue;
                        temp[j] = ch;
                        
                        // 12. VALIDITY CHECK:
                        // - Is it a valid word in dictionary?
                        // - Have we visited it in a PREVIOUS level? (If yes, ignore it, it's not shortest path)
                        if (wordSet.count(temp) && visited.find(temp) == visited.end()) {
                            
                            // 13. QUEUE DUPLICATION CHECK:
                            // - Have we already seen this word in THIS SPECIFIC level?
                            // - If NO, add to queue and mark as seen in this level.
                            if (levelVisited.find(temp) == levelVisited.end()) {
                                q.push(temp);
                                levelVisited.insert(temp);
                            }
                            
                            // 14. GRAPH BUILDING (The most important line):
                            // Whether we just added it to queue OR another node added it,
                            // we ALWAYS add 'curr' as a valid parent for 'temp'.
                            parent[temp].push_back(curr);
                            
                            // 15. Check if we reached the goal.
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[j] = orig; // Backtrack character change for next iteration
                }
            }
            
            // 16. LEVEL COMPLETE:
            // Now we move all 'levelVisited' words to the global 'visited'.
            // They are officially "old news" for the next level.
            for (const string& word : levelVisited) {
                visited.insert(word);
            }
        }
        
        if (!found) return {};
        
        // 17. RECONSTRUCTION:
        // BFS is done. We have the map. Now use DFS to walk backwards from End -> Start.
        vector<vector<string>> result;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parent, path, result);
        return result;
    }
    
private:
    void dfs(const string& word, const string& beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& result) {
        
        // 18. Base Case: We walked all the way back to the start.
        if (word == beginWord) {
            reverse(path.begin(), path.end()); // Reverse to get Start->End
            result.push_back(path);
            reverse(path.begin(), path.end()); // Reverse back to restore state
            return;
        }
        
        // 19. Recursive Step:
        // Look at all parents of the current word and try paths through them.
        for (const string& prev : parent[word]) {
            path.push_back(prev);
            dfs(prev, beginWord, parent, path, result);
            path.pop_back(); // Backtrack
        }
    }
};

int main(){
    
   
   
}
