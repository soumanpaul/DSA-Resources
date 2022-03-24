int minCoins(int coin[], int n, int amount){
    sort(coin, coin+n);
    int res = 0;

    for(int i = n -1; i>=0; i--){
        if(coin[i] <= amount){
            res += floor(amount/coin[i]);
            amount -= res*coin[i]; 
        }
        if(amount == 0) break;
    }
    return res;
}

int main() {
    int coin[] = {5,10,2,1}, n = 4, amount  = 57;

    minCoins(coin, n, amount);
}