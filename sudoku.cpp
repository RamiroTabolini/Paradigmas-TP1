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
std::optional<Matrix> tryValues(const Matrix&, int, int, const std::vector<int>&);
std::optional<Matrix> solveSudoku(const Matrix&);
optional<pair<int, int>> findEmptycell(const Matrix&);
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

std::optional<Matrix> tryValues(const Matrix& matrix, int row, int col, const std::vector<int>& values) {
    if (values.empty()) return std::nullopt; // Si no hay más valores, no hay solución
    int n = values.front();
    if (isValid(matrix, row, col, make_optional(n))) {
        Matrix matrixCopy = matrix;
        matrixCopy[row][col] = make_optional(n); // Asignar el valor temporal
        auto result = solveSudoku(matrixCopy);
        if (result.has_value()) return result; // Si encuentra solución
    }
    return tryValues(matrix, row, col, {values.begin() + 1, values.end()}); // valores restantes
}

std::optional<Matrix> solveSudoku(const Matrix& matrix){
    auto emptyCell= findEmptycell(matrix);// Busca la primera celda vacia
    if (!emptyCell.has_value()) return matrix;// Si no hay celdas vacias, devolvemos la solucion
    auto [row, col] = emptyCell.value();//obtenemos las coordenadas de la celda vacia
    std::vector<int> values = {1,2,3,4,5,6,7,8,9};
    return tryValues(matrix, row, col, values);
}

optional<pair<int, int>> findEmptycell(const Matrix& matrix) {
    // Encontrar una tupla (índice de fila, índice de columna) donde haya una celda vacía
    auto rowIt = std::find_if(matrix.begin(), matrix.end(), [](const vector<optional<int>>& row) {
        return std::any_of(row.begin(), row.end(), [](const optional<int>& cell) {
            return !cell.has_value();
        });
    });    
    if (rowIt == matrix.end())return nullopt;//No filas vacias

    int rowIdx = std::distance(matrix.begin(), rowIt);//Indice de la fila

    // Buscar la columna vacía dentro de esa fila
    int colIdx = std::distance(rowIt->begin(), std::find_if(rowIt->begin(), rowIt->end(), [](const optional<int>& cell) {
        return !cell.has_value();
    }));

    // Devolver la posición como un par (fila, columna)
    return make_optional(make_pair(rowIdx, colIdx));
}


// Find an empty cell (i.e., a cell with Nothing)
// findEmptyCell :: Grid -> Maybe (Int, Int)
/*
optional<pair<int,int>> findEmptycell(const Matrix& matrix){
     vector<optional<pair<int, int>>> cells;
     optional<pair<int,int>> pos;
int fila=0;
transform(matrix.begin(),matrix.end(),back_inserter(cells),[&fila,&cells,&pos](const vector<optional<int>>& datos)->optional<pair<int,int>>  
{ int col=0; transform(datos.begin(),datos.end(),back_inserter(cells),[&fila,&col,&pos](const optional<int>& valor)->optional<pair<int,int>> {
auto result=valor.has_value()?(col++,nullopt):(pos=make_optional(make_pair(fila,col)),cout<<"solo prueba,elimina este cout ("<<pos->first <<","<<pos->second<<")\n",col++,pos);
return result;
});fila++;return nullopt;});return nullopt;}*/

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
    // Crear la matriz inicial
    Matrix matrix = createInitialMatrix();

    // Imprimir la matriz inicial
    std::cout << "Tablero inicial de Sudoku:" << std::endl;
    printMatrix(matrix);
    
    // Resolver el Sudoku
    auto solucion = solveSudoku(matrix);
    
    // Verificar si se encontró una solución
    if (solucion.has_value()) {
        std::cout << "\nSudoku resuelto:" << std::endl;
        printMatrix(solucion.value());
    } else {
        std::cout << "\nNo se encontró solución para este Sudoku." << std::endl;
    }

    return 0;
}
