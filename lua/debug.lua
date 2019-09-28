gval1=100
function foo()
	local var2 = 10
	function bar()
		debug.debug()
		return val2
	end
	bar()
end

debug.debug()
foo()
