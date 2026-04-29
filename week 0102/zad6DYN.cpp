#include <iostream>
#include <functional>

// int main()
// {
//     int* ptr = new int;
//     *ptr = 42;
//     std::cout << *ptr;
//     delete ptr;
//     ptr = nullptr;
// }
// int main()
// {
//     int* dynArray = new int[5];
//     for(int i = 0; i < 5; i++)
//     {
//         dynArray[i] = i+1;
//     }

//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << dynArray[i] << " ";
//     }
//     delete[] dynArray;
//     dynArray = nullptr;

// }
// int main(){
//     int n;
//     std::cout << "Enter n: ";
//     std::cin >> n;
//     int* dynArray = new int [n];
//     for(int i = 0; i < n; i++){
//         std::cin >> dynArray[i];
//     }
//     std::cout << '\n';
//     for(int i = 0; i < n; i++){
//         std::cout << dynArray[i] << " ";
//     }
//     delete[] dynArray;
//     dynArray = nullptr;
// }
int myStrlen (const char* string)
{
    int strLen = 0;
    for(int i = 0; string[i] != '\0'; i++)
        strLen++;
    return strLen;
}

template <typename T>
void forEach(T arr[], int size, std::function<void(T&)> action)
{
    for(int i = 0; i < size; i++)
    {
        action(arr[i]);
    }
}
template <typename T>
void doubleElement(T& x){ x *= 2; }

template <typename T>
void ifZeroRemove(T& x){ if(x<0) x = 0; }

template <typename T>
bool compareStringArrays(const char* const& string1, const char* const& string2)
{
    return myStrlen(string1) < myStrlen(string2);
}

template <typename T>
void printElement(T x){std::cout << x << " ";}
bool intCompare(const int& a, const int& b)
{
    return a<b;
}
template <typename T>
void sortFunc(T arr[], int size, bool (*compare)(const T&, const T&))
{
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(compare (arr[j+1], arr[j])){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int arr [] = {10, 20, 30, 5, 3, 2};
    const char* words[] = {"banana", "hi", "apple", "ok", "kiwi"};
    sortFunc(words, 5, compareStringArrays<const char*>);
    // sortFunc(arr, 6,intCompare);
    // for(int i = 0; i < 6; i++)
    // {
    //     std::cout << arr[i] << " ";
    // }
    //forEach<int>(arr,6,doubleElement<int>);
    forEach<const char*>(words, 5, printElement<const char*>);
    
    // for(int i = 0; i < 6; i++)
    // {
    //      std::cout << arr[i] << " ";
    // }
}