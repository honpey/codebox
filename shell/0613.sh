#!/bin/bash

# play with sed 
var=1

if (( $var == 1 )) 
then
	printf "hello %s, you number is %d\n" "xiaoming" 12
fi

## sed awk are very important tools in shell
## let's learn regexsession first

# sed 中也有和awk相似的用法, 即按照模式选择某一行
# sed -e "/***/ ***" file
# 比如: sed -e "/123\s45/ s/45/@45/g" info

# 发现了这么一条sed命令
# sed -e 's/([ \t(])(__user|__force|__iomem)[ \t]/\1/g'




