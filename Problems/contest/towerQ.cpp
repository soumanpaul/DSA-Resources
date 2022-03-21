#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{

    vector<vector<int>> arr = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};

    int length = arr.size();
    vector<vector<int>> cordinate;
    int quality = 0;
    for (int i = 0; i < length; i++)
    {
    int value = 0;
        for (int j = i+1; j < length; j++)
        {
            int sq = sqrt(pow((arr[i][0]-arr[j][0]),2) + pow((arr[i][1]-arr[j][1]),2));
            if(sq <=2){
                value+= floor(arr[i][2] / (1+ sq));
            }

        }
        if(value >= quality){
            quality = value;
            cordinate.push_back(arr[i]);
        }
    }
    // cout << "Cordinates........" << cordinate;
    return 0;
}