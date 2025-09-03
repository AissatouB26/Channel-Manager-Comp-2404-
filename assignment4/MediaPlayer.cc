#include "MediaPlayer.h"
#include "fstream"

//MediaPlayer Functions
MediaPlayer& operator<<( MediaPlayer& player, const Media& m){
    player.play(cout, m);
    return player;
}

//AudioPlayer Functions
void AudioPlayer::play(ostream& ost, const Media& m) const{
    ost << m.getAudioContent() << endl;
}

//VideoPlayer
void VideoPlayer::play(ostream& ost, const Media& m) const{
    ost << m.getAudioContent() << endl;
    
    //Code that opens the file, reads it, then closes it
    string text;
    ifstream MyReadFile(m.getVideoFile());

    if(!MyReadFile.is_open()){
        ost << "Error, could not open video file: " << m.getVideoFile() << endl;
        return;
    }
    while(getline(MyReadFile, text)){
        cout << text;
    }

    MyReadFile.close();
    
}