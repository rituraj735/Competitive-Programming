struct MyStruct
{
    int key;
    std::string stringValue;

    MyStruct(int k, const std::string& s) : key(k), stringValue(s) {}
};

struct less_than_key
{
    inline bool operator() (const MyStruct& struct1, const MyStruct& struct2)
    {
        return (struct1.key < struct2.key);
    }
};

std::vector < MyStruct > vec;

vec.push_back(MyStruct(4, "test"));
vec.push_back(MyStruct(3, "a"));
vec.push_back(MyStruct(2, "is"));
vec.push_back(MyStruct(1, "this"));

std::sort(vec.begin(), vec.end(), less_than_key());
