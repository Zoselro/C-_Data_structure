#include <iostream>

// namespace 사용하는 이유 : 동일명의 함수를 구분지어 호출할 수 있게 도와준다.

namespace A_RANGE
{
	int score = 100;
	int FUNC(int s)
	{
		return s/5;
	}
}
  
namespace B_RANGE
{
	int score = 200;
	int FUNC(int s)
	{
		return s/10;
	}
}

namespace C_RANGE
{
    int score = 3000;
    int FUNC(int s){
        return s/20;
    }
}

namespace std
{
	int score = 9999;
}

// std를 사용하며 안에 있는 함수를 호출하여 사용하겠다.
using std::cout;
using std::endl;
using std::cin;

// RANGE를 사용하며 안에 있는 함수를 호출하여 사용하겠다.
//using namespace A_RANGE;
//using namespace B_RANGE;
//using A_RANGE::FUNC;
 
int main()
{
	int score = 0;

	cout << "score 값 입력 : ";
	cin >> score;
	cout << '\n';

    //main score
	cout << "main score : " << score << endl; // main에 정의되어있는 score 값
    
    //A_RANGE score
	cout << "A_RANGE score : " << A_RANGE::score << endl; // A_RANGE에 정의 되어있는 score 값
    cout << "A_RANGE->FUNC : " << A_RANGE::FUNC(score) << endl; // A_RANGE에 정의 되어있는 함수를 호출한 값

    //B_RANGE score
    cout << "B_RANGE score : " << B_RANGE::score << endl;
	cout << "B_RANGE score : " << B_RANGE::FUNC(score) << endl;

    //C_RANGE score
    cout << "C_RANGE score : " << C_RANGE::score << endl;
    cout << "A_RANGE::FUNC : " << C_RANGE::FUNC(score) << endl;

	cout << "std에 정의되어있는 score : " << std::score << endl;



	return 0;
}