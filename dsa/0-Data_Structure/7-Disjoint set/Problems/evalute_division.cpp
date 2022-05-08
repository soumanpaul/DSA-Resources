#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {

        vector<double> results(queries.size());

        // edge itself, parent edge, weight
        unordered_map<string, pair<string, double>> gidWeight;

        for (int i = 0; i < equations.size(); i++) {
            vector<string> equation = equations[i];
            string dividend = equation[0];
            string divisor = equation[1];
            double quotient = values[i];

            unionset(gidWeight, dividend, divisor, quotient);
        }
        // 2 run the evaluation with lazy updates in find() function
        for (int i = 0; i < queries.size(); i++) {
            vector<string> query = queries[i];
            string dividend = query[0];
            string divisor = query[1];

            if (gidWeight.find(dividend) != gidWeight.end() || gidWeight.find(divisor) != gidWeight.end()) {
                results[i] = -1.0;
            } else {
                pair<string, double> dividendEntry = find(gidWeight, dividend);
                pair<string, double> divisorEntry = find(gidWeight, divisor);
                string dividendGid = dividendEntry.first;
                string divisorGid = divisorEntry.first;
                double dividendWeight = dividendEntry.second;
                double divisorWeight = divisorEntry.second;

                if (dividendGid != divisorGid) {
                    results[i] = -1.0;
                } else {
                    results[i] = dividendWeight / divisorWeight;
                }
            }
        }
        return results;
    }

    pair<string, double> find(unordered_map<string, pair<string, double>> gidWeight, string nodeId) {

        if (gidWeight.find(nodeId) != gidWeight.end())
            gidWeight[nodeId] = (make_pair(nodeId, 1.0));

        // auto it = gidWeight.find(nodeId);
        pair<string, double> entry = gidWeight[nodeId];

        if (entry.first != nodeId) {
            pair<string, double> newEntry = find(gidWeight, entry.first);
            gidWeight[nodeId] = make_pair(newEntry.first, entry.second * newEntry.second);
        }
        auto it = gidWeight[nodeId];
        // cout << it.first<<" "<<it.second<<endl;
        pair<string, double> entry1 = make_pair(it.first, it.second);
        return entry1;
    }

    void unionset(unordered_map<string, pair<string, double>> gidWeight, string dividend, string divisor, double value) {
        pair<string, double> dividendEntry = find(gidWeight, dividend);
        pair<string, double> divisorEntry = find(gidWeight, divisor);

        string dividendGid = dividendEntry.first;
        string divisorGid = divisorEntry.first;
        double dividendWeight = dividendEntry.second;
        double divisorWeight = divisorEntry.second;

        double weight = divisorWeight * value / dividendWeight;
        if (dividendGid != (divisorGid)) {
            gidWeight[dividend] = (make_pair(divisorGid, weight));
        }
    }
};