#include <iostream>
#include <string>

using namespace std;

class MovieEntry {
private:
float score;
string movieName;
public:
MovieEntry(float newScore, string newName);
void display();
};


MovieEntry::MovieEntry(float newScore, string newName)
{
    this->score = newScore;
    this->movieName = newName;
}

void MovieEntry::display()
{
    std::cout << "Position: " << this->score << std::endl;
    std::cout << "Movie name: " << this->movieName << std::endl;
}