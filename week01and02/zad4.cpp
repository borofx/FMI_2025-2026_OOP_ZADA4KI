#include <iostream>

template <typename T> 
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
bool intCompare(const int& a, const int& b)
{
    return a<b;
}
bool intCompareDescending(const int& a, const int& b)
{
    return a>b;
}
template <typename T>
void sortArray(T arr[], int size, bool (*compare)(const T&, const T&))
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(compare(arr[j+1], arr[j])){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int nums[] = {9834, 12, 23, 878, 555};
    sortArray(nums, 5, intCompare);
    for(int i = 0; i < 5; i++)
    {
        std::cout << nums[i] << " ";
    }
}