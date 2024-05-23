#include<iostream>
#include<string.h>

using namespace std;

class String{
protected:
    char *m_nBuffer;
    void _init();
    void _clear();
    void _copy(const char* lpsz);
public:
    String(){
        _init();
    }
    String(const char* lpsz){
        _init();
        _copy(lpsz);
    }
    ~String() { // 소멸자
        _clear();
    }
    void print() const { // 문자열 출력 메소드
    if (m_nBuffer)
        cout << m_nBuffer << endl;
    }


    void set(const char* lpsz){
        _clear();
        _copy(lpsz);
    }
};

int main(){
    String s;
    s.set("hello");
    s.print();  // "hello" 출력
    return 0;
}


void String::_init(){
    m_nBuffer = 0;
}

void String::_clear(){
    if(m_nBuffer)
        delete []m_nBuffer;
        _init();
}

void String::_copy(const char* lpsz)
{
    if(lpsz != 0){
        int len = strlen(lpsz);
        m_nBuffer = new char [len + 1];
        if (m_nBuffer)
            strcpy(m_nBuffer, lpsz);
    }
}
