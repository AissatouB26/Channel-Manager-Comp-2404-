#include "MediaTube.h"

void MediaTube::addChannel(Channel* c){
    if(c != nullptr){
        channels += c;
    }
}

void MediaTube::addMedia(Media* m, string& channelTitle){
    if(getChannel(channelTitle) != nullptr){
        getChannel(channelTitle)->add(m);
    }
    else{
        cerr << "Unable to add media to channel" <<endl;
    }
}

Array<Channel*>& MediaTube::getChannels(){
    return channels;
}

Channel* MediaTube::getChannel(int index){
    return channels[index];
}

Channel* MediaTube::getChannel(string& title){
    for(int i = 0; i < channels.getSize(); i++){
        if(channels[i]->getTitle() == title){
            return channels[i];
        }
    }
    return nullptr;
}

void MediaTube::getMedia(const Search& s, Array<Media*>& a){
    for(int i = 0; i < channels.getSize(); i++){
        if(channels[i] == nullptr){ 
            continue;
        } 
        //Checks if each media in each channel matches the search parameters. If yes, add it to the array
        for(int j = 0; j < channels[i]->getSize(); j++){
            if(s.matches(channels[i]->get(j))){
                if(channels[i]->get(j) != nullptr) a += channels[i]->get(j);
            }
        }
    }
}