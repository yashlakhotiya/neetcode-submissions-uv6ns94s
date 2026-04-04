class DS {
    vector<int> parent;
    vector<int> rank;
    public:
    DS(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int find(int i) {
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unon(int i, int j) {
        int p1 = find(i), p2 = find(j);
        if(p1 == p2) return false;
        if(rank[p2] > rank[p1]) swap(p1, p2);
        if(rank[p1] == rank[p2]) rank[p1]++;
        parent[p2] = p1;
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DS ds(n);
        unordered_map<string,int> emailIdmp;
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string &email = accounts[i][j];
                if(emailIdmp.count(email)) {
                    ds.unon(i, emailIdmp[email]);
                } else {
                    emailIdmp[email] = i;
                }
            }
        }
        unordered_map<int,vector<string>> idemails;
        for(auto &[email, id]: emailIdmp) {
            idemails[ds.find(id)].push_back(email);
        }
        vector<vector<string>> res;
        for(auto &[id, emaillist] : idemails) {
            vector<string> tempres;
            tempres.push_back(accounts[id][0]);
            sort(emaillist.begin(), emaillist.end());
            tempres.insert(tempres.end(), emaillist.begin(), emaillist.end());
            res.push_back(tempres);
        }
        return res;
    }
};