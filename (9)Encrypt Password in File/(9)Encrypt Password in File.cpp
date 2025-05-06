#include <iostream>
#include "clsLoginScreen.h"

int main()

{
    while (true)//Unlimited loop
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            //break will go out of unlimited loop
            break;
        }
    }



    return 0;
}