#include <cstring>
#include <iostream>

class Media{
    protected:
        char *title;
        int duration;
        Media(const char* title, int duration){
            this->title = new char[strlen(title) + 1];
            strcpy(this->title, title);
            this->duration = duration;
        }
        Media(const Media& other){
            title = new char[strlen(other.title) + 1];
            strcpy(title, other.title);
            duration = other.duration;
        }
    public:
        virtual void play() const = 0;
        virtual void getInfo() const = 0;
        virtual int getDuration() const = 0;
        virtual Media *clone() const = 0;
        virtual ~Media() {
            delete[] title;
        };
};
class Song : public Media{
    private:
        char *artist;
    public:
        Song(const char *t, const char *ar, int dur) : Media(t, dur) {
            artist = new char[strlen(ar) + 1];
            strcpy(artist, ar);
        }
        Song(const Song& other) : Media(other){
            artist = new char[strlen(other.artist) + 1];
            strcpy(artist, other.artist);
        }
        void play() const override {
            std::cout << "Playing song: " << title << " by " << artist << "\n";
        }
        
        void getInfo() const override {
            std::cout << "Song: " << title << ", Artist: " << artist 
                      << ", Duration: " << duration << "s\n";
        }
        Media* clone() const override{
            return new Song(*this);
        }
        int getDuration() const override{
            return duration;
        }
        ~Song(){
            delete[] artist;
        }
};
class Podcast : public Media{
    private:
        char *host;
        int numberOfEpisodes;
    public:
        Podcast(const char *t, const int dur, const char* h, const int noE) : Media(t,dur), numberOfEpisodes(noE){
            host = new char[strlen(h) + 1];
            strcpy(host, h);
        }
        Podcast(const Podcast& other) : Media(other){
            host = new char[strlen(other.host) + 1];
            strcpy(host, other.host);
        }
        void getInfo() const override{
            std::cout << "Podcast: " << title << " with host " << host
                      << " number of episodes and duration " << numberOfEpisodes << "; "
                      << duration << std::endl;
        }
        void play() const override{
            std::cout << "Currently playing: " << title << "with " << host << '\n';
        }
        int getDuration() const override{
            return numberOfEpisodes * duration;
        }
        Media* clone() const override{
            return new Podcast(*this);
        }
        ~Podcast()
        {
            delete[] host;
        }
};
class Playlist{
    private:
        Media **items;
        int size;
    public:
        Playlist(): items(nullptr),size(0) {}
        Playlist(const Playlist& other) : size(other.size){
            items = new Media *[size];
            for (int i = 0; i < size; i++){
                items[i] = other.items[i]->clone();
            }
        }
        Playlist operator=(Playlist& other){
            if(this != &other){
                for (int i = 0; i < size; i++){
                    delete items[i];
                }
                delete[] items;

                size = other.size;
                items = new Media *[size];for (int i = 0; i < size; i++)
                items[i] = other.items[i]->clone();
            }
            return *this;    
        }
        void add(Media* m){
            Media **newArr = new Media *[size + 1];
            for (int i = 0; i < size; i++)
                newArr[i] = items[i];
            newArr[size] = m->clone();
            delete[] items;
            items = newArr;
            size++;
        }
        ~Playlist(){
            for (int i = 0; i < size; i++){
                delete items[i];
            }
            delete[] items;
        }
};