#ifndef CHANNEL_H
#define CHANNEL_H

#include "Media.h"
#include "Array.h"
#include "defs.h"

class Channel{
    private:
        Array<Media*> channel;
        string title, owner;

    public:
        Channel(string title, string owner);
        bool equals(const string& title);
        Media* get(int index) const;
        int getSize() const {return channel.getSize();}
        void print(ostream&) const;
        void printWithMedia(ostream&) const;
        Channel& add(Media*);
        friend ostream& operator<<(ostream& ost,const Channel& c);
        string getTitle(){return title;}

};

#endif