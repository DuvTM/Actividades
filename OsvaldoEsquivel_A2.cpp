#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    SQLHENV hEnv;
    SQLHDBC hDbc;
    SQLRETURN ret;

    // Asignar un gestor de entorno
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

    // Asignar un gestor de conexión
    ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

    // Conectarse a la base de datos
    ret = SQLConnect(hDbc, (SQLWCHAR*)L"Empresa", SQL_NTS, (SQLWCHAR*)L"Username", SQL_NTS, (SQLWCHAR*)L"Password", SQL_NTS);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {

        cout << "Conectado a la base de datos exitosamente." << endl;

        std::cout << std::endl;

        SQLHSTMT hStmt;
        ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
        std::cout << "Empleados" << std::endl;
        wcout << L"+------+--------+-----------+---------------------+-----+-----------+------------------+-----------+--------+-----------+ " << endl;
        wcout << L"| N.   | Nombre | Apellidos | Fecha de nacimiento | RFC | N. Centro | Nombre de centro | N. Puesto | Puesto | Directivo | " << endl;
        wcout << L"+------+--------+-----------+---------------------+-----+-----------+------------------+-----------+--------+-----------+ " << endl;

        //Select a la base de datos
        ret = SQLExecDirect(hStmt, (SQLWCHAR*)L"SELECT * FROM Empleados", SQL_NTS);




        wcout << L"+------+--------+-----------+---------------------+-----+-----------+------------------+-----------+--------+-----------+ " << endl;

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Directivos" << std::endl;
        wcout << L"+------+--------+-----------+---------------------+-----------+------------------+-----------+--------+ " << endl;
        wcout << L"| Id   | Nombre | Apellidos | Fecha de nacimiento | N. Centro | Nombre de centro | N. Puesto | Puesto | " << endl;
        wcout << L"+------+--------+-----------+---------------------+-----------+------------------+-----------+--------+ " << endl;

        //Select a la base de datos
        ret = SQLExecDirect(hStmt, (SQLWCHAR*)L"SELECT * FROM Directivo", SQL_NTS);




        wcout << L"+------+--------+-----------+---------------------+-----------+------------------+-----------+--------+ " << endl;

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Catalogo de puestos" << std::endl;
        wcout << L"+------------+--------+-----------+------------------+ " << endl;
        wcout << L"| N.Puesto   | Puesto | N. Centro | Nombre de centro | " << endl;
        wcout << L"+------------+--------+-----------+------------------+ " << endl;

        //Select a la base de datos
        ret = SQLExecDirect(hStmt, (SQLWCHAR*)L"SELECT * Catalogo de puesto", SQL_NTS);




        wcout << L"+------------+--------+-----------+------------------+ " << endl;

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Centro de trabajo" << std::endl;
        wcout << L"+-------------+------------------+--------+ " << endl;
        wcout << L"| N. Centro   | Nombre de centro | Ciudad | " << endl;
        wcout << L"+-------------+------------------+--------+ " << endl;

        //Select a la base de datos
        ret = SQLExecDirect(hStmt, (SQLWCHAR*)L"SELECT * FROM Centro de trabajo", SQL_NTS);




        wcout << L"+-------------+------------------+--------+ " << endl;
    }
    else {
        cout << "Fallo la conexion a la base de datos" << endl;
    }

    // Desconectar y liberar gestores de entorno
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    return 0;
}