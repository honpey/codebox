local ffi = require("ffi")
ffi.cdef[[
typedef struct { double x, y; } point_t;
]]
 
param_to_reg = {param1='di', param2='si',param3='dx'}
local point
local mt = {
  __add = function(a, b) return point(a.x+b.x, a.y+b.y) end,
  __len = function(a) return math.sqrt(a.x*a.x + a.y*a.y) end,
  --[[
  __index = {
    area = function(a) return a.x*a.x + a.y*a.y end,
	areaa = function() print("hello world") end,
  },
  --]]
  __index = function(a, key)
  	print("hello world")
  	return assert(param_to_reg[key]--[[, 'no such registryer: '..key--]])
  end,

}
point = ffi.metatype("point_t", mt)
 
local a = point(3, 4)
print(a.x, a.y)  --> 3  4
print(#a)        --> 5
print(a.param1)  --> 25
--print(a())
local b = a + point(0.5, 8)
print(b.x, b.y)
print(#b)        --> 12.5


-- lua中冒号会默认接受self，而点好不会接受
