#include <iostream>
#include <cassert>

#include "sql.h"

using namespace sql;

int main()
{
    std::string example{""};
    
    std::vector<int> a = {1, 2, 3};
    UpdateModel u;
    u.update("user")
        .set("name", "ddc")
            ("age", 18)
            ("score", nullptr)
            ("address", "beijing")
        .where(column("id").in(a));
    example = "update user set name = 'ddc', age = 18, score = null, address = 'beijing' where id in (1, 2, 3)";
    assert(example.compare(u.querry()) == 0);

    // Update with positional parameters
    UpdateModel uP;
    Param mark = "?";
    uP.update("user")
        .set("name", mark)
            ("age", mark)
            ("score", mark)
            ("address", mark)
        .where(column("id").in(a));
    example = "update user set name = ?, age = ?, score = ?, address = ? where id in (1, 2, 3)";
    assert(example.compare(uP.querry()) == 0);
    return 0;
}
