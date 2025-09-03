#include "Channel.h"

Channel:: Channel(string title, string owner){
    this->title = title;
    this->owner = owner;
}

bool Channel::equals(const string& title){
    if(this->title == title){
        return true;
    }
    return false;
}

Media* Channel::get(int index) const{
    if(channel[index]){
        return channel[index];
    }
    else{
        exit(1);
    }
}

void Channel::print(ostream& ost) const{
    ost << "Channel Name: " << title << '\n'
        << "Owner: " << owner << endl;
}

void Channel::printWithMedia(ostream& ost) const{
    print(ost);
    for(int i = 0; i < getSize(); i++){
        get(i)->print(ost);
    }
}

Channel& Channel::add(Media* m){
    if(m == nullptr){
        return *this;
    }

    channel += m;
    return *this;
}

ostream& operator<<(ostream& ost,const Channel& c){
    c.print(ost);
    return ost;
}