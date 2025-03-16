#include <iostream>
using namespace std;

class MediaFile {
public:
    string path;
    string size;
    bool isPlay;

    MediaFile(string p, string s, bool iP) : path(p), size(s), isPlay(iP) {}
    
    void play() {
        cout << "Play()" << endl;
        isPlay = true;
    }
    
    void stop() {
        cout << "stop()" << endl;
        isPlay = false;
    }
};

class VisualMedia : public virtual MediaFile {  // Virtual inheritance
public:
    string res;
    VisualMedia(string p, string s, bool iP, string r) 
        : MediaFile(p, s, iP), res(r) {}
};

class AudioMedia : public virtual MediaFile {  // Virtual inheritance
public:
    int soundIntensity;
    
    AudioMedia(string p, string s, bool iP, int SI) 
        : MediaFile(p, s, iP), soundIntensity(SI) {}
};

class Images : public VisualMedia {
public:
    string type;
    
    Images(string p, string s, bool iP, string r, string t) 
        : MediaFile(p, s, iP), VisualMedia(p, s, iP, r), type(t) {}
};

class Audio : public AudioMedia {
public:
    int speed;
    
    Audio(string p, string s, bool iP, int SI, int spd) 
        : MediaFile(p, s, iP), AudioMedia(p, s, iP, SI), speed(spd) {}
};

class Videos : public VisualMedia, public AudioMedia {
public:
    bool subTitle;
    int speed;
    
    Videos(string p, string s, bool iP, string res, int SI, int spd, bool sub) 
        : MediaFile(p, s, iP),
          VisualMedia(p, s, iP, res),
          AudioMedia(p, s, iP, SI),
          speed(spd), subTitle(sub) {}
};

int main() {
    Images img("img.jpg", "2MB", false, "1080p", "PNG");
    Audio aud("song.mp3", "5MB", false, 44100, 1);
    Videos vid("movie.mp4", "1GB", false, "4K", 48000, 1, true);
    
    return 0;
}
