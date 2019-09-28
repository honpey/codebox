local Shape = class("Shape")
 
function Class:hello(x,y)
    self.xx = x
    self.yy = y
end

function Class:Output()
    print("out put")
    print(x, y)
end
 
function Class:test()
	print("Hello--------------->");
    print(self.xx,self.yy)
end
 
Class:hello(1, 2)
Class:Output()
