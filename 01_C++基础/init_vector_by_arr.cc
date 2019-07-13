#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> v1(begin(arr), end(arr));
    for (auto i : v1)
        cout << i << endl;

    {
/*
 *         // 编译错误
 *         int *arr = (int *)malloc(sizeof(int) * 10);
 *         for (int i = 0; i < 10; i++)
 *             arr[i] = i;
 * 
 *         vector<int> v2(begin(arr), end(arr));
 *         for (auto i : v2)
 *             cout << i << endl;
 */
    }
}
