#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "defs.h"
#include "Media.h"

class MediaPlayer{
    public:
        virtual void play(ostream& ost, const Media& m) const = 0;
        friend MediaPlayer& operator<<( MediaPlayer& player, const Media& m);

};

class AudioPlayer : public MediaPlayer{
    public:
        void play(ostream& ost, const Media& m) const override;
};

class VideoPlayer : public AudioPlayer{
    public:
        void play(ostream& ost, const Media& m) const override;

};
#endif