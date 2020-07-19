#include <iostream>    
using namespace std; //自底向上，两个循环，不用递归；   
int main()  
{  
    int n = 10;  
    int price[11] = { 0, 1, 7, 8, 9, 10, 17, 17, 20, 23, 24 };  
      
    int *r = new int[n + 1];  
  
    for (int i = 0; i <= n; ++i)  
        r[i] = 0;  //初始化  
  
    for (int i = 1; i <= n; ++i)//规模长度为i    
    {  
        int q = INT_MIN;  
        for (int j = 1; j <= i; ++j)//计算规模为i的最大收益    
        {  
            if (q < (price[j] + r[i - j]))//因为i>i-j，所以当计算r[i]时，r[i-j]已经解决，可以直接用    
                q = (price[j] + r[i - j]);  //迭代q；  
        }  
        r[i] = q;  //找出i这个位置的最优解；  
    }  
    cout << r[n];  //最后是n这个位置，就是n米长的木头的最大价值。  
    delete r;  
    return 0;  
}//此算法的时间效率是O(n^2)，空间效率是O (N) 
