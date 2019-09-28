Class = {}
--Class.__index = Class
--Class = class("shandong")
 
function Class:new(x,y)
    local temp = {}
    setmetatable(temp, Class)
    temp.x = x
    temp.y = y
    Class.__index = Class
    return temp
end
 
function Class:test()
	print("Hello--------------->");
    print(self.x,self.y)
end
 
 
object = Class:new(10,20)
print(object)
print("-----------")
 
object:test()
