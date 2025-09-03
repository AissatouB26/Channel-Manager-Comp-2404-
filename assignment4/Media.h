#ifndef MEDIA_H
#define MEDIA_H

#include "defs.h"
#include <iostream>

using namespace std;

class Media{
    private:
        string channelTitle, owner, mediaTitle, category, 
            audioContent, videoFile;
    public:
        Media(string channelTitle, string owner, string mediaTitle, string category, 
            string audioContent, string videoFile);
        virtual void print(ostream& ost) const;
        string getChannelTitle() const {return channelTitle;}
        string getOwner() const {return owner;}
        string getMediaTitle() const {return mediaTitle;}
        string getCategory() const {return category;}
        string getAudioContent() const {return audioContent;}
        string getVideoFile() const {return videoFile;}
        friend ostream& operator<<(ostream& ost, const Media& m);
};



#endif