#include <iostream>

int main(){
    int matrix[3][3] {
        {1,2,3},
        {6,2,3},
        {7,1,9}
    };
    int matrix2[3][3] {
        {1,6,3},
        {9,2,3},
        {7,1,1}
    };
    int arr[3] = {0,0,0};
    for(int i=0;i<3;i++){
        int MaxElementForColumn = -99999;
        for(int j=0;j<3;j++){
            if(matrix2[j][i] > MaxElementForColumn)
                MaxElementForColumn = matrix2[j][i];
        }
        arr[i]=MaxElementForColumn;
    }



    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            
            if(matrix[i][j] < arr[j]){
                matrix[i][j] = 0;
            }
        }
        
    }

    for(int i = 0; i< 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
}