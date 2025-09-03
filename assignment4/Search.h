#ifndef SEARCH_H
#define SEARCH_H

#include "defs.h"
#include "Media.h"

class Search{
    public:
       virtual bool matches(const Media* m) const = 0;
       virtual void print(ostream& ost) const = 0;
       friend ostream& operator<<(ostream& ost, const Search& s);

};

class O_Search : virtual public Search{
    private:
        string owner;
    
    public:
        O_Search(string owner);

        bool matches(const Media* m) const override;
        void print(ostream& ost) const override;

        string getOwner() const{return owner;} 
};

class C_Search : virtual public Search{
    private:
        string category;
    
    public:
        C_Search(string category);

        bool matches(const Media* m) const override;
        void print(ostream& ost) const override;

        string getCategory() const {return category;}
};

class OorC_Search : public O_Search, public C_Search{
    public:
        OorC_Search(string owner, string category) 
            : O_Search(owner), C_Search(category){}
        
        bool matches(const Media* m) const override;
        void print(ostream& ost) const override;

};

#endif