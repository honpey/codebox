#!/bin/bash

# 要求: 某文档中每一行都包含 A="SP90 alpha inhibitor", 去除下面模式的行:
# 1): A前一个字符不是空格的行
# 2): A前一个字符是空格, 但是不是字符';'

# 方案1:
cat alpha.txt | sed "/[^ ]SP90 alpha inhibitor/d" | sed "/[^;] SP90 alpha inhibitor/d"

# 方案2:
# 上面的两个sed相当于两个awk的条件, 两个条件在正则中可以使用小括号归一
cat alpha.txt | sed "/\([^ ]\|[^;] \)SP90 alpha inhibitor/d"

#Attention: sed中小括号的转义


