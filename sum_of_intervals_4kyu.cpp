#include <vector>
#include <utility>
#include <algorithm>

int sum_intervals(std::vector<std::pair<int, int>> intervals) 
{
    using pairII = std::pair<int, int>;
    auto compare = [](std::pair<int, int>& p1, std::pair<int, int>& p2){return p1.first < p2.first;};
    std::sort(intervals.begin(), intervals.end(), compare);
    int res = 0;
    int cur = intervals[0].first;
    for(int i = 0; i<intervals.size(); i++)
    {

        pairII p = intervals[i];
        if(p.first < cur)
        {
            p.first = cur;
        }


        std::vector<pairII> v;
        cur = p.first;
        v.push_back(p);
        while(i<intervals.size()-1 && p.first >= intervals[i+1].first)
        {
            v.push_back(intervals[i+1]);
            i++;
        }
        pairII maxEnd = *std::max_element(v.begin(), v.end(), [](pairII& p1, pairII p2){return p1.second < p2.second;});
        if(cur > maxEnd.second) continue;
        res += maxEnd.second - cur;
        cur = maxEnd.second;
    }

    return res;

    
}

int main(int argc, char const *argv[])
{
    std::vector<std::pair<int, int>> intervals{{-460, 365}, {-443, 342}, {-368, -176}, {325, 475}, {444, 467}};

    int res = sum_intervals(intervals);

    int n = 0;
    return 0;
}
