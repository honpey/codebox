#!/usr/bin/python
class hi():
	def __init__(self, name):
				self.name = name
	def getName(self):
		return self.name

class hi2():
	def __init__(self, name, age):
		self.name = name
		self.age = age
	def setName(self, name):
		def setNameInterl(self, name):
			return name+"Append"
	 	self.name = setNameInterl(self,name)
	def setAge(self, age):
	 	self.age = age
	def getNameAge(self):
		return self.name, self.age
	 
if __name__ == '__main__':
	hello = hi("xioahong")
	print hello.getName()
	hi2E = hi2("xiaohua", 29)
	print hi2E.getNameAge()

	hi2E.setName("xiaohuahua")
	hi2E.setAge(30)
	print hi2E.getNameAge()

	d = {"hello":1, "world":2}
	print d["hello"]
	print d['world']
	print d
