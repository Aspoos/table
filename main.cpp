#include <iostream>
#include <iomanip>
#include <cstdlib>

void print_completed_line(int startPrefix, int endPrefix, int insidePrefix, int insideSpace) {
    std::cout << char(startPrefix);
    for (int i = 0; i < insideSpace; ++i) {
        std::cout << char(insidePrefix);
    }
    std::cout << char(endPrefix) << std::endl;
}

void draw_table(int n) {
    print_completed_line(201, 187, 205, 19);
    for (int i = 1; i <= 10; i++) {
        std::cout << char(186) << std::setw(4) << n << " . " << std::setw(2) << i;
        std::cout << " = " << std::setw(6) << n * i << std::setw(2) << char(186) << std::endl;
    }
    print_completed_line(200, 188, 205, 19);
}

void display_message(std::string content, bool breakLine) {
    std::cout << content << std::endl;

    if (breakLine) std::cout << std::endl;
}

int verify_table_limit(int n) {
    int tmp = n;
    if (n < 0 || n > 100) {
        std::system("clear");
        tmp = -1;
        display_message("Numero deve estar entre 0 e 100, por favor\ndigite novamente um numero valido.", true);
    }

    return tmp;
}

int main() {
    int n = -1;
    while (n == -1) {
        display_message("Descobra a tabuada, digite o numero desejado entre 0 a 100: ", false);
        std::cin >> n;
        n = verify_table_limit(n);
    }
    draw_table(n);
    return n;
}