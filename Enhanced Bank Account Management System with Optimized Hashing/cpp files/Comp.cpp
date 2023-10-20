#include "Comp.h"
#include <vector>
#include <iostream>
using namespace std;
void Comp::createAccount(std::string id, int count)
{
    Account a;
    a.id = id;
    a.balance = count;
    int key = hash(id);
    if (bankStorage2d.size() == 0)
    {
        bankStorage2d.resize(75011 + 1);
        bankStorage2d[key].push_back(a);
    }
    else
    {
        bankStorage2d[key].push_back(a);
    }
}
void mergeCo(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void SortCo(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        SortCo(arr, left, mid);
        SortCo(arr, mid + 1, right);

        mergeCo(arr, left, mid, right);
    }
}


std::vector<int>Comp::getTopK(int k)
{   
    std::vector<int> ans;
    std::vector<int> tot;
    for (int i = 0; i < bankStorage2d.size(); i++)
    {
        for (int j = 0; j < bankStorage2d[i].size(); j++)
        {
            if (bankStorage2d[i][j].id != "")
            {
                tot.push_back(bankStorage2d[i][j].balance);
            }
        }
    }
    int n=tot.size();
    SortCo(tot,0,n-1);
    int mi=k;if(tot.size()<k){mi=tot.size();}
    for (int i = 0; i<mi; i++)
    {
        ans.push_back(tot[i]);
    }
    return ans; // Placeholder return value

}
int Comp::getBalance(std::string id)
{
    int j = hash(id);
    int ans = -1;
    if(bankStorage2d.size()==0){
        return -1;
    }
    for (int i = 0; i < bankStorage2d[j].size(); i++)
    {
        if (bankStorage2d[j][i].id == id)
        {
            ans = bankStorage2d[j][i].balance;
            break;
        }
    }
    return ans;

}

void Comp::addTransaction(std::string id, int count)
{
    int j = hash(id);
    bool yes = false;
    if(bankStorage2d.size()==0){
        yes=true;
        createAccount(id,count);
    }
    else{
    for (int i = 0; i < bankStorage2d[j].size(); i++)
    {
        if (bankStorage2d[j][i].id == id)
        {
            bankStorage2d[j][i].balance += count;
            yes = true;
        }
    }
    if (!yes)
    {
        createAccount(id, count);
    }}
}
bool Comp::doesExist(std::string id)
{
    int j = hash(id);
    if(bankStorage2d.size()==0){
        return false;
    }
    if(bankStorage2d[j].size()==0){
        return false;
    }
    for (int i = 0; i < bankStorage2d[j].size(); i++)
    {
        if (bankStorage2d[j][i].id == id)
        {
            return true;
        }
    }
    return false; // Placeholder return value
}

bool Comp::deleteAccount(std::string id)
{
    int j = hash(id);
    if(bankStorage2d.size()==0){
        return false;
    }
    if(bankStorage2d[j].size()==0){
        return false;
    }
    for (int i = 0; i < bankStorage2d[j].size(); i++)
    {
        if (bankStorage2d[j][i].id == id)
        {
            bankStorage2d[j].erase(bankStorage2d[j].begin() + i);
            return true;
        }
    }
    return false; 
}

int Comp::databaseSize()
{
    int count = 0;
    if (bankStorage2d.size() > 0)
    {
        for(int i=0;i<bankStorage2d.size();i++)
        {
            for(int j=0;j<bankStorage2d[i].size();j++)
            {
                if(bankStorage2d[i][j].id!="")
                {
                    count++;
                }
            }
        }
    }
    return count;
}
int Comp::hash(std::string id)
{
    int n = 0;
    for (int i = 0; i < id.size(); i++)
    {
        n += i*id[i];
    }
    n %= 75011;
    return n; // Placeholder return value
}

