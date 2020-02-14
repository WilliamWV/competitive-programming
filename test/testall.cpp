#include "test.h"

int test_all(){
    
    return (
        test_biginteger() == OK && test_geometry() == OK && test_graph() == OK &&
        test_mathematics() == OK && test_searching() == OK && test_sorting() == OK
    ) ? OK : FAIL;

}