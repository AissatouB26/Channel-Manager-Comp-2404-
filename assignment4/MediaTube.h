#ifndef MEDIATUBE_H
#define MEDIATUBE_H

#include "defs.h"
#include "Array.h"
#include "Media.h"
#include "Channel.h"
#include "Search.h"

class MediaTube{
    private:
        Array<Channel*> channels;

    public:
        void addChannel(Channel* c);
        void addMedia(Media* m, string& channelTitle);

        Array<Channel*>& getChannels();
        Channel* getChannel(int index);
        Channel* getChannel(string& title);

        void getMedia(const Search&, Array<Media*>&);
};

#endif