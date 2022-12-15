


#include <iostream>
#include <SDL.h>

//#include "template_functions.h"

#define DEBUG 1


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

��������� (������������ ����������), �� ������� ������ ����.

������ (������������ ����������):
��������������      F[0]
����������� ������  F[1]

������� ����� (����) L

��������� �� ������� ���������� ���� P[0]

������� P[], L, F[] ����� �������� ���������



*/





/*
* P - ���������
* L - �������� �����
* T - ����������� �������: t1, t2, t3 - �����
* 
* Ki - ����� �������� ��������

���� - ������������� - 3� ��� 4-�.

��� ��� ���� ����� ���� ������������, �� ������ R = 1000 �������� - ��� ����� ������������ ������ ����������� ����, 

{1. ���������
    L---Ti---P ��� P---Ti---L
    ����������� ���� ������ � P - ������� ����� Ki
2. �������� ����� ����� ���������� � ������ ��������
    Ti---L---P ��� P---L---Ti
    ���� �� ��������� ��� ���� �����.
3. ��������� ����� ���������� ����� � ������ ��������
    L---P---Ti ��� T---P---L
    ���� �� ��������� ��� ���� �����.
4. ��������� ����������� ������ ����� ���������� ����� � ������ ��������
    L---Ti �� ���������� P}

��� ��������� ������:
�� 20.

T1T2T3

������� ��������:

111���� ��� ���� 3-� ����� ������ 1, �� ������� ������� K ����� �������

222���� ��� ���� 3-� ����� ������ 2, �� ���� ���
333���� ��� ���� 3-� ����� ������ 3, �� ���� ���
444���� ��� ���� 3-� ����� ������ 4, �� ���� ���

������ ��������:

11 2:
     ����� ��������� ���������� ������� ����.
     12K1 K2 
     x = ����� ����������� ������ 3-L � ���������� 
     ������ x-K1 � x-K2 - �������� ������ ����������� ����
     3 ����� ����� �� ������ x-K1 ���������(� ��������������� ������� �� x) �� K1 �� R
     4 ����� ����� �� ������ x-K2 ���������(� ��������������� ������� �� x) �� K2 �� R



11 3:
    ����� ������� ���� 4-� ���������
    12 K1 K2 
    34 ����� ����������� ������ 1-3 � ������c�� � 2-3 � ���������

11 4:
     ����� ��������� ���������� ������� ����.
     12K1 K2
     x = ������ 3-L
     ����������� ��������� x � K1 � K2
     34 ����� ��� �� L � 3 � �� �� ������� ����������� R

1 22:
     ����� ��������� ���������� ������� ����.
     1 K1

     x1 = ����� ����������� ������ 2-L � ����������
     x2 = ����� ����������� ������ 3-L � ����������

     2 �� ������ x1-K1 ����������� ����� ��������� �� x1 (� ��������������� ������� �� K1) �� R 
     3 �� ������ x2-K1 ����������� ����� ��������� �� x2 (� ��������������� ������� �� K1) �� R 
3 22:
     ����� ��������� ���������� ������� ����.
          
     x1 = ����� ����������� ������ 2-L � ����������
     x2 = ����� ����������� ������ 3-L � ����������
     
     x3 = ����� ����������� ������ 1-L � ����������

     1 ����� ����������� ������ 2-1 � ����������
     2 ����� ����������� ������ 3-1 � ����������

     3 �� ������ x1-x3 ����������� ����� ��������� �� x1 (� ��������������� ������� �� x3) �� R
     4 �� ������ x2-x3 ����������� ����� ��������� �� x2 (� ��������������� ������� �� x3) �� R



4 22:
    ������� ���� �� ���������

1 33:
     1 K1
     2 ����� ����������� ������ 2-1 � ����������
     3 ����� ����������� ������ 3-1 � ����������

2 33:

     x1 = ����� ����������� ������ 1-L � ����������

     1 x2 = ����� ����������� ������ 2-1 � ����������
     2 x3 = ����� ����������� ������ 3-1 � ����������

     3 �� ������ x1-x2 ����������� ����� ��������� �� x2 (� ��������������� ������� �� x1) �� R
     4 �� ������ x1-x3 ����������� ����� ��������� �� x3 (� ��������������� ������� �� x1) �� R
4 33:
     x1 = ������ 1-L 

     1 x2 = ����� ����������� ������ 2-1 � ����������
     2 x3 = ����� ����������� ������ 3-1 � ����������

     ����������� ��������� x1 � x2 � x3

     34 ����� ��� �� L � 1 � �� �� ������� ����������� R

1 44:
     1 K1

     x1 = ������ l-2
     x2 = ������ l-3


     ����������� ��������� x1 � x2 � K1

     2 ����� ��� �� L � 2 � �� �� ������� ����������� R
     3 ����� ��� �� L � 3 � �� �� ������� ����������� R
2 44:
    
        ������� ���� �� ���������



3 44:


     1 ����� ����������� 1-2 � ���������
     2 ����� ����������� 1-3 � ���������


     x3 = ����� ����������� l � 1

     x1 = ������ l-2
     x2 = ������ l-3


     ����������� ��������� x1 � x2 � x3

     3 ����� ��� �� L � 2 � �� �� ������� ����������� R
     4 ����� ��� �� L � 3 � �� �� ������� ����������� R

123:

     1 K1

     2 x1 = ����������� ������ 2-3 � ���������
     3 x2 = ����������� ������ 1-3 � ���������
     

     x3 = ����� ����������� l-2 � ���������

     4 �� ������ x3-K1 ����������� ����� ��������� �� K1 (� ��������������� ������� �� x3) �� R
     5 �� ������ x3-x1 ����������� ����� ��������� �� x1 (� ��������������� ������� �� x3) �� R




124:
     
     1 K1

     x3 = ����������� 1-2 � ��������� ����� L ������������ ��������� 

     x1 = ������ l-x3
     x2 = ������ l-3


     ����������� ��������� x1 � x2 � K1

     2 ����� ��� �� L � x3 � �� �� ������� ����������� R
     3 ����� ��� �� L � 3 � �� �� ������� ����������� R


    
134:
     1 ����� ����������� 1-2 � ���������
     2 x2 = ����� ����������� 3-2 � ���������

     3 K1

     x1 = ������ l-3

     ����������� ��������� x1 � x2

     4 ����� ��� �� L � 3 � �� �� ������� ����������� R


234:
     1 x3 = ����� ����������� 1-2 � ���������
     2 x2 = ����� ����������� 3-2 � ���������

     x4 = ����� (������ 1-l ����������� � ����������)
      


    3 �� ������ x3-x4 ����������� ����� ��������� �� x3 (� ��������������� ������� �� x4) �� R


     x1 = ������ l-3

     ����������� ��������� x1 � x2

     4 ����� ��� �� L � 3 � �� �� ������� ����������� R



*/

int main(int argc, char* argv[])
{
    srand(1);

    Screen s(800, 800);

    s.add_figures();
    s.cycle();


    return 0;



 
}
