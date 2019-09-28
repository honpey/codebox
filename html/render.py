global html
with open("./a.html") as f:
    html = f.read().strip()
print("Pre-------")
print html
print("Pos-------")
print html.format(name="hello")
