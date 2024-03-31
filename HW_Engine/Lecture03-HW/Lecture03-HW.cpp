#include <iostream>
using namespace std;

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

enum ColorMask {
    WHITE = 0b1,
    RED = 0b10,
    GREEN = 0b100,
    YELLOW = 0b1000,
    CYAN = 0b10000,
    MAGENTA = 0b100000,
    EXIT = 0b1000000
};

void block(int Color)
{
    cout << "\x1b[" << Color << "m" << endl;
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 10; x++)
            cout << "*";
        cout << endl;
    }
    cout << "\x1b[" << White << "m" << endl;

    cout << endl;
}

int main()
{
    /*
    * 흰색 블록을 그리는 키코드 : 1 (1)
    * 빨강색 블록을 그리는 키코드 : 2 (10)
    * 녹색 블록을 그리는 키코드 : 4 (100)
    * 노란색 블록을 그리는 키코드 : 8 (1000)
    * 청록색 블록을 그리는 키코드 : 16 (10000)
    * 마젠타색 블록을 그리는 키코드 : 32 (100000)
    * 프로그램 종료 : 64 (1000000)
    *
    * 프로그램을 시작하면 아래와 같이 쓰시오
    *
    *
    * 화면에 그림을 그리는 프로그램입니다.
    * 학번 : 349218347(본인학번)
    * 이름 : 본인이름
    *
    * 화면에 그릴 물체코드를 입력하세요 :
    * (반복)
    */

    int num = 0;

    cout << "화면에 그림을 그리는 프로그램입니다.\n" << "학번 : 202327027\n" << "이름 : 박윤하\n" << endl;

    while (true)
    {
        cout << "화면에 그릴 물체 코드를 입력하세요 => ";
        cin >> num;
        if ((num == ColorMask::EXIT))
        {
            cout << "\n프로그램을 종료합니다." << endl;
            return 0;
        }
        if ((num <= 0) || (num > ColorMask::EXIT))
        {
            cout << "\n잘못 입력한 코드입니다. 재입력하세요.\n" << endl;
        }
        else
        {
            if (num & ColorMask::WHITE)
            {
                block(White);
            }
            if (num & ColorMask::RED)
            {
                block(Red);
            }
            if (num & ColorMask::GREEN)
            {
                block(Green);
            }
            if (num & ColorMask::YELLOW)
            {
                block(Yellow);
            }
            if (num & ColorMask::CYAN)
            {
                block(Cyan);
            }
            if (num & ColorMask::MAGENTA)
            {
                block(Magenta);
            }
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}