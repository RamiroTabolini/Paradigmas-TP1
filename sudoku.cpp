#include <iostream>
#include <functional>
#include <optional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>
#include<utility>

using namespace std;

using Matrix = vector<vector<optional<int>>>;

Matrix setValor(Matrix&, int, int, optional<int>);
bool isValid(const Matrix&, int, int, optional<int>);
bool validInRow(const Matrix&, int, optional<int>);
bool validInCol(const Matrix&, int, optional<int>);
bool isValidSubmatriz(const Matrix&,int, int, optional<int>);
void printMatrix(const Matrix&);
Matrix createInitialMatrix();

// Setea un valor en una fila col especifica
Matrix setValor(Matrix& matrix, int row, int col, optional<int> valor) {
    matrix[row][col] = valor;
    return matrix;
}

// Verifica si un valor es valido en una posicion de la matriz
bool isValid(const Matrix& matrix, int row, int col, optional<int> valor) {
    return validInRow(matrix, row, valor) && validInCol(matrix, col, valor) 
           && isValidSubmatriz(matrix, row, col, valor);
}

// Validar valor en una fila
bool validInRow(const Matrix& matrix, int row, optional<int> valor) {
    return std::none_of(matrix[row].begin(), matrix[row].end(), 
        [=](const optional<int>& cell) { return cell == valor; });
}

// Validar valor en una columna
bool validInCol(const Matrix& matrix, int col, optional<int> valor) {
    return std::none_of(matrix.begin(), matrix.end(), 
        [=](const vector<optional<int>>& row) { return row[col] == valor; });
}

// Validar valor en una submatriz de 3x3
bool isValidSubmatriz(const Matrix& matrix,int row, int col, optional<int> valor){
    // Calculo de coordenadas 
    const int submatrizRowStart = (row / 3) * 3;
    const int submatrizColStart = (col / 3) * 3;
    int index = 0;
    vector<optional<int>> submatriz(9); // vector para guardar los 9 elementos de la submatriz
    std::generate(submatriz.begin(), submatriz.end(), [&]() {
        // Calculamos la fila y columna de cada celda del subgrid
        int r = submatrizRowStart + (index / 3);
        int c = submatrizColStart + (index % 3);
        ++index; // Incrementamos el índice
        return matrix[r][c];
    });

    // Verificamos si el valor no está en el subgrid, ignorando nullopt
    return std::none_of(submatriz.begin(), submatriz.end(), [=](const optional<int>& cell) {
        return cell == valor;
    });
}
//Funcion para buscar coord vacias
optional<pair<int,int>> findEmptycell(const Matrix& matrix){
     vector<optional<pair<int, int>>> cells;
     optional<pair<int,int>> pos;
int fila=0;
//transformamos la matriz en un vector de coordenadas
transform(matrix.begin(),matrix.end(),back_inserter(cells),[&fila,&cells,&pos](const vector<optional<int>>& datos)->optional<pair<int,int>>  
{ int col=0; transform(datos.begin(),datos.end(),back_inserter(cells),[&fila,&col,&pos](const optional<int>& valor)->optional<pair<int,int>> {
    //aplicamos la condicion
auto result=valor.has_value()?(col++,nullopt):(pos=make_optional(make_pair(fila,col)),cout<<"solo prueba,elimina este cout ("<<pos->first <<","<<pos->second<<")\n",col++,pos);
return result;
});fila++;return nullopt;});return nullopt;}

// Función para mostrar la matriz
void printMatrix(const Matrix& matrix) {
    std::for_each(matrix.begin(), matrix.end(), [](const vector<optional<int>>& row) {
        std::ostringstream oss;
        std::transform(row.begin(), row.end(), std::ostream_iterator<string>(oss, " "), [](const optional<int>& cell) {
            return cell ? to_string(*cell) : ".";
        });
        cout << oss.str() << endl;
    });
}

// Función para crear un grid inicial
Matrix createInitialMatrix() {
    return {
        {make_optional(5), nullopt, make_optional(1), nullopt, nullopt, nullopt, nullopt, nullopt, nullopt},
        {nullopt, nullopt, nullopt, nullopt, make_optional(7), nullopt, nullopt, nullopt, nullopt},
        {make_optional(6), nullopt, nullopt, nullopt, nullopt, nullopt, make_optional(3), nullopt, make_optional(8)},
        {nullopt, make_optional(6), nullopt, nullopt, make_optional(1), make_optional(9), nullopt, nullopt, nullopt},
        {nullopt, nullopt, make_optional(9), make_optional(8), make_optional(5), nullopt, nullopt, make_optional(6), nullopt},
        {nullopt, nullopt, nullopt, make_optional(3), nullopt, nullopt, make_optional(4), nullopt, nullopt},
        {nullopt, nullopt, make_optional(8), make_optional(5), nullopt, make_optional(6), nullopt, nullopt, nullopt},
        {make_optional(4), nullopt, nullopt, nullopt, nullopt, make_optional(3), nullopt, nullopt, make_optional(1)},
        {nullopt, nullopt, nullopt, nullopt, nullopt, nullopt, nullopt, make_optional(5), nullopt}
    };
}

int main() {
    std::cout << "Hola---" << std::endl;
    Matrix matrix = createInitialMatrix();
    vector<optional<pair<int,int>>> cells;
    optional<pair<int,int>> pos;
    printMatrix(matrix);
    
    //setValor(matrix,1,2,5);
    std::cout << (isValid(matrix,1,4,8) ? "TRUE" : "FALSE")<< std::endl;
    std::cout << (isValid(matrix,1,2,4) ? "TRUE" : "FALSE")<< std::endl;
    pos = findEmptycell(matrix); 
    return 0;
}