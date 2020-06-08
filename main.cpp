#include <Application/ApplicationFacade.hpp>


// How this program works?

// There are Facade and Strategy desing patterns used
// ApplicationFacade manages IO interface and program flow (based on user choice)
// ActionStrategy initializes Actions that user is choosing

// Program runs in a loop until user chooses '0' option, which means Exit



int main()
{
    std::string menuContent(std::string("\n====================\n") +
                            std::string("SDiZO Projekt nr 2: Algorytmy znajdowania MST i najkrotszych sciezek w grafach\n") +
                            std::string("Autor: Grzegorz Wolanski\n\n") +
                            std::string("Menu:\n") +
                            std::string("1. Algorytm znajdowania MST w grafie.\n") +
                            std::string("2. Algorytm znajdowania najkrotszej sciezki w grafie.\n") +
                            std::string("3. Pomiary.\n") +
                            std::string("0. Wyjscie.\n\n") +
                            std::string("Wybor: "));


    ApplicationFacade application(menuContent);

    // while '0' option was not selected -> keep running
    // program initializes user selected action and executes (runs) its code
    while(application.getCurrentMenuSelection() != "0")
    {
        application.printMenu();
        application.readMenuSelection();
        application.run();
    }

    return 0;
}
