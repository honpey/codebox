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

#--------------------------------------#
#  ------   sed高级用法 --------       #
#--------------------------------------#

# 数据库中经常会有这样的操作: create table XXXXX
# 使用sed把所有的 XXXXX 变成 XXXXX_20160628

# 方案1:(比较菜鸟, 只是用到了基本的\1的替换的功能 )
# sed -r "s/create table 
#             ([0-9a-zA-z])/create table \1_20160628/g" table.txt

# 方案2: (提前对这样的行做了一个筛选)
sed '/create table .*/s/ (/_20160628 (/' table.txt


# 方案3:
sed -r 's/create table \w+/&_20160628/' table.txt


