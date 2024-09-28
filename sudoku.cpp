#include <iostream>
#include <functional>
#include <optional>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;


using Matrix=vector<vector<optional<int>>>;
///std::vector<std::vector<std::optional<int>>> matrix9(9,std::vector<std::optional<int>>(9)); 
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

//setea un valor en una fila  col especifica
decltype (auto) setValor(Matrix & matrix,int a,int b,optional<int> valor)
{
 matrix[a][b]=valor;
 return 0;
}

//
/// Funcion para crear un grid inicial
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
 std::cout << "Hola" << std::endl;
    Matrix matrix = createInitialMatrix();
    printMatrix(matrix);


return 0;
}