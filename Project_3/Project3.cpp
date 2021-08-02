#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <unordered_map>
#include <map>
#include <set>
#include <chrono>
using namespace std;


int main(){
    cout << "\n" << "Billboard Top100 Music Map by Chidiogo Onoh " << "\n" << "\n";
    cout << "This program takes in a .csv of all songs on the Billboard Top100 from 1999 to 2019." << endl;
    cout << "Each song has an artist, a title, an amount of weeks x it was on the Billboard Top100, and a rank y how high it was ranked on the Billboard Top100" << endl;
    cout << "**Songs with number of weeks and rank N/A were assigned as -1" << endl;
    cout << "\n" << "\n";
    cout << "Loading..." << endl;

    unordered_multimap<string,string> Artist_Song;
    unordered_multimap<int,string> Weeks_Song;
    unordered_multimap<int,string> Ranks_Song;

    multimap<string,string> Artist_Song2;
    multimap<int,string> Weeks_Song2;
    multimap<int,string> Ranks_Song2;

    ifstream CSV;
    CSV.open("../Project_3/cmake-build-debug/billboardHot100_1999-2019 copy 2.csv");
    if (!CSV.is_open()) {
        cout << "Could not open file CSV." << endl;
        return 1;
    }
    string dataLine, testLine;
    getline(CSV, testLine);

    //cout << testLine << "\n" << dataLine << endl;
    string artist, song, rank, weeks, songBy;
    int numWeeks, numRank;

//    pair<string,string> artist_song; //find the number of unique songs an artist has had on the list, return each song
//    pair<int,string> numWeeks_song; //input x number, return songs that have been on the list for that many weeks
//    pair<int,string> numRank_song; // input x number, return songs that have ranked that high on the list

    while(!CSV.eof()){
        getline(CSV, dataLine);
        dataLine.erase(0, dataLine.find(',') + 1);
        artist = dataLine.substr(0, dataLine.find(","));

        dataLine.erase(0, dataLine.find(",") +1);

        song = dataLine.substr(0, dataLine.find(","));

        dataLine.erase(0, dataLine.find(",")+1);
        dataLine.erase(0, dataLine.find(",")+1);

        rank = dataLine.substr(0, dataLine.find(","));
        numRank = stoi(rank);
        dataLine.erase(0, dataLine.find(",") +1);
        weeks = dataLine.substr(0, dataLine.find(","));
        numWeeks = stoi(weeks);

        //cout << artist << song <<numRank <<numWeeks << endl;
//        artist_song = make_pair(artist,song);
//        test.push_back(artist_song);
//        numWeeks_song = make_pair(numWeeks,song);
//        numRank_song = make_pair(numRank, song);
        dataLine.erase(0, dataLine.length());
        songBy = song;
        songBy.append(", by ");
        songBy.append(artist);

        Artist_Song.insert(make_pair(artist,song));
        Weeks_Song.insert(make_pair(numWeeks,songBy));
        Ranks_Song.insert(make_pair(numRank,songBy));

        Artist_Song2.insert(make_pair(artist,song));
        Weeks_Song2.insert(make_pair(numWeeks,songBy));
        Ranks_Song2.insert(make_pair(numRank,songBy));
    }
    cout << "Ready!" << endl;
    cout << "Menu: " << "\n" << "1. Input an artist's name to return all unique songs they have had on the Billboard Top100, using an unordered multimap" << endl;
    cout << "2. Input an artist's name to return all unique songs they have had on the Billboard Top100, using a multimap" << endl;
    cout << "3. Input a number x to return all unique songs that have been on the Billboard Top100 for that many weeks in a row, using an uordered multimap" << endl;
    cout << "4. Input a number x to return all unique songs that have been on the Billboard Top100 for that many weeks in a row, using a multimap" << endl;
    cout << "5. Input a number y to return all unique songs that have ranked that high on the Billboard Top100, using an unordered multimap" << endl;
    cout << "6. Input a number y to return all unique songs that have ranked that high on the Billboard Top100, using a multimap" << endl;


    int command;
    cin >> command;
    string name;
    set<string> songNames;
    int v;
    int num;

    using namespace std::chrono;
    high_resolution_clock::time_point t1;// = high_resolution_clock::now();

    high_resolution_clock::time_point t2;// = high_resolution_clock::now();
    duration<double> time_span;// = duration_cast<duration<double>>(t2 - t1);

    while(command != 0){ //press any key to continue, press 0 to quit
        switch(command){
            case 1: // search artist name for all songs on billboard unordered multimap
            cin.ignore();
            getline(cin,name);
            using namespace std::chrono;
            t1 = high_resolution_clock::now();
            for(auto& x: Artist_Song){
                if(x.first == name){
                    songNames.insert(x.second);
                    v++;
                }
            }
            cout << name << " has had " << songNames.size() << " unique songs on the Billboard Top100: " << endl;
            v = 0;
            for (auto x : songNames){
                cout << x << endl;
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "Unordered Multimap elapsed time: " << time_span.count() << " seconds." << endl;
            songNames.clear();
            cout << "Press any key to continue or 0 to quit" << endl;
            cin >> command;
            break;

            case 2: ; // search artist name for all songs on billboard using multimap
            cin.ignore();
            getline(cin,name);
            using namespace std::chrono;
            t1 = high_resolution_clock::now();
            for(auto& x: Artist_Song2){
                if(x.first == name){
                    songNames.insert(x.second);
                    v++;
                }
            }
            cout << name << " has had " << songNames.size() << " unique songs on the Billboard Top100: " << endl;
            v = 0;
            for (auto x : songNames){
                cout << x << endl;
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "Multimap elapsed time: " << time_span.count() << " seconds." << endl;
            songNames.clear();
            cout << "Press any key to continue or 0 to quit" << endl;
            cin >> command;
            break;

            case 3: //input number, return all songs that have been up for that many weeks using unordered multimap
            cin.ignore();
            cin >> num;
            using namespace std::chrono;
            t1 = high_resolution_clock::now();
            for(auto&x : Weeks_Song){
                if(x.first == num){
                    songNames.insert(x.second);
                    v++;
                }
            }
            cout << songNames.size() << " songs have been on the Billboard Top100 for " << num << " weeks: " << endl;
            v = 0;
            for(auto x : songNames){
                cout << x << endl;
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "Unordered Multimap elapsed time: " << time_span.count() << " seconds." << endl;
            songNames.clear();
            cout << "Press any key to continue or 0 to quit" << endl;
            cin >> command;
            break;

            case 4: //input number, return all songs that have been up for that many weeks using multimap
            cin.ignore();
            cin >> num;
            using namespace std::chrono;
            t1 = high_resolution_clock::now();
            for(auto&x : Weeks_Song2){
                if(x.first == num){
                    songNames.insert(x.second);
                    v++;
                }
            }
            cout << songNames.size() << " songs have been on the Billboard Top100 for " << num << " weeks: " << endl;
            v = 0;
            for(auto x : songNames){
                cout << x << endl;
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "Multimap elapsed time: " << time_span.count() << " seconds." << endl;
            songNames.clear();
            cout << "Press any key to continue or 0 to quit" << endl;
            cin >> command;
            break;

            case 5: // input number, return all songs that have been up at that rank, using unordered multimap
            cin.ignore();
            cin >> num;
            using namespace std::chrono;
            t1 = high_resolution_clock::now();
            for(auto&x : Ranks_Song){
                if(x.first == num){
                    songNames.insert(x.second);
                    v++;
                }
            }
            cout << songNames.size() << " songs have been ranked " << num << " on the Billboard Top100: " << endl;
            v = 0;
            for(auto x : songNames){
                cout << x << endl;
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "Unordered Multimap elapsed time: " << time_span.count() << " seconds." << endl;
            songNames.clear();
            cout << "Press any key to continue or 0 to quit" << endl;
            cin >> command;
            break;

            case 6: // input number, return all songs that have been up at that rank, using multimap
            cin.ignore();
            cin >> num;
            using namespace std::chrono;
            t1 = high_resolution_clock::now();
            for(auto&x : Ranks_Song2){
                if(x.first == num){
                    songNames.insert(x.second);
                    v++;
                }
            }
            cout << songNames.size() << " songs have been ranked " << num << " on the Billboard Top100: " << endl;
            v = 0;
            for(auto x : songNames){
                cout << x << endl;
            }
            t2 = high_resolution_clock::now();
            time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "Multimap elapsed time: " << time_span.count() << " seconds." << endl;
            songNames.clear();
            cout << "Press any key to continue or 0 to quit" << endl;
            cin >> command;
            break;
        }
    }

    return 0;
}