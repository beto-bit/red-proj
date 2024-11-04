#pragma once

#include <string>
#include <variant>
#include <vector>

#include "src/models/Company.hpp"


enum class FileError {
    NoFile,
    BadFormat,
    EmptyFile
};


void write_file_company(
    const std::string& filename,
    const std::vector<Company>& companies
);


[[nodiscard]]
std::variant<Company, FileError> read_file_company(
    const std::string& filename
);