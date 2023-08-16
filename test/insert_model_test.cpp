#include <iostream>
#include <cassert>

#include "sql.h"

using namespace sql;

int main()
{
    std::string example{""};
    // Insert
    InsertModel i;
    i.insert("score", 100)
            ("name", std::string("six"))
            ("age", (unsigned char)20)
            ("address", "beijing")
            ("create_time", nullptr)
        .into("user");
    example = "insert into user (score, name, age, address, create_time) values (100, 'six', 20, 'beijing', null)";
    assert(example.compare(i.querry()) == 0);

    // Insert with named parameters
    InsertModel iP;
    Param score {":score"};
    Param name {":name"};
    Param age {":age"};
    Param address {":address"};
    Param create_time {":create_time"};
    iP.insert("score", score)
            ("name", name)
            ("age", age)
            ("address", address)
            ("create_time", create_time)
        .into("user");
    example = "insert into user (score, name, age, address, create_time) values (:score, :name, :age, :address, :create_time)";
    assert(example.compare(iP.querry()) == 0);   

    return 0;
}
