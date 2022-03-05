#ifndef _bes_lib_lib_str_map_cpp_
#define _bes_lib_lib_str_map_cpp_
#include "allocator.hpp"
namespace bes {
	namespace lib {
		namespace lib {
			namespace funcs {
				size_t getstrlen(char* str) {
					size_t ret = 0;
					while (str[ret] != 0)ret++;
					return ret;
				}
				void strcpy(char* str1, char* str2, size_t strlen) {
					for (size_t i = 0; i < strlen; i++) {
						str1[i] = str2[i];
					}
					return;
				}
			}
			class _string;
			class _conststring; // only read
			class _string {
			private:
				_allocator self;
			public:
				char* cstr;
				size_t length;
				_string(void) {
					cstr = (char *)self.ptr;
					length = 0;
					return;
				}
				_string(char *str) {
					length = funcs::getstrlen(str);
					self.resize(length);
					cstr = (char*)self.ptr;
					funcs::strcpy(cstr, str, length); 
					return;
				}
				_string(char* str, size_t len) {
					length = len;
					self.resize(length);
					cstr = (char*)self.ptr;
					funcs::strcpy(cstr, str, length);
					return;
				}
				char* c_str(void);
				char& operator[](size_t index) {
					return cstr[index];
				}
				_string& operator=(_string str) {
					self.resize(str.length);
					length = str.length;
					cstr = (char *)self.ptr;
					funcs::strcpy(cstr, str.cstr,str.length);
					return str;
				}
				size_t size(void) {
					return length;
				}
				size_t size_of(void) {
					return length;
				}
			};
		}
	}
}
#endif