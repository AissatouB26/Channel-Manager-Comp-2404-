#include "Search.h"
//Search Function
ostream& operator<<(ostream& ost, const Search& s){
    s.print(ost);
    return ost;
};

//O_Search Functions
O_Search::O_Search(string owner){
    this->owner = owner;
}

bool O_Search::matches(const Media* m) const{
    if(m == nullptr) return false;
    if(m->getOwner() == owner) return true;
    return false;
}

void O_Search::print(ostream& ost) const{
    ost << "This media belongs to " << owner << endl;
}

//C_Search Functions
C_Search::C_Search(string category){
    this->category = category;
}

bool C_Search::matches(const Media* m) const{
    if(m == nullptr) return false;
    if(m->getCategory() == category) return true;
    return false;
}

void C_Search::print(ostream& ost) const{
    ost << "This media matches the  " << category << " category" << endl;
}

//OorC_Search Functions
bool OorC_Search::matches(const Media* m) const{
    if(m == nullptr) return false;
    if(m->getCategory() == getCategory() || m->getOwner() == getOwner()){
        return true;
    }
    return false;
} 

void OorC_Search::print(ostream& ost) const{
    ost << "This media either belongs to " << getOwner() 
        << " or matches the " << getCategory() << " category." << endl;
}