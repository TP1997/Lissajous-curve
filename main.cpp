#include <iostream>
#include <SFML/Graphics.hpp>
#include "application.h"
using namespace std;

int main()
{
    Application *app=new Application(12,8);
    app->mainloop();
    return 0;
}
