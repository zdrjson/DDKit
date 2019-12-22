public int[] pourWater(int[] heights, int V, int K) {
        while(V-- != 0) {
            drop(heights, K);
        }
       return heights;
}

private void drop(int[] heights, int K)  {
             Int best = K;
             for (int d = -1; d <= 1; d += 2) {
                   int i = k + d;
                   while (i >= 0 && i < heights.length && heights[i] <= heights[i - d]) {
                            if (heights[i] < heights[best])  {
                                 best = i;
                            }                           
                            i  += d;
                   }
                   if (best != K) {
                       break;
                   }
             }
             ++heights[K];
}

