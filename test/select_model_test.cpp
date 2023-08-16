#include <iostream>
#include <cassert>

#include "sql.h"

using namespace sql;

int main()
{
    std::string example{""};
    
    SelectModel select1;
    /*CASE 1 - hard case*/
    select1.select("id as user_id", "age", "name", "address")
        .distinct()
        .from("user")
        .join("score")
        .on(column("user.id") == column("score.id") && column("score.id") > 60)
        .where(column("score") > 60 && (column("age") >= 20 || column("address").is_not_null()))
        // .where(column("score") > 60 && (column("age") >= 20 || column("address").is_not_null()))
        .group_by("age")
        .having(column("age") > 10)
        .order_by("age desc")
        .limit(10)
        .offset(1);
    example = "select distinct id as user_id, age, name, address from user join score on (user.id = score.id) and (score.id > 60) where (score > 60) and ((age >= 20) or (address is not null)) group by age having age > 10 order by age desc limit 10 offset 1";
    assert(example.compare(select1.querry()) == 0);
    /*CASE 2 - reset*/
    select1.reset();
    example = "";
    assert(example.compare(select1.querry()) == 0);
    /*CASE 3 - add columns after reset*/
    select1.select("id as user_id", "age", "name", "address");
    example = "select id as user_id, age, name, address from user";
    assert(example.compare(select1.querry()) == 0);
    /*CASE 4 - clear*/
    select1.clear();
    example = "";
    assert(example.compare(select1.querry()) == 0);
    /*CASE 5 - add columns after clear*/
    select1.select("id as user_id", "age", "name", "address");
    example = "";
    assert(example.compare(select1.querry()) == 0);
    /*CASE 6 - add tables*/
    select1.from("user");
    example = "select id as user_id, age, name, address from user";
    assert(example.compare(select1.querry()) == 0);


    /*CASE N - construct with single table*/
    SelectModel select2{"test_table"};
    example = "";
    assert(example.compare(select2.querry()) == 0);
    return 0;
}
