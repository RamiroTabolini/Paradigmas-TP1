#include <iostream>
#include <vector>
#include <optional>


using Matrix = vector<vector<optional<int>>>;

//Funcion para 


// Funcion para crear un grid inicial
Matrix createInitialMatrix(){
    return {
        {5, std::nullopt, 1, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt},
        {std::nullopt, std::nullopt, std::nullopt, std::nullopt, 7, std::nullopt, std::nullopt, std::nullopt, std::nullopt},
        {6, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 3, std::nullopt, 8},
        {std::nullopt, 6, std::nullopt, std::nullopt, 1, 9, std::nullopt, std::nullopt, std::nullopt},
        {std::nullopt, std::nullopt, 9, 8, 5, std::nullopt, std::nullopt, 6, std::nullopt},
        {std::nullopt, std::nullopt, std::nullopt, 3, std::nullopt, std::nullopt, 4, std::nullopt, std::nullopt},
        {std::nullopt, std::nullopt, 8, 5, std::nullopt, 6, std::nullopt, std::nullopt, std::nullopt},
        {4, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 3, std::nullopt, std::nullopt, 1},
        {std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 5, std::nullopt}
    };
}

int main(){
    std::cout << "Hola" << std::endl;
    

    return 0;
}