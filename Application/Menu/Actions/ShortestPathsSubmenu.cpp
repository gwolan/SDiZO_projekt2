#include <Application/Menu/Actions/ShortestPathsSubmenu.hpp>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/ShortestPathsFacade.hpp>


ShortestPathsSubmenu::ShortestPathsSubmenu(const std::string& actionName)
    : BaseAction(actionName)
{ }

void ShortestPathsSubmenu::run()
{
    std::string menuContent(std::string("\nMenu dla algorytmow znajdujacych najkrotsze sciezki:\n") +
                            std::string("1. Wczytaj graf z pliku.\n") +
                            std::string("2. Wygeneruj losowy graf.\n") +
                            std::string("3. Wyswietl graf.\n") +
                            std::string("4. Wykonaj algorytm Dijkstry.\n") +
                            std::string("0. Powrot.\n\n") +
                            std::string("Wybor: "));

    ShortestPathsFacade shortestPathsFacade(menuContent);

    while(shortestPathsFacade.getCurrentMenuSelection() != "0")
    {
        shortestPathsFacade.printMenu();
        shortestPathsFacade.readMenuSelection();
        shortestPathsFacade.run();
    }
}
