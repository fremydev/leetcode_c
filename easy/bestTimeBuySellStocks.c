#pragma GCC optimize("O3", "unroll-loops")
int maxProfit(int* prices, int pricesSize) {
int buy = prices[0];
int max = 0;
for(int i = 1; i < pricesSize; ++i){
    if(buy - prices[i] > 0){
        buy = prices[i];
    }
    if(prices[i] - buy > max){
        max = prices[i] - buy;
    }
}
    return max;
}
