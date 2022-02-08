#ifndef _lib_string_kmp_cpp_
#define _lib_string_kmp_cpp_
#include <string>
#include <vector>
namespace bes{
    class KMPstring;
    class KMPstring{
    public:
        std::string self;
        std::vector<unsigned long> pos;
        unsigned long kmplength;
        void bind(void);
        KMPstring(char *);
        KMPstring(std::string);
        std::vector<unsigned long> findall(char *);
        std::vector<unsigned long> findall(std::string);
        bool in(char *);
        bool in(std::string);
        std::vector<std::string> split(char *);
        std::vector<std::string> split(std::string);
        bool operator>(KMPstring);
        bool operator<(KMPstring);
        bool operator==(KMPstring);
        bool operator<=(KMPstring);
        bool operator>=(KMPstring);
        bool operator!=(KMPstring);
        KMPstring operator=(KMPstring);
        std::string operator=(std::string);
        char * operator=(char *);
    };
    void KMPstring::bind(void){
        kmplength=self.length();
        pos.clear();
        pos.push_back(-1);
        for (unsigned long i=1;i<kmplength;i++){
            unsigned long _POS=pos[i-1]+1;
            while(_POS!= -1){

                if (self[i]==self[_POS])break;
                else if (_POS==0)_POS=-1;
                else _POS=pos[_POS-1]+1;
            }
            pos.push_back(_POS);
        }
        return;
    }
    KMPstring::KMPstring(char * str){
        self=str;
        bind();
    }
    KMPstring::KMPstring(std::string str){
        self=str;
        bind();
    }
    std::vector<unsigned long> KMPstring::findall(std::string str){
        std::vector<unsigned long> ret;
        unsigned long _POS=0;
        unsigned long len=str.length();
        for (unsigned int i=0;i<len;){
            if (self[_POS]==str[i]){
                if (_POS==kmplength-1){
                    ret.push_back(i-_POS);
                    _POS=pos[_POS]+1;
                    i++;
                }
                else{
                    _POS++;
                    i++;
                }
            }else{
                if (_POS==0){
                    i++;
                }
                if (_POS!=0){
                    _POS=pos[_POS-1]+1;
                }
            }
        }
        return ret;

    }
    std::vector<unsigned long> KMPstring::findall(char * str){
        std::string _str=str;
        return findall(_str);
    }
    bool KMPstring::in(std::string str){
        unsigned long _POS=0;
        unsigned long len=str.length();
        for (unsigned int i=0;i<len;){
            if (self[_POS]==str[i]){
                if (_POS==kmplength-1){
                    return true;
                    _POS=pos[_POS]+1;
                    i++;
                }
                else{
                    _POS++;
                    i++;
                }
            }else{
                if (_POS==0){
                    i++;
                }
                if (_POS!=0){
                    _POS=pos[_POS-1]+1;
                }
            }
        }
        return false;

    }
    bool KMPstring::in(char * str){
        std::string _str=str;
        return in(_str);
    }
    bool KMPstring::operator>(KMPstring x){
        return self>x.self;
    }
    bool KMPstring::operator<(KMPstring x){
        return self<x.self;
    }
    bool KMPstring::operator==(KMPstring x){
        return self==x.self;
    }
    bool KMPstring::operator<=(KMPstring x){
        return self>=x.self;
    }
    bool KMPstring::operator>=(KMPstring x){
        return self<=x.self;
    }
    bool KMPstring::operator!=(KMPstring x){
        return self!=x.self;
    }
    KMPstring KMPstring::operator=(KMPstring x){
        self=x.self;
        kmplength=x.kmplength;
        pos=x.pos;
        return x;
    }
    std::string KMPstring::operator=(std::string x){
        self=x;
        bind();
        return x;
    }
    char * KMPstring::operator=(char * x){
        self=x;
        bind();
        return x;
    }
}
#endif
