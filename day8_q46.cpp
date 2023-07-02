// #include <bits/stdc++.h> 
// bool cmp(pair<double,pair<int,int>>p1,pair<double,pair<int,int>>p2)
// {
//     return p1.first>p2.first;
// }
// double maximumValue (vector<pair<int,int>>& items, int n, int w)
// {
//     // Write your code here.
//     // ITEMS contains {weight, value} pairs.
//     double result=0;
//     vector<pair<double,pair<int,int>>>vec;
//     for(int i=0;i<n;i++)
//     {
//         double valuePerWeight=(1.0)*(items[i].second)/(items[i].first);
//         vec.push_back({valuePerWeight,{items[i].first,items[i].second}});


//     }
//     sort(vec.begin(),vec.end(),cmp);
//     for(int i=0;i<n;i++)
//     {
//         if(vec[i].second.first<=w)
//         {
//             result+=vec[i].second.second;
//             w-=vec[i].second.first;
//         }
//         else
//         {
//             result+=w*(vec[i].first);
//             break;
//         }
//     }
//     return result;

    
// }


#include <bits/stdc++.h> 

bool cmp(pair<double, pair<int, int>> p1, pair<double, pair<int, int>> p2)
{
    return p1.first > p2.first;
}

double maximumValue(vector<pair<int, int>>& items, int n, int w)
{
    double result = 0;
    vector<pair<double, pair<int, int>>> vec;
    
    for (int i = 0; i < n; i++)
    {
        double valuePerWeight = static_cast<double>(items[i].second) / items[i].first;
        vec.push_back({ valuePerWeight, { items[i].first, items[i].second } });
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < n; i++)
    {
        if (vec[i].second.first <= w)
        {
            result += vec[i].second.second;
            w -= vec[i].second.first;
        }
        else
        {
            result += w * vec[i].first;
            break;
        }
    }
    
    return result;
}