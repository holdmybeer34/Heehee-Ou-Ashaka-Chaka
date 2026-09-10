#include <iostream>
#include <cstring>
#include <fstream>

struct Table{
    int* size = new int;
    char colour[20];

    void show(){
        std::cout << "Size: " << *size << std::endl;
        std::cout << "Colour: " << colour << std::endl;
    }

    int TableVolume(){
        return ((*size) * (*size) * (*size));
    }

    ~Table(){
        delete size;
    }
};

int main(){
    Table array[5];

    std::fstream file("data.txt");
    if (!file.is_open()){
        std::cout << "Could not open file" << std::endl;
        return 0;
    }

    for (int i = 0; i < 5; i++){
        int s;
        char col[20];
        file >> s >> col;

        *(array[i].size) = s;
        strcpy(array[i].colour, col);
    }
    file.close();

    for (int i = 0; i < 5; i++){
        std::cout << "Table_" << i + 1 << " info: " << std::endl;
        array[i].show();
        std::cout << "Volume: " << array[i].TableVolume() << std::endl;
        std::cout << std::endl;
    }

    int n = 0;
    std::cout << "\nTables with volume<100: " << std::endl;
    for (int i = 0; i < 5; i++){
        if (array[i].TableVolume() < 100) {
            std:: cout << "Table_" << i + 1 << " ";
        }    
        n++;
    }
    if (n == 0) std::cout << "No tables with volume<100";
}