#include<iostream>

using namespace std;

template <class T>

class Pointer{
private:
    T *p;
public:
   Pointer() {
        p = new T;
        *p = 0;
    }

    // 생성자: 값으로 초기화
    Pointer(T val) {
        p = new T;
        *p = val;
    }

    // 소멸자: 메모리 해제
    ~Pointer() {
        delete p;
    }

    // 값 설정
    void set(T val) {
        *p = val;
    }

    // 값 가져오기
    T get() const {
        return *p;
    }

protected:
    // 포인터에 대한 접근 제공
    T* getPointer() {
        return p;
    }
};



template <class T>
class DerivedPointer : public Pointer<T> {
public:
    // 부모 클래스의 p 포인터의 값을 증가시키는 함수
    void increment() {
        T* ptr = this->getPointer();  // protected 멤버에 접근
        (*ptr)++;
    }

    // 부모 클래스의 p 포인터의 값을 감소시키는 함수
    void decrement() {
        T* ptr = this->getPointer();  // protected 멤버에 접근
        (*ptr)--;
    }
};

int main() {
    DerivedPointer<int> p;

    p.set(10);
    cout << "Initial value: " << p.get() << endl;

    p.increment();
    cout << "After increment: " << p.get() << endl;

    p.decrement();
    p.decrement();
    cout << "After two decrements: " << p.get() << endl;

    return 0;
}