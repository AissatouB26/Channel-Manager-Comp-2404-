#include "Media.h"

Media:: Media(string channelTitle, string owner, string mediaTitle, string category, 
    string audioContent, string videoFile){
        this->channelTitle = channelTitle;
        this->owner = owner;
        this->mediaTitle = mediaTitle;
        this->category = category;
        this->audioContent = audioContent;
        this->videoFile = videoFile;
}

void Media::print(ostream& ost) const{
    ost << "Channel Title: " << channelTitle << "\n"
        << "Owner: " << owner << "\n"
        << "Media Title: " << mediaTitle << endl;
}

ostream& operator<<(ostream& ost, const Media& m){
    m.print(ost);
    return ost;
}; 