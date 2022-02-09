#ifndef _bes_lib_math_complex_cpp_
#define _bes_lib_math_complex_cpp_
#include <string>
#include "base.cpp"
namespace bes{
    namespace math{
        template <class field>
        class complex{
        public:
            field RE;
            field IM;
            field re(void);
            field im(void);
            complex(complex<field>&);
            complex(field,field);
            complex(field);
            complex<field> operator+(complex<field>);
            complex<field> operator-(complex<field>);
            complex<field> operator*(complex<field>);
            complex<field> operator/(complex<field>);
            complex<field> operator+(field);
            complex<field> operator-(field);
            complex<field> operator*(field);
            complex<field> operator/(field);
            complex<field> operator=(complex<field>);
            complex<field> operator=(field);
            bool operator==(complex<field>);
            complex<field> operator!(void);
            operator std::string (void);
        };
        template <class field> field complex<field>::re(void){
            return RE;
        }
        template <class field> field complex<field>::im(void){
            return IM;
        }
        template <class field> complex<field>::complex(complex<field>&input){
            RE=input.RE;
            IM=input.IM;
        }
        template <class field> complex<field>::complex(field re,field im){
            RE=re;
            IM=im;
        }
        template <class field> complex<field>::complex(field re){
            RE=re;
        }
        template <class field> complex<field> complex<field>::operator+(complex<field> input){
            complex<field> ret(RE+input.RE,IM+input.IM);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator-(complex<field> input){
            complex<field> ret(RE-input.RE,IM-input.IM);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator*(complex<field> input){
            complex<field> ret(RE*input.RE-IM*input.IM,RE*input.IM+IM*input.RE);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator/(complex<field> input){
            field mid=RE*input.RE+IM*input.IM;
            complex<field> ret((RE*input.RE-IM*input.IM)/mid,(IM*input.RE-RE*input.IM)/mid);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator+(field input){
            complex<field> ret(RE+input,IM);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator-(field input){
            complex<field> ret(RE-input,IM);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator*(field input){
            complex<field> ret(RE*input,IM*input);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator/(field input){
            complex<field> ret(RE/input,IM/input);
            return ret;
        }
        template <class field> complex<field> complex<field>::operator=(complex<field> input){
            RE=input.RE;
            IM=input.IM;
            return input;
        }
        template <class field> complex<field> complex<field>::operator=(field input){
            RE=input;
            return input;
        }
        template <class field> complex<field> complex<field>::operator!(){
            complex ret(RE,-IM);
            return ret;
        }
        template <class field> bool complex<field>::operator==(complex<field> input){
            return (RE==input.RE && IM==input.IM);
        }
        template <class field> complex<field>::operator std::string(void){
            return (std::string) RE+" + "+(std::string) IM+"j";
        }
    }
}
#endif
