#include <Application/Menu/Actions/MstSubmenu.hpp>
#include <Application/Menu/MstSubmenu/MstFacade.hpp>


MstSubmenu::MstSubmenu(const std::string& actionName)
    : BaseAction(actionName)
{ }

void MstSubmenu::run()
{
    std::string menuContent(std::string("\nMenu MST:\n") +
                            std::string("1. Wczytaj graf z pliku.\n") +
                            std::string("2. Wygeneruj losowy graf.\n") +
                            std::string("3. Wyswietl graf.\n") +
                            std::string("4. Wykonaj algorytm Prima.\n") +
                            std::string("5. Wykonaj algorytm Kruskala.\n") +
                            std::string("0. Powrot.\n\n") +
                            std::string("Wybor: "));

    MstFacade mstFacade(menuContent);

    while(mstFacade.getCurrentMenuSelection() != "0")
    {
        mstFacade.printMenu();
        mstFacade.readMenuSelection();
        mstFacade.run();
    }
}
