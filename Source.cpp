


#include <iostream>
#include <SDL.h>

//#include "template_functions.h"




#include "screen.h"








using namespace std;
/*

������� 9.

�������������� � ������

���������� ����������

�������� ����������

���������� ��� ������ (�������� ����� �� �������� ����������)

*/

/*

��������� �� ������� ������ ����.

��������������      P
����������� ������  T
������� �����       L

��������� �� ������� ���������� ���� O

������� P, T, L, O ����� �������� ���������



*/






int main(int argc, char* argv[])
{
    srand(1);

    Screen s(800, 800);

    s.add_figures();
    s.cycle();


    return 0;



 
}
