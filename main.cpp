#include <iostream>
#include <range/v3/core.hpp>
#include <range/v3/action.hpp>
#include <range/v3/view.hpp>
#include <range/v3/action/sort.hpp>
#include <vector>
#include <string>
#include <range/v3/numeric/accumulate.hpp>
#include <sstream>
using namespace std;
using namespace ranges;
int main()
{

    auto ints = views::ints(0, 10) | views::slice(3, 9);
    auto arr = {1, 2, 3, 4, 5, 2, 8, 1, 2, 3, 8};
    auto sli = views::all(arr)[{0, ranges::end - 4}];
    auto acc = ranges::accumulate(views::ints(0, 10), 0);
    cout << acc << endl;
    cout << sli << endl;
    cout << ints << endl;
    auto sorted = arr | ranges::to_vector | actions::sort;
    for (auto e : sorted)
    {
        cout << e << endl;
    }

    string s = "HelL,Word";
    vector<string> rng = actions::split(s, views::c_str(","));

    for (auto e : rng)
    {
        cout << e << endl;
    }
    string s2 = "{Max,Value};";
    auto p = [](char c) { return c == '}' || c == ';' || c == '{'; };
    string trm = s2 | views::trim(p) | ranges::to<string>;
    cout << trm << endl;
}