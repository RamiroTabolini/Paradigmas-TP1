#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

using Matrix = vector<vector<optional<int>>>;

//Funcion para mostrar la matrix
void printMatrix(const Matrix& matrix) {
    // Iteramos sobre cada fila
    std::for_each(matrix.begin(), matrix.end(), [](const vector<optional<int>>& row) {
        // Usamos std::transform para formatear cada celda y guardarlo en un string
        std::ostringstream oss;
        std::transform(row.begin(), row.end(), std::ostream_iterator<string>(oss, " "), [](const optional<int>& cell) {
            // Formateamos cada celda: si es nullopt, ponemos ".", si no, mostramos el número
            return cell ? to_string(*cell) : ".";
        });
        cout << oss.str() << endl;  // Imprimimos la fila formateada
    });
}

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
    Matrix matrix = createInitialMatrix();
    printMatrix(matrix);

    return 0;
}