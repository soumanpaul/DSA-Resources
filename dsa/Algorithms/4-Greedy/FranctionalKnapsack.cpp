bool myCmp(pair<int, int>a, pair<int,int>b){
    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;
    return r1 > r2;
}

double fKnaps(int w, pair<int, int> arr[], int n){
    sort(arr, arr+n, myCmp);
    double res = 0.0;
    for(int i = 0; i < n; i++){
        if(w => arr[i].second){
            res += arr[i].first;
            w = w - arr[i].second;
        } else {
            res+= arr[i].first*((double) w/ arr[i].second);
            break;
        }
    }
    return res;
}
