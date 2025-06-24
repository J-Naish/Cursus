#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


static bool matches_at(std::string content, std::string target, int position) {
    int i = 0;
    while (target[i]) {
        if (content[position + i] != target[i]) {
            return false;
        }
        i++;
    }
    return true;
}


int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cerr << "Invalid args. Usage: `filename` `s1` `s2`" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];


    std::ifstream input_file(filename);

    if (!input_file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return 1;
    }


    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string content = buffer.str();
    input_file.close();


    std::ofstream output_file(filename + ".replace");
    if (!output_file.is_open()) {
        std::cerr << "Failed to open or create a replace file" << std::endl;
        return 1;
    }


    int i = 0;
    while (content[i]) {

        if (content[i] != s1[0]) {
            output_file << content[i];
        } else {

            if (matches_at(content, s1, i)) {
                output_file << s2;
                i += s1.length();
                continue;
            } else {
                output_file << content[i];
            }

        }

        i++;
    }

    output_file.close();

    return 0;
}

