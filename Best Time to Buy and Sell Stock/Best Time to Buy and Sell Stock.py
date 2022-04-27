class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0
        minPrice = prices[0]
        for i in range(1, len(prices)):
            minPrice = min(prices[i], minPrice)
            maxProfit = max(prices[i] - minPrice, maxProfit)
        return maxProfit

    def maxProfit2(self, prices: List[int]) -> int:
        maxProfit = 0
        minPrice = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
            elif prices[i] - minPrice > maxProfit:
                maxProfit = prices[i] - minPrice
        return maxProfit