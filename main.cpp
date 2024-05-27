#include "TXLib.h"
#include <fstream>

using namespace std;

bool Click(int x){

    return (GetAsyncKeyState(VK_LBUTTON) && txMouseX() >= x + 23 && txMouseX() <= x + 214 + 23 && txMouseY() >= 220
            &&  txMouseY() <= 388);

}

struct Form {

    string que;
    HDC img1;
    string ans1;
    HDC img2;
    string ans2;
    HDC img3;
    string ans3;
    int rians;


};

string getPart(int *pos2, string stroka) {

    int pos1 = *pos2 + 1;
    *pos2 = stroka.find(",", pos1);
    string part = stroka. substr(pos1, *pos2 - pos1);

    return part;
}

int main()
    {

    txCreateWindow (800, 600);

    int n_que = 1;

    int i = 0;

    int res = 0;

    Form form;

    Form text[10];

    string str;
    ifstream file("����.txt");

    while(file.good()){

        getline(file, str);

        int pos2 = -1;

        text[i].que = getPart(&pos2, str);
        text[i].img1 = txLoadImage(getPart(&pos2, str).c_str());
        text[i].ans1 = getPart(&pos2, str);
        text[i].img2 = txLoadImage(getPart(&pos2, str).c_str());
        text[i].ans2 = getPart(&pos2, str);
        text[i].img3 = txLoadImage(getPart(&pos2, str).c_str());
        text[i].ans3 = getPart(&pos2, str);
        text[i].rians = atoi(getPart(&pos2, str).c_str());
        i++;


    }
    file.close();

    char stroka[50];






    while(n_que <= 3) {

        form = text[n_que-1];

        txClear();
        txBegin();



        //�����
        txSetColor (TX_WHITE);
        txSetFillColor (TX_BLACK);
        txRectangle (10, 10, 790, 590);

        txSelectFont("Times New Roman", 30);

        //����� �������
        sprintf(stroka, "������ %d", n_que);
        txDrawText(614, 22, 756, 68, stroka);

        //������
        txDrawText(41, 82, 743, 162, form.que.c_str());

        //��������
        txRectangle(41 + 23, 220, 255 + 23, 388);

        txBitBlt(txDC(), 41 + 23, 220, 255 + 23, 388, form.img1);

        txRectangle(270 + 23, 220, 484 + 23, 388);

        txBitBlt(txDC(), 270 + 23, 220, 484 + 23, 388, form.img2);

        txRectangle(499 + 23, 220, 713 + 23, 388);

        txBitBlt(txDC(), 499 + 23, 220, 713 + 23, 388, form.img3);

        txSelectFont("Times New Roman", 20);

        //�����
        txDrawText(41 + 23, 388 + 30, 255 + 23, 460, form.ans1.c_str());

        txDrawText(270 + 23, 388 + 30, 484 + 23, 460, form.ans2.c_str());

        txDrawText(499 + 23, 388 + 30, 713 + 23, 460, form.ans3.c_str());

        if(Click(41)){
            if(form.rians == 1) {res ++;}
            while (txMouseButtons() == 1) {txSleep(10);}
            n_que ++;
        }
        if(Click(270)){
            if(form.rians == 2) {res ++;}
            while (txMouseButtons() == 1) {txSleep(10);}
            n_que ++;
        }
        if (Click(499)){
            if(form.rians == 3) {res ++;}
            while (txMouseButtons() == 1) {txSleep(10);}
            n_que ++;
        }


        txEnd();

    }
    txSetFillColor(TX_BLACK);
    txClear();



    txSetColor(TX_WHITE);
    sprintf(stroka, "��� ���������: %d", res);
    txDrawText(0,0,800, 600, stroka);

    txDeleteDC(form.img1);
    txDeleteDC(form.img2);
    txDeleteDC(form.img3);

    txTextCursor (false);
    return 0;
    }

