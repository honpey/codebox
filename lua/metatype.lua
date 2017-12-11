local ffi = require('ffi')
ffi.cdef [[
struct point {
	uint8_t x;
	uint8_t y;
} __attribute__((packed));
]]
ffi.metatype(ffi.typeof('struct point'), {
	__index = {
		ip = function() print("Comer here"); end,
	}
})

print(ffi.typeof('struct point'))
--ffi.meta
