#include "CubicProbing.h"
#include <vector>
using namespace std;
void CubicProbing::createAccount(std::string id, int count) {
    Account a;
    a.balance=count;
    a.id=id;int key=hash(id);
    if(bankStorage1d.size()==0){
    bankStorage1d.resize(100000);
    bankStorage1d[key]=a;
    }
    else{
    if((bankStorage1d[key].id!="")){
        int s=bankStorage1d.size();
        for(int i=0;i<s;i++){
            if(bankStorage1d[(key+i*i*i)%s].id==""){
                bankStorage1d[(key+i*i*i)%s]=a;
                break;
            }
        }
    }
    else{
        bankStorage1d[key]=a;
    }
    }
}
void mergeC(std::vector<int>& arr, int left, int mid, int right) {
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

void mSortC(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mSortC(arr, left, mid);
        mSortC(arr, mid + 1, right);

        mergeC(arr, left, mid, right);
    }
}
std::vector<int> CubicProbing::getTopK(int k) {
    vector<int> bal;
    vector<int> ans;
    for(int i=0;i<bankStorage1d.size();i++){
        if(bankStorage1d[i].id!=""){
        bal.push_back(bankStorage1d[i].balance);
    }}
    int n=bal.size();
    mSortC(bal,0,n-1);
    int mi=k;if(bal.size()<k){mi=bal.size();}
    for (int i = 0; i<mi; i++)
    {
        ans.push_back(bal[i]);
    }
    return ans; // Placeholder return value
}

int CubicProbing::getBalance(std::string id) {
    int key=hash(id);int size=bankStorage1d.size();
    bool exist=false;
    if(size==0){
        return -1;
    }
    if(bankStorage1d[key].id==id){
        exist=true;
        return bankStorage1d[key].balance;
    }
    for(int i=0;i<size;i++){
        if(bankStorage1d[(key+i)%size].id==id){
            exist=true;
            return bankStorage1d[(key+i)%size].balance;
        }
    }
    return -1;
     // Placeholder return value
}

void CubicProbing::addTransaction(std::string id, int count) {
       int key=hash(id);int size=bankStorage1d.size();
    bool exist=false;
    if(size==0){
        createAccount(id,count);
    }
    else{
    for(int i=0;i<size;i++){
        if(bankStorage1d[(key+i)%size].id==id){
        exist=true;
        bankStorage1d[(key+i)%size].balance+=count;
        break;
        }}
        if(!exist){
            createAccount(id,count);
        }
    }
}
bool CubicProbing::doesExist(std::string id) {
 int key=hash(id);int size=bankStorage1d.size();
    if(size==0){
        return false;
    }
    if(bankStorage1d[key].id==id){
       return true;
    }
    for(int i=0;i<size;i++){
        if(bankStorage1d[(key+i)%size].id==id){
            return true;
        }
    }
    return false; // Placeholder return value
}

bool CubicProbing::deleteAccount(std::string id) {
    int key=hash(id);int size=bankStorage1d.size();
    for(int i=0;i<size;i++){
        if(bankStorage1d[(key+i)%size].id==id){
         bankStorage1d.erase(bankStorage1d.begin()+(key+i)%size);
         return true;
        }
    }
    return false; // Placeholder return value
}
int CubicProbing::databaseSize() {
    int ans=0;
    for(int i=0;i<bankStorage1d.size();i++){
        if(bankStorage1d[i].id!=""){
            ans++;
        }
    }
    return ans; // Placeholder return value
}
int CubicProbing::hash(std::string id) {
    int ans=0;
    for(int i=0;i<id.length();i++){
        ans+=i*id[i];
        ans%=100000;
    }
    return ans; // Placeholder return value
}
