#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int get_ged(int,int);
int primeNumber(int);
int primeNumber2(int);
vector<bool> sieveOfEratosthenes(int);

int main(){

    cout << get_ged(200,30) << endl;
    cout << primeNumber2(3) << endl;
    cout << primeNumber2(4) << endl;
    cout << primeNumber2(71) << endl;
    cout << "true : " << true << endl;
    cout << "false : " << false << endl;
    sieveOfEratosthenes(30);
    return 0;
}

int get_ged(int u,int v){
    
    int t = 0;

    while (u){
        if(u < v){
            t = u;
            u = v;
            v = t;
        }
        u = u - v;
    }
    return v;
}

int primeNumber(int n){
    for(int i = 2 ; i < n ; i++){
        if (n % 1 == 0)
            return false;
    }
    return true;
}

int primeNumber2(int n){
    cout << "들어온 값 : " << n << endl;
    int sqrn;
    sqrn = (int)sqrt(n); // 제곱근을 구하는 변수
    cout << "sqrn : " << sqrn << endl;
    for(int i = 2 ; i <= sqrn ; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

//에라토스테네스의 체
vector<bool> sieveOfEratosthenes(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님
    int sqrn = (int)sqrt(max_num);

    for (int i = 2; i <= sqrn; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}