#include <iostream>
#include <string>
using namespace std;

// This class holds the characteristics of a song input (song title + song artist)
class song
{

private:
    // Set up two private member varibales to store the value from the input string.
    std::string song_name;
    std::string song_artist;

public:
    // constructor
    song(){

    };

    // destructor
    ~song()
    {
        song_name = "";
        song_artist = "";
    };

    // placeInput member function --> update the new input strings into the variables
    void placeInput(std::string title, std::string artist)
    {
        song_name = title;
        song_artist = artist;
    }

    // getSongName --> get the current song name
    std::string getSongName()
    {
        return this->song_name;
    }

    // getSongArtist --> get the current artist name
    std::string getSongArtist()
    {
        return this->song_artist;
    }
};

// Playlist class contains all the implementing member variables and functions we need to make the song list.
class playList
{

//arrSize--fixed size, songNum--dynamically changing size
private:
    int arrSize;
    int songNum = 0;

public:
    song *songList;

    //constructor 
    playList()
    {
        songList = new song[0];
    };

    //destructor
    ~playList()
    {
        arrSize = 0;
        songNum = 0;
        delete[] songList;
        songList = nullptr;
    };

    //set up the size of playlist (command m)
    void setPlaylist(int intput_N)
    {
        arrSize = intput_N;
        //Make sure ther size is greater than 0.
        if (arrSize >= 0)
        {
            songList = new song[arrSize];
            cout << "success" << endl;
        }
    };

    //play song at nth position(command p)
    void playSong(int input_num)
    {
        int index = input_num;
        //can not play if it goes beyond the array size
        if (index > (arrSize - 1))
        {
            cout << "can not play " << index << endl;
        }
        else
        {
            std::string currentPlay = songList[index].getSongName();
            std::string currentArtist = songList[index].getSongArtist();
            //check if the index position is not empty. 
            if (notEmpty(index) == true)
            {
                cout << "played " << index << ' ' << currentPlay << ";" << currentArtist << endl;
            }
            //if it is empty, the song cannot be played.
            else
            {
                cout << "can not play " << index << endl;
            }
        }
    };

    //insert song at the nth position(command i)
    void insertSong(string s_in, string a_in)
    {
        //check the restricted entry, if so, can not insert into the song list.
        if ((s_in == "Mustkrat Love" && a_in == "Captain and Tennille") || (s_in == "My Heart Will Go On") || (same_song(s_in, a_in)))
        {
            cout << "can not insert " << s_in << ";" << a_in << endl;
        }
        else
        {
            //if the list is not full, insert the song at the end of the list.
            if (songNum <= arrSize - 1)
            {
                songList[songNum].placeInput(s_in, a_in);
                cout << "success" << endl;
                songNum += 1;
            }
            //if the list is full, cannot insert.
            else if (songNum > arrSize - 1)
            {
                cout << "can not insert " << s_in << ";" << a_in << endl;
            }
        }

        // cout << songNum <<endl;
        // cout << arrSize << endl;
    };

    //erase song at nth position
    void eraseSong(const int input_pos)
    {
        //if it is empty at the location, can not erase any song.
        if (notEmpty(input_pos) == false)
        {
            cout << "can not erase " << input_pos << endl;
        }
        //if the input index is larger than the array size, cannot erase any song.
        else if (input_pos >= songNum)
        {
            cout << "can not erase " << input_pos << endl;
        }
        else
        {
            int temp = input_pos;
            for (int i = 0; i < songNum - input_pos - 1; ++i)
            {
                songList[temp] = songList[temp + 1];
                temp += 1;
            }
            songList[songNum - 1].placeInput("", "");
            songNum = songNum - 1;
            cout << "success" << endl;
        }
    };

    /*helper function
    1. Make sure the same song does not get inserted;
    2. Make sure there is song to play at the index position;
    **/
    bool same_song(string s, string a)
    {
        std::string inputSong = s;
        std::string inputArtist = a;

        for (int i = 0; i < this->arrSize; i++)
        {
            if (songList[i].getSongName() == inputSong && songList[i].getSongArtist() == inputArtist)
            {
                return true;
            }
        }
        return false;
    };

    bool notEmpty(int n)
    {
        if (songList[n].getSongName() != "" && songList[n].getSongArtist() != "")
        {
            return true;
        }
        return false;
    };
};

// Diriving Code
int main()
{

    std::string instruction; //variable that takes in the command
    bool inputLineBreak = cin.eof(); //check if the input line has ended

    while (!inputLineBreak)
    {

        getline(cin, instruction);
        playList songList; //create an object

        if (instruction.substr(0, 1) == "m")
        {
            int max_entry = stoi(instruction.substr(2, string::npos));
            songList.setPlaylist(max_entry);

            while (getline(cin, instruction))
            {
                if (instruction.substr(0, 1) == "i")
                {
                    songList.insertSong(instruction.substr(2, instruction.find(";") - 2), instruction.substr(instruction.find(";") + 1, string::npos));
                }
                else if (instruction.substr(0, 1) == "p")
                {
                    int play_entry = stoi(instruction.substr(2, string::npos));
                    songList.playSong(play_entry);
                }
                else if (instruction.substr(0, 1) == "e")
                {
                    int erase_entry = stoi(instruction.substr(2, string::npos));
                    songList.eraseSong(erase_entry);
                }
                else if(instruction.length() == 0){
                    songList.~playList();
                    exit(0);
                    break;
                }
            }
        }
    }
}
