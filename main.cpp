#include "linkedList.hh"
#include <fstream>


int main() {
    /*
    std::fstream fileRanking;

    fileRanking.open("projekt2_dane.csv", ios::in);

    string x;

    getline(fileRanking, x);

    MovieEntry *film1 = new MovieEntry();
    getline(fileRanking,x,',');
    getline(fileRanking,x,',');
    film1->setName(x);
    getline(fileRanking,x,'\n');
    film1->setScore(std::stof(x));
    film1->display();

    MovieEntry *film2 = new MovieEntry();
    getline(fileRanking,x,',');
    getline(fileRanking,x,',');
    film2->setName(x);
    getline(fileRanking,x,'\n');
    film2->setScore(std::stod(x));
    film2->display();

    getline(fileRanking,x,',');
    getline(fileRanking,x,',');
    std::cout << "Title: " << x << std::endl;
    getline(fileRanking,x,'\n');
    std::cout << "Score (string for now): " << x << std::endl;
    */


   int answer;

    linkedList *lista;
    string nazwa;
    float score;
    bool quit = false;
    while(!quit){
    std::cout << "Insert your choice (1-insert, 2-display): ";
    std::cin >> answer;
   switch(answer){
        case 1:
        {
        cin.ignore();
        std::cout<<"Podaj nazwe filmu: ";
        std::getline(std::cin, nazwa);
        cin.ignore();
        std::cout<<"Podaj wynik filmu: ";
        std::cin >> score;
        
        MovieEntry temp;
        temp.setName(nazwa);
        temp.setScore(score);
        lista->insertFirst(temp);
        }
        break;
        case 2:
        {
        lista->displayAll();
        }
        break;
        default:
        quit = true;
        break;
   }
}
    return 0;
}