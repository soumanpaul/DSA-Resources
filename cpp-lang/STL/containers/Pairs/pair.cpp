#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string, int>> stations;
    unordered_map<int, pair<string, int>> avgTime;

public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        stations[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        pair<string, int> departure = stations[id];
        int time = t - departure.second;
        pair<string, string> pr = {departure.first, stationName};
        avgTime[id] = make_pair(pr, time);
    }

    double getAverageTime(string startStation, string endStation) {
        vector<int> count;
        cout << "............print............." << endl;

        for (auto x : avgTime) {
            if (x.first.first == startStation) {
                if (x.first.second == endStation) {
                    count.push_back(x.second.second);
                }
            }
        }

        double sum = ceil(accumulate(count.begin(), count.end(), 0) / count.size());
        return sum;

        return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */