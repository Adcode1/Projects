#include "LinearProbing.h"
#include <vector>
using namespace std;
void LinearProbing::createAccount(std::string id, int count) {
    Account a;
    a.balance = count;
    a.id = id;
    int key = hash(id);
    if(bankStorage1d.empty()) {
        bankStorage1d.resize(100000);
    }
    if (bankStorage1d[key].id != "") {
        int size = bankStorage1d.size();
        for (int i = 0; i < size; i++) {
            if (bankStorage1d[(key + i) % size].id == "") {
                bankStorage1d[(key + i) % size] = a;
                return; 
            }
        }
    } 
    else {
        bankStorage1d[key] = a;
    }
}
void mergeL(std::vector<int>& arr, int left, int mid, int right) {
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
void mSortL(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mSortL(arr, left, mid);
        mSortL(arr, mid + 1, right);

        mergeL(arr, left, mid, right);
    }
}
std::vector<int> LinearProbing::getTopK(int k) {
    vector<int> bal;
    vector<int> ans;
    for(int i=0;i<bankStorage1d.size();i++){
        if(bankStorage1d[i].id!=""){
        bal.push_back(bankStorage1d[i].balance);
    }}
    int n=bal.size();
    mSortL(bal,0,n-1);
    int mi=k;if(bal.size()<k){mi=bal.size();}
    for (int i = 0; i<mi; i++)
    {
        ans.push_back(bal[i]);
    }
    return ans; // Placeholder return value
}

int LinearProbing::getBalance(std::string id) {
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

void LinearProbing::addTransaction(std::string id, int count) {
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
bool LinearProbing::doesExist(std::string id) {
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

bool LinearProbing::deleteAccount(std::string id) {
    int key=hash(id);int size=bankStorage1d.size();
    for(int i=0;i<size;i++){
        if(bankStorage1d[(key+i)%size].id==id){
         bankStorage1d.erase(bankStorage1d.begin()+(key+i)%size);
         return true;
        }
    }
    return false; // Placeholder return value
}
int LinearProbing::databaseSize() {
    int give=0;
    if(bankStorage1d.size()==0){
        return 0;
    }
    for(int i=0;i<bankStorage1d.size();i++){
        if(bankStorage1d[i].id!=""){
            give++;
        }
    }
    return give; // Placeholder return value
}
int LinearProbing::hash(std::string id) {
    int ans=0;
    for(int i=0;i<id.length();i++){
        ans+=i*id[i];
        ans%=100000;
    }
    return ans;
}

