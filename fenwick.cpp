#include <iostream>
#include <vector>

class fenwick
{
public:
    std::vector<int> T;
    int n;
    fenwick(int n)
    {
        this->n = n;
        T.assign(n, 0);
    }

    fenwick(std::vector<int> &A) : fenwick(A.size())
    {
        for (int i = 0; i < (int)A.size(); i++)
        {
            add(i, A[i]);
        }
    }
    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
        {
            ret += T[r];
        }
        return ret;
    }

    int sum(std::vector<int> &A)
    {
        return sum(A.size() - 1);
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
        {
            T[idx] += delta;
        }
    }

    void print()
    {
        for (auto &it : this->T)
        {
            std::cout << it << " ";
        }
    }
};

int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fenwick Afen(A);
    std::cout << Afen.sum(A) << std::endl;
    Afen.print();
}