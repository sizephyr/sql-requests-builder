#include <iostream>
#include <cassert>

#include "sql.h"

using namespace sql;

int main()
{
    std::string example{""};
    
    DeleteModel d;
    d._delete()
        .from("user")
        .where(column("id") == 1);
    example = "delete from user where id = 1";
    assert(example.compare(d.querry()) == 0);
    return 0;
}
