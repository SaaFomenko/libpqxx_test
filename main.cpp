#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <tuple>
#include <map>
#pragma execution_character_set( "utf-8")


void CreateTables(pqxx::connection& connect)
{
    std::string query = "CREATE TABLE IF NOT EXISTS public.books ("
        "id serial NOT NULL, "
        "title text NOT NULL, "
        "author text NOT NULL, "
        "CONSTRAINT books_pk PRIMARY KEY(id)"
        ");";
    
    pqxx::transaction t{connect};
    t.exec(query);
    t.commit();
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try{
        pqxx::connection connect(
            "host=localhost "
            "port=5432 "
            "dbname=test "
            "user=editor "
            "password=test01"
            );

        // pqxx::transaction t(connect);

        // SELECT query
        // auto values = t.query<int, std::string, std::string>("SELECT * FROM books");

        // for (auto [id, title, autor] : values)
        // {
        //     std::cout << "Id: " << id;
        //     std::cout << " with title: " << title;
        //     std::cout << " and autor: " << autor << std::endl;
        // }

        // t.exec("INSERT INTO books(title, autor) VALUES ('Том Соер', 'Марк Твен')");
        // t.commit();

        CreateTables(connect);

        std::cout << "All ok.\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Error list: " << e.what() << '\n';
    }
    return 0;
}