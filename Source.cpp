


#include <iostream>
#include <SDL.h>

//#include "template_functions.h"




#include "screen.h"








using namespace std;
/*

Вариант 9.

Параллелепипед и призма

Построчное заполнение

Алгоритм «художника»

Построение «на землю» (источник света на конечном расстоянии)

*/

/*

Плоскость на которую падает тень.

Параллелепипед      P
Треугольная призма  T
Истоник света       L

Плоскость на которую проецируем тени O

Объекты P, T, L, O могут свободно двигаться



*/






int main(int argc, char* argv[])
{
    srand(1);

    Screen s(800, 800);

    s.add_figures();
    s.cycle();


    return 0;



 
}
