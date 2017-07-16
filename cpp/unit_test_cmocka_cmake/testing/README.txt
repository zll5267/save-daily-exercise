required:
    cmake(compile system)
    cmocka(unit test framework with mock func support)
    lcov(code coverage tool)

test folder structure is same with the source code;
test is file-based: every file with one test executable;
test is function-based: every function in the file with one test function;

cmake -DCMAKE_BUILD_TYPE=Debug ..
make ll_test
