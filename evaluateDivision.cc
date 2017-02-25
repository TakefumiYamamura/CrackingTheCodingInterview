#define DBL_MAX 1.7976931348623158e+308
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> hash;
        int idx = 0;
        for (int i = 0; i < equations.size(); ++i)
        {
            if(hash.find(equations[i].first) == hash.end()){
                hash[equations[i].first] = idx;
                idx++;
            }
            if(hash.find(equations[i].second) == hash.end()){
                hash[equations[i].second] = idx;
                idx++;
            }
        }
        vector<vector<double> > g;
        g.resize(hash.size());
        for (int i = 0; i < hash.size(); ++i)
        {
            g[i].resize(hash.size());
            for (int j = 0; j < hash.size(); ++j)
            {
                g[i][j] = DBL_MAX;
            }
        }

        for (int i = 0; i < equations.size(); ++i)
        {
            g[hash[equations[i].first] ][hash[equations[i].second] ] = values[i];
            g[hash[equations[i].second] ][hash[equations[i].first] ] = 1.0 / values[i];
        }

        for (int k = 0; k < hash.size(); ++k)
        {
            for (int i = 0; i < hash.size(); ++i)
            {
                for (int j = 0; j < hash.size(); ++j)
                {
                    if(g[i][k] == DBL_MAX || g[k][j] == DBL_MAX) continue;
                    g[i][j] = min(g[i][j], g[i][k]*g[k][j]);
                }
            }
        }

        vector<double> answer;
        for (int i = 0; i < queries.size(); ++i)
        {
            if(hash.find(queries[i].first) == hash.end() || hash.find(queries[i].second) == hash.end()){
                answer.push_back(-1.0);
            }else if(g[hash[queries[i].first] ][hash[queries[i].second] ] == DBL_MAX){
                answer.push_back(-1.0);
            }else{
                answer.push_back(g[hash[queries[i].first] ][hash[queries[i].second] ]);
            }
        }
        return answer;

    }
};
