class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>geneSet(begin(bank), end(bank));

        queue<string>que;
        que.push(startGene);

        unordered_set<string>vis;
        vis.insert(startGene);

        int level = 0;

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                string curGene = que.front();
                que.pop();

                if(curGene == endGene) {
                    return level;
                }

                for(char ch : "ACGT") {
                    for(int i = 0;i < curGene.length();i++) {
                        string temp = curGene;
                        temp[i] = ch; 
                        if(vis.find(temp) == vis.end() && geneSet.find(temp) != geneSet.end()) {
                            que.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};