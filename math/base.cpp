#ifndef _bes_lib_math_base_cpp_
#define _bes_lib_math_base_cpp_
#include <string>
namespace bes{
    namespace math{
        class _unsignedlong;
        class _double;
        class _unsignedlong{
            unsigned long self;
            _unsignedlong(unsigned long);
            _unsignedlong(_unsignedlong&);
            inline _unsignedlong operator+(_unsignedlong);
            inline _unsignedlong operator-(_unsignedlong);
            inline _unsignedlong operator*(_unsignedlong);
            inline _unsignedlong operator=(_unsignedlong);
            inline _unsignedlong operator%(_unsignedlong);
            inline _unsignedlong operator/(_unsignedlong);
            inline _unsignedlong operator&(_unsignedlong);
            inline _unsignedlong operator^(_unsignedlong);
            inline _unsignedlong operator|(_unsignedlong);
            inline _unsignedlong operator>>(_unsignedlong);
            inline _unsignedlong operator<<(_unsignedlong);
            inline _unsignedlong operator!(void);
            inline _unsignedlong operator-(void);
            inline bool operator==(_unsignedlong);
            inline bool operator!=(_unsignedlong);
            inline bool operator>(_unsignedlong);
            inline bool operator<(_unsignedlong);
            inline bool operator>=(_unsignedlong);
            inline bool operator<=(_unsignedlong);
            operator std::string(void);
            operator unsigned long(void);
            _unsignedlong get1(void);
        };
        _unsignedlong::_unsignedlong(unsigned long input){self=input;}
        _unsignedlong::_unsignedlong(_unsignedlong &input){self=input.self;}
        inline _unsignedlong _unsignedlong::operator+(_unsignedlong input){_unsignedlong ret(self+input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator-(_unsignedlong input){_unsignedlong ret(self-input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator*(_unsignedlong input){_unsignedlong ret(self*input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator/(_unsignedlong input){_unsignedlong ret(self/input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator%(_unsignedlong input){_unsignedlong ret(self%input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator^(_unsignedlong input){_unsignedlong ret(self^input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator|(_unsignedlong input){_unsignedlong ret(self|input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator&(_unsignedlong input){_unsignedlong ret(self&input.self);return ret;}
        inline _unsignedlong _unsignedlong::operator>>(_unsignedlong input){_unsignedlong ret(self>>(input.self));return ret;}
        inline _unsignedlong _unsignedlong::operator<<(_unsignedlong input){_unsignedlong ret(self<<(input.self));return ret;}
        inline _unsignedlong _unsignedlong::operator!(void){_unsignedlong ret(!self);return ret;}
        inline _unsignedlong _unsignedlong::operator-(void){_unsignedlong ret(-self);return ret;}
        inline bool _unsignedlong::operator==(_unsignedlong input){return self==input.self;};
        inline bool _unsignedlong::operator!=(_unsignedlong input){return self!=input.self;};
        inline bool _unsignedlong::operator>=(_unsignedlong input){return self>=input.self;};
        inline bool _unsignedlong::operator<=(_unsignedlong input){return self<=input.self;};
        inline bool _unsignedlong::operator>(_unsignedlong input){return self>input.self;};
        inline bool _unsignedlong::operator<(_unsignedlong input){return self<input.self;};
        _unsignedlong::operator std::string(void){
            const char num[17]="0123456789abcdef";
            std::string ret;
            unsigned long value=self;
            ret.push_back(num[value>>60]);
            ret.push_back(num[(value>>56)&0xf]);
            ret.push_back(num[(value>>52)&0xf]);
            ret.push_back(num[(value>>48)&0xf]);
            ret.push_back(num[(value>>44)&0xf]);
            ret.push_back(num[(value>>40)&0xf]);
            ret.push_back(num[(value>>36)&0xf]);
            ret.push_back(num[(value>>32)&0xf]);
            ret.push_back(num[(value>>28)&0xf]);
            ret.push_back(num[(value>>24)&0xf]);
            ret.push_back(num[(value>>20)&0xf]);
            ret.push_back(num[(value>>16)&0xf]);
            ret.push_back(num[(value>>12)&0xf]);
            ret.push_back(num[(value>>8)&0xf]);
            ret.push_back(num[(value>>4)&0xf]);
            ret.push_back(num[value&0xf]);
            return ret;
        }
        _unsignedlong::operator unsigned long(void){
            return self;
        }
        _unsignedlong _unsignedlong::get1(void){
            unsigned long table[16]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
            unsigned long cnt=0;
            unsigned long value=self;
            while(value){
                cnt+=table[value&0xf];
                value>>=4;
            }
            _unsignedlong ret(cnt);
            return ret;
        }
    }
}
#endif
