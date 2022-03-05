#ifndef _bes_lib_lib_allocator_hpp_
#define _bes_lib_lib_allocator_hpp_
#include <stdlib.h>

namespace bes {
	namespace lib {
		namespace lib {
			namespace consts {
				size_t _allocatorsettings[] = { 0x0, 0x0, 0x0,0x1,0xf,0x7f,0x3ff,0x7ff,0xfff,0x1fff,
												0x3fff,0x7fff,0xffff,0x17ffe, 0x23ffd, 0x35ffb, 0x50ff8, 0x797f4, 0xb63ee, 0x1115e5,
												0x19a0d7, 0x267142, 0x39a9e3, 0x567ed4, 0x81be3e, 0xc29d5d, 0x123ec0b, 0x1b5e210,
												0x290d318, 0x3d93ca4, 0x5c5daf6, 0x8a8c871, 0xcfd2ca9, 0x137bc2fd, 0x1d39a47b, 0x2bd676b8,
												0x41c1b214, 0x62a28b1e, 0x93f3d0ad, 0xddedb903, 0x14ce49584, 0x1f356e046, 0x2ed025069,
												0x46383789d, 0x6954534eb, 0x9dfe7cf60, 0xecfdbb710, 0x1637c99298, 0x2153ae5be4, 0x31fd8589d6,
												0x4afc484ec1, 0x707a6c7621, 0xa8b7a2b131, 0xfd137409c9, 0x17b9d2e0ead, 0x2396bc51603,
												0x35621a7a104, 0x501327b7186, 0x781cbb92a49, 0xb42b195bf6d, 0x10e40a609f23, 0x19560f90eeb4,
												0x26011759660e, 0x3901a3061915, 0x55827489259f, 0x8043aecdb86e, 0xc065863494a5, 0x12098494edef7,
												0x1b0e46df64e72, 0x28956a4f175ab, 0x3ce01f76a3080, 0x5b502f31f48c0, 0x88f846caeed20, 0xcd746a30663b0,
												0x1342e9f4899588, 0x1ce45eeece604c, 0x2b568e66359072, 0x4101d5995058ac, 0x6182c065f88500,
												0x92442098f4c780, 0xdb6630e56f2b40, 0x14919495826c0e0, 0x1eda5ee043a2150, 0x2e478e506573200,
												0x456b5578982cb00, 0x68210034e443080, 0x9c31804f5664900, 0xea4a40770196d80, 0x15f6f60b28262400,
												0x20f27110bc393600, 0x316ba9991a55d000, 0x4a217e65a780b800, 0x6f323d987b411400, 0xa6cb5c64b8e1a000,
												0xfa310a9715527000, 0xffffffffffffffff 
											};
			}
			namespace funcs {
				// binary functions;
				template <class T> size_t find_sorted(T key, T* ptr, size_t length) {
					size_t left = 0, right = length - 1;
					if (ptr[right] == key)return right;
					while (left + 1 < right) {
						size_t mid = left + ((right - left) >> 1);
						if (ptr[mid] == key)return mid;
						else if (ptr[mid] > key) {
							right = mid;
						}
						else {
							left = mid;
						}
					}
					return -1;
				}
				template <class T> size_t find_sortedx(T key, T* list, size_t length) {
					size_t left = 0, right = length - 1;
					if (list[right] == key)return right;
					while (left + 1 < right) {
						size_t mid = left + ((right - left) >> 1);
						if (list[mid] == key)return mid;
						else if (list[mid] > key) {
							right = mid;
						}
						else {
							left = mid;
						}
					}
					return left;
				}
				unsigned getfirst1(unsigned x) {
					x = (x & 0xffff0000) ? (x & 0xffff0000) : x;
					x = (x & 0xff00ff00) ? (x & 0xff00ff00) : x;
					x = (x & 0xf0f0f0f0) ? (x & 0xf0f0f0f0) : x;
					x = (x & 0xcccccccc) ? (x & 0xcccccccc) : x;
					x = (x & 0xaaaaaaaa) ? (x & 0xaaaaaaaa) : x;
					return x;
				}
				unsigned pgetlast1(unsigned x) {
					return (x ^ ((!x) + 1));
				}
				unsigned get1(unsigned x) {
					unsigned cnt = 0;
					while (x) {
						++cnt;
						x = x & (x - 1);
					}
					return x;
				}
			}
			class _allocator {
			private:
				size_t real_size;
				size_t memory_list;
			public:
				void* ptr;
				_allocator(void) {
					ptr = malloc(0);
					real_size = 0;
					memory_list = 2;
					return;
				}
				int resize(size_t new_size) {
					if (new_size == 0) {
						free(ptr);
						ptr = malloc(0);
						real_size = 0;
						memory_list = 2;
						return 0;
					}
					if (new_size <= consts::_allocatorsettings[memory_list]) {
						if (new_size >= consts::_allocatorsettings[memory_list - 2]) {
							real_size = new_size;
							return 0;
						}
					}
					// resize;
					size_t new_memory_list =funcs::find_sortedx(new_size, consts::_allocatorsettings, sizeof(consts::_allocatorsettings)/sizeof(size_t))+1;
					memory_list = new_memory_list;
					real_size = new_size;
					void* nptr = realloc(ptr, consts::_allocatorsettings[memory_list]);
					if (nptr == NULL) return -1;
					ptr = nptr;
					return 0;
				}
				inline int upsize(size_t add_size) {
					return resize(add_size+real_size);
				}
				inline int downsize(size_t minus_size) {
					return resize(real_size - minus_size);
				}
				size_t size(void) {
					return real_size;
				}
				size_t size_of(void) {
					return consts::_allocatorsettings[memory_list];
				}
			};
		}
	}
}
#endif // !_bes_lib_lib_allocator_cpp_