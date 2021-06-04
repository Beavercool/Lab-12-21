#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <utility>
#include <string>

#ifndef ARRAY_COMMON_U
#define ARRAY_COMMON_U
namespace arrays
{
    template <typename T>
    void swap(T& e1, T& e2) // xor swap
    {
        e1 ^= e2;
        e2 ^= e1;
        e1 ^= e2;
    }

    template <typename T>
    void sort_rule(std::vector<T>& v, bool (*func)(T& e1, T& e2))
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (!func(v[i], v[j]) and !(i == j))
                    swap((v[i]), (v[j]));
            }
        }
    }

    template <typename T>
    void sort_rule(std::vector<T>& v, std::function<bool(T& e1, T& e2)> func)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (!func(v[i], v[j]) and !(i == j))
                    swap((v[i]), (v[j]));
            }
        }
    }

    template <typename T>
    void print(const std::vector<T>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += std::to_string(i) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]");

        std::cout << result << std::endl;
    }

    template <typename T1, typename T2>
    void print(const std::vector<std::pair<T1, T2>>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += "(" + std::to_string(i.first) + ", " + std::to_string(i.second) + "), ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]");

        std::cout << result << std::endl;
    }

    template <typename T>
    void print(const std::vector<std::vector<T>>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += "[";
            for (auto j : i)
            {
                result += std::to_string(j) + ", ";
            }
            result.erase(result.size() - 2, 2);
            result.append("]\n");
        }
        result.erase(result.end());
        result.append("]");

        std::cout << result << std::endl;
    }

    template <typename T>
    std::string to_str(const std::vector<T>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += std::to_string(i) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]");

        return result;
    }

    template <typename T>
    std::string to_str(const std::vector<std::vector<T>>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += "[";
            for (auto j : i)
            {
                result += std::to_string(j) + ", ";
            }
            result.erase(result.size() - 2, 2);
            result.append("]\n");
        }
        result.erase(result.size() - 1);
        result.append("]");

        return result;
    }

    template <typename T>
    T sum(const std::vector<T>& v)
    {
        T result = 0;
        for (auto i : v)
            result += i;

        return result;
    }

    template <typename T>
    T sum(const std::vector<std::vector<T>>& v)
    {
        T result = 0;
        for (auto i : v)
        {
            for (auto j : i)
                result += j;
        }

        return result;
    }

    template <typename T>
    T max(const std::vector<T>& v)
    {
        T mx = v[0];
        for (auto i : v) {
            if (mx < i) mx = i;
        }

        return mx;
    }

    template <typename T>
    T min(const std::vector<T>& v)
    {
        T mx = v[0];
        for (auto i : v) {
            if (mx > i) mx = i;
        }

        return mx;
    }

    template <typename T>
    T max(const std::vector<std::vector<T>>& v)
    {
        T mx = v[0][0];
        for (auto i : v)
        {
            for (auto j : i)
            {
                if (mx < j) mx = j;
            }
        }

        return mx;
    }

    template <typename T>
    T min(const std::vector<std::vector<T>>& v)
    {
        T mx = v[0][0];
        for (auto i : v)
        {
            for (auto j : i)
            {
                if (mx > j) mx = j;
            }
        }

        return mx;
    }



}
#endif

template <typename T>
struct vec
{
public:
    T x, y;

    vec<int>& operator^=(vec<int>& y)
    {
        this->x ^= y.x;
        this->y ^= y.y;

        return *this;
    }
};

template <typename T>
vec<T> init_vec(T& x, T& y)
{
    vec<T> res;
    res.x = x;
    res.y = y;

    return res;
}

template <typename T>
vec<T> init_vec(T x, T y)
{
    vec<T> res;
    res.x = x;
    res.y = y;

    return res;
}

template <typename T>
void swap(T& e1, T& e2)
{
    e1 ^= e2;
    e2 ^= e1;
    e1 ^= e2;
}

template <typename T>
void sort_rule(std::vector<T>& v, bool (*func)(T& e1, T& e2))
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!func(v[i], v[j]) and !(i == j))
                swap((v[i]), (v[j]));
        }
    }
}

template <typename T>
void sort_rule(std::vector<T>& v, std::function<bool(T& e1, T& e2)> func)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!func(v[i], v[j]) and !(i == j))
                swap((v[i]), (v[j]));
        }
    }
}

bool foo1(int& a, int& b)
{
    if (a < b)
        return true;
    return false;
}

bool foo2(vec<int>& a, vec<int>& b)
{
    if (sqrt(a.x * a.x + a.y * a.y) < sqrt(b.x * b.x + b.y * b.y))
        return true;
    return false;
}

int main(int argc, char* argv[])
{

    std::vector<int> v = { 10, 31, 62, 34, 43, 25, 86, 74, 98, 89, 110 };

    std::cout << "Original: " << arrays::to_str(v) << std::endl;
    sort_rule<int>(v, &foo1);
    std::cout << "Sorted: " << arrays::to_str(v) << std::endl;

    std::vector<vec<int>> v2;
    for (int i = 0; i < 8; i++) // filling array
    {
        v2.push_back(init_vec<int>(int(i + 3), int((i + 4) * 3)));
    }

    std::cout << std::endl;

    std::cout << "Original: " << std::endl;
    for (auto i : v2)
    {
        std::cout << i.x << " : " << i.y << std::endl;
    }

    sort_rule<vec<int>>(v2, [&](vec<int> a, vec<int> b) -> bool {
        if (sqrt(a.x * a.x + a.y * a.y) < sqrt(b.x * b.x + b.y * b.y)) return true;
        return false;
        });

    std::cout << "Sorted: " << std::endl;
    for (auto i : v2)
    {
        std::cout << i.x << " : " << i.y << std::endl;
    }
    getchar();
}