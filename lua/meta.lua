other = function(t,k) if k=="foo" then return 1212 end end
t = setmetatable({}, { __index = other })
print(t.foo)
