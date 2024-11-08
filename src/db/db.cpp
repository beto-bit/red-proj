#include <fstream>
#include <ostream>
#include <string>
#include <vector>

#include "db.hpp"
#include "src/models/Company.hpp"
#include "src/utils/enum.hpp"


enum class DataPrefix : char {
    Company = '!',
    Department = '#',
    Area = '$',
    Workstation = '%'
};

std::ostream& operator<<(std::ostream& os, DataPrefix prefix) {
    os << to_underlying(prefix);
    return os;
}


void write_file_company(
    const std::string &filename,
    const std::vector<Company> &companies
) {
    std::ofstream file{filename};

    if (!file.is_open())
        return;

    for (const auto& comp : companies) {
        file << DataPrefix::Company << comp.name << '\n';

        for (const auto& dept : comp.departments) {
            file << DataPrefix::Department << dept.name << '\n';

            for (const auto& area : dept.areas) {
                file << DataPrefix::Area << area.name << '\n';

                for (const auto& worktn : area.workstations)
                    file << DataPrefix::Workstation << worktn.name << '\n';
            }
        }
    }
}


std::variant<Company, FileError> read_file_company(
    const std::string& filename
) {
    std::ifstream file{filename};

    if (!file.is_open())
        return FileError::NoFile;

    // Only read first line
    std::string firstline{};
    std::getline(file, firstline);

    if (firstline.empty())
        return FileError::EmptyFile;

    if (firstline[0] != to_underlying(DataPrefix::Company))
        return FileError::BadFormat;


    Company company{ firstline.substr(1), {} };

    for (std::string line; std::getline(file, line);) {
        // Ignore empty lines
        if (line.empty())
            continue;

        // Ignore prefix
        const auto content = line.substr(1);

        // If empty data
        if (content.empty())
            return FileError::BadFormat;

        
        // Match prefix
        switch (line[0]) {
            case to_underlying(DataPrefix::Department):
                company.departments.push_back({ content, {} });
                break;
            
            case to_underlying(DataPrefix::Area):
                company.departments.back().areas.push_back({ content, {} });
                break;

            case to_underlying(DataPrefix::Workstation):
                company
                    .departments.back()
                    .areas.back()
                    .workstations
                    .push_back({ content });
                break;

            default:
                return FileError::BadFormat;
        }
    }

    return company;
}
