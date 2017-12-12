function myfunction(a, b)
	print "Enter myfunction"
	print("a+b: ", a+b)
	print("c.a.b", c.a.b)
end

function myerrorhandler(err)
	print("Err:",err)
end

local M = {}
M.func = function() 
	print("hello world")
end
setmetatable(M, {
	__call = function () 
		print("setmetaTable")
	end
})
status=xpcall(myfunction, debug.traceback, 1, 2)
print(status)
M:func()
M()
