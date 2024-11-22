function compile() {
    g++ -O2 -Wall -Wextra -Wfloat-equal -Wunreachable-code -Wfatal-errors -Wformat=2 -std=gnu++17 -D_GLIBCXX_DEBUG "$1"
}

function run() {
    compile "$1"
    valgrind ./a.out < "$2" > "$2".out
}
