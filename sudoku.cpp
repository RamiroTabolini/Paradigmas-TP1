#include <iostream>
#include <functional>
#include <optional>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;


using Matrix=vector<vector<optional<int>>>;
// std::vector<std::vector<std::optional<int>>> matrix9(9,std::vector<std::optional<int>>(9)); 

// Setea un valor en una fila  col especifica
Matrix setValor(Matrix& matrix,int row,int col,optional<int> valor){
 matrix[row][col] = valor;
 return matrix;
}

// Verifia si un valor es valido en una posicion de la matriz
bool isValid(Matrix& matrix, int row, int col, int valor){
    return validInRow(matrix, row, valor) && validInCol(matrix, col, valor) 
    && validInSubgrid(matrix, row, col, valor);
}

// Validar valor en una fila
bool validInRow(Matrix& matrix, int row, int valor){
    return std::none_of(matrix[row].begin(), matrix[row].end(), 
    [=](const optional<int>& cell) { return cell == valor; });
}

// Validar valor en un columa
bool validInCol(Matrix& matrix, int col, int valor){
    return std::none_of(matrix.begin(), matrix.end(), 
    [=](const vector<optional<int>>& row) { return row[col] == valor; });
}

// Validar valor en una submatriz de 3x3
bool alidInSubgrid(Matrix& matrix,int row, int col, int valor){
    // Calculo de coordenadas 
    const int submatrizRowStart = (row / 3) * 3;
    const int submatrizColStart = (col / 3) * 3;

    vetor<optional<int>> submatriz(9); // vector para guardar los 9 elementos de la submatriz
    std::generate(submatriz.begin(), submatriz.end(),[=](){
        int r = 
    })
}

// Funcion para mostrar la matrix
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
return{{make_optional(5), nullopt, make_optional (1), nullopt, nullopt, nullopt, nullopt, nullopt, nullopt}
    ,{nullopt, nullopt, nullopt, nullopt, make_optional (7), nullopt, nullopt, nullopt, nullopt}
    , {make_optional (6), nullopt, nullopt, nullopt, nullopt, nullopt, make_optional (3), nullopt, make_optional (8)}
    , {nullopt, make_optional (6), nullopt, nullopt, make_optional (1), make_optional (9), nullopt, nullopt, nullopt}
    , {nullopt, nullopt, make_optional(9), make_optional (8), make_optional (5), nullopt, nullopt, make_optional (6), nullopt}
    , {nullopt, nullopt, nullopt, make_optional (3), nullopt, nullopt, make_optional (4), nullopt, nullopt}
    , {nullopt, nullopt, make_optional (8), make_optional (5), nullopt, make_optional(6) , nullopt, nullopt, nullopt}
    , {make_optional (4), nullopt, nullopt, nullopt, nullopt, make_optional (3), nullopt, nullopt, make_optional (1)}
    , {nullopt, nullopt, nullopt, nullopt, nullopt, nullopt, nullopt, make_optional (5), nullopt}
    };

}




decltype (auto) imprimirMatrix(Matrix & matrix){

    return 0;
}
int main() {
 std::cout << "Hola---" << std::endl;
    Matrix matrix = createInitialMatrix();
    printMatrix(matrix);


return 0;
}