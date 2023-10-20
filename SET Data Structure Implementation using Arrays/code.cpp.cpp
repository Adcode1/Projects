#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
class SET
{
private:
    vector<int> v;

public:
    SET();
    void Insert(int a);
    void Delete(int k);
    int BelongsTO(int c);
    void print();
    int size();
    void Union(SET &s1, SET s2);
    void Intersection(SET &s1, SET s2);
    void Difference(SET &s1, SET s2);
    void Symmetric(SET &s1, SET s2);
    ~SET();
};
SET::SET()
{
}
void SET::Insert(int b)
{
    bool so = true;
    if (!BelongsTO(b))
    {
        if (v.size() == 0)
        {
            v.push_back(b);
        }
        else if (b > v[v.size() - 1])
        {
            v.push_back(b);
        }
        else if (b < v[0])
        {
            v.insert(v.begin(), b);
        }
        else
        {
            int i = 0;
            int j = v.size() - 1;
            while (i < j)
            {
                if (i == j - 1)
                {
                    break;
                }
                int mid = (i + j) / 2;
                if (b < v[mid])
                {
                    j = mid;
                }
                else if (b > v[mid])
                {
                    i = mid;
                }
            }
            v.insert(v.begin() + i + 1, b);
        }
    }
    cout << v.size() << endl;
}
void SET::Delete(int b)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == b)
        {
            v.erase(v.begin() + i);
            // cout << v.size() <<endl;
            break;
        }
    }
    // cout << v.size()-1 << endl;
}
int SET::BelongsTO(int c)
{
    bool l = false;
    int i = 0;
    int j = v.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (v[mid] == c)
        {
            l = true;
            break;
        }
        else if (v[mid] > c)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    if (l)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int SET::size()
{
    return v.size();
}
void SET::Union(SET &s1, SET s2)
{
    for (int i = 0; i < s2.v.size(); i++)
    {
        s1.Insert(s2.v[i]);
    }
}
void SET::print()
{
    for (auto pr : v)
    {
        if (pr != v[v.size() - 1])
        {
            cout << pr << ",";
        }
        else
        {
            cout << pr;
        }
    }
    cout << endl;
}
void SET::Intersection(SET &s1, SET s2)
{
    for (int i = 0; i < s1.v.size(); i++)
    {
        if (!s2.BelongsTO(s1.v[i]))
        {
            s1.v.erase(s1.v.begin() + i);
            i--;
        }
    }
}
void SET::Difference(SET &s1, SET s2)
{
    for (int i = 0; i < s1.v.size(); i++)
    {
        if (s2.BelongsTO(s1.v[i]))
        {
            s1.v.erase(s1.v.begin() + i);
            i--;
        }
    }
}
void SET::Symmetric(SET &s1, SET s2)
{
    vector<int> v3;
    for (int i = 0; i < s2.v.size(); i++)
    {
        if (!s1.BelongsTO(s2.v[i]))
        {
            v3.push_back(s2.v[i]);
        }
    }
    s1.Difference(s1, s2);
    for (int i = 0; i < v3.size(); i++)
    {
        s1.Insert(v3[i]);
    }
}
SET::~SET()
{
}
int main()
{
    vector<SET> s;
    while (true)
    {
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            int set_num, data;
            cin >> set_num >> data;
            if (set_num > s.size())
            {
                SET temp;
                s.push_back(temp);
                s[set_num].Insert(data);
            }
            else
            {
                s[set_num].Insert(data);
            }
            break;
        case 2:
            int num2, data2;
            cin >> num2 >> data2;
            if (num2 <= s.size())
            {
                if (!s[num2].BelongsTO(data2))
                {
                    cout << s[num2].size();
                }
                else
                {
                    s[set_num].Delete(data2);
                }
            }
            else
            {
                cout << -1 << endl;
            }
            break;
        case 3:
            int num3, data3;
            cin >> num3 >> data3;
            if (num3+1 > s.size())
            {
                cout << -1 << endl;
            }
            else
            {
                if (s[num3].BelongsTO(data3))
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            break;
        case 4:
            int num4a, num4b;
            cin >> num4a >> num4b;
            if (num4a+1 > s.size())
            {
                SET temp2;
                s.push_back(temp2);
            }
            else if (num4b+1 > s.size())
            {
                SET temp3;
                s.push_back(temp3);
            }
            else
            {
                s[num4a].Union(s[num4a], s[num4b]);
            }
            break;
        case 5:
            int num5a, num5b;
            cin >> num5a >> num5b;
            if (num5a+1 > s.size())
            {
                SET temp4;
                s.push_back(temp4);
            }
            else if (num5b+1 > s.size())
            {
                SET temp5;
                s.push_back(temp5);
            }
            else
            {
                s[num5a].Intersection(s[num5a], s[num5b]);
            }
            break;
        case 6:
            int num6;
            cin >> num6;
            if (num6+1 > s.size())
            {
                SET temp10;
                s.push_back(temp10);
            }
            else
            {
                cout << s[num6].size() << endl;
            }

        case 7:
            int num7a, num7b;
            cin >> num7a >> num7b;
            if (num7a+1 > s.size())
            {
                SET temp6;
                s.push_back(temp6);
            }
            else if (num7b +1> s.size())
            {
                SET temp7;
                s.push_back(temp7);
            }
            else
            {
                s[num7a].Difference(s[num7a], s[num7b]);
            }
            break;
        case 8:
            int num8a, num8b;
            cin >> num8a >> num8b;
            if (num8a+1> s.size())
            {
                SET temp8;
                s.push_back(temp8);
            }
            else if (num7b+1 > s.size())
            {
                SET temp9;
                s.push_back(temp9);
            }
            else
            {
                s[num8a].Symmetric(s[num8a], s[num8b]);
            }
        case 9:
            int num9;
            cin >> num9;
            if (num9+1 > s.size())
            {
                cout << endl;
            }
            else
            {
                s[num9].print();
            }
        }
    }
}
