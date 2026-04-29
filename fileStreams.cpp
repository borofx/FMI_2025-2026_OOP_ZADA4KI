#include <iostream>
#include <fstream>
#include <string>

//---------------writing from file below-------------------
// int main()
// {
//     int size = 5;
//     int *arr = new int[5]{1, 2, 3, 4, 5};

//     std::ofstream outFile("myFile1.txt");

//     if(outFile.is_open()){
//         for (int i = 0; i < size; i++){
//             outFile << arr[i] << '\n';
//         }
//         std::cout << "Uspeshno pisane vuv faila!\n";
//     } 
//     else {
//         std::cout << "Error when making file.\n";
//     }
//     delete[] arr;

// }
//---------------reading from file below-------------------
// int main(){
//     int capacity = 6;
//     int *arr = new int[capacity];
//     int count = 0;

//     std::ifstream inFile("myFile1.txt");

//     if(inFile.is_open()){
//         while(inFile >> arr[count] && count < capacity){
//             count++;
//         }
//         inFile.close();
//         std::cout << "Success reading " << count << " numbers from the file!\n";
//         for (int i = 0; i < count; ++i) {
//             std::cout << arr[i] << " ";
//         }
//         std::cout << "\n";
//     }
//     else{
//         std::cout << "Error when opening the file!\n";
//     }
//     delete[] arr;
// }
//-------copying from file into another file below---------
void copyFile(const std::string& sourceName, const std::string destName){

    std::ifstream inFile(sourceName); // read from here

    if (!inFile.is_open()) {
        std::cout << "Error: '" << sourceName << "' not found!\n";
        return;
    }

    std::ofstream outFile(destName); //write here

    if (!outFile.is_open()) {
        std::cout << "Error: copy '" << destName << "' can't be created!\n";
        inFile.close();
        return;
    }

    char c;
    while(inFile.get(c)){
        outFile.put(c);
    }
    inFile.close();
    outFile.close();

    std::cout << "Hoorrayy!\n";
}
int main(){
    std::string originalFile = "my_text.txt";
    std::ofstream testFile(originalFile);
    if (testFile.is_open()) {
        testFile << "Ей!\nТова е тестов файл.\nИма няколко реда и интервали.";
        testFile.close();
    }
    std::string copyName = "my_text_copy.txt";
    copyFile(originalFile, copyName);
}