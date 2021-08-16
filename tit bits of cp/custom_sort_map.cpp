struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

// ...
std::map<std::string, std::string, cmpByStringLength> myMap;
