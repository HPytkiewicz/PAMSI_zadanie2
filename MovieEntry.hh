#include <string>

using namespace std;

class MovieEntry {
private:
float score;
string movieName;
public:
MovieEntry();
MovieEntry(float newScore, string newName);
MovieEntry(const MovieEntry& newEntry);
void display();
void setScore(float newScore) {this->score = newScore;}
void setName(string newName) {this->movieName = newName;}
};

MovieEntry::MovieEntry()
{
    this->score=0;
    this->movieName = "365 dni";
}

MovieEntry::MovieEntry(float newScore, string newName)
{
    this->score = newScore;
    this->movieName = newName;
}

MovieEntry::MovieEntry(const MovieEntry &newEntry)
{
    this->score = newEntry.score;
    this->movieName = newEntry.movieName;
}

void MovieEntry::display()
{
    std::cout << "Score: " << this->score << std::endl;
    std::cout << "Movie name: " << this->movieName << std::endl;
}