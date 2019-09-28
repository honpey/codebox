#-*- coding=utf-8 -*-
import os
import xlrd, xlwt
import json
from resume_template import iPos
import resume_basic_info as basic_info
import resume_education_info as edu_info
import resume_experience_info as exp_info
import resume_certification_info as cert_info
import headers

def read_excel():
    filename="./resume_template_2003.xls"
    data = xlrd.open_workbook(filename, formatting_info=True) 
    table = data.sheets()[0]
    headerList = map(lambda x:x.value, table.row(1))
    headerSet = set(headerList)

    # Found the basic info and update the pos
    if u'简历渠道' in headerSet and u'电话号码' in headerSet:
        FoundBLine=True
    else:
        print("This is not a valid Excel")
        return

    #for i, value in enumerate(table.row(1)):
    #        iPos[value] = i
    # Found the comment info line

    # Iterate each row to get the resume items
    # Attention, how to check the combined cells

    for rownum in xrange(2, table.nrows):
        curRowList = map(lambda x:x.value, table.row(rownum))
        phone = curRowList[iPos['PHONE']].strip()
        if not phone == "":
            
        else: 
            print("Not The First Line", phone)

        #for colnum in xrange(table.ncols):
if __name__ == "__main__":
    read_excel()

