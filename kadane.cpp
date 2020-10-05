#include <iostream>
#include <vector>

std::vector<int> kadane(std::vector<int> &A)
{
    int n = A.size();
    int currentSum = 0;
    int currentStart = -1;
    int maxStart;
    int maxEnd;
    int maxSum = 0;
    int j = 0;
    while (j < n)
    {
        if (currentSum <= 0)
        {
            currentStart = j;
            currentSum = A[j];
        }
        else
        {
            currentSum += A[j];
        }

        if (currentSum > maxSum)
        {
            maxStart = currentStart;
            maxEnd = j + 1;
            maxSum = currentSum;
        }
        j++;
    }
    return {maxSum, maxStart, maxEnd};
}

int main()
{
    std::vector<int> A{-23, 2, 14, -18, 23, 43, -12, -12, 34, -3, 2};
    std::vector<int> result = kadane(A);
    std::cout << "Max Sum = " << result[0] << std::endl;
    for (int i = result[1]; i < result[2]; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}