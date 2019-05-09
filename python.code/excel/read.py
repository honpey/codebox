#-*- coding=utf-8 -*-
import os
import xlrd, xlwt

iDict={
        u"简历渠道":-1,
        u"渠道明细":-1,
        u"姓名":-1,
        u"性别":-1,
        u"电话号码":-1,
        u"邮箱":-1,
        u"QQ号码":-1,
        u"照片":-1,
        u"出生年":-1,
        u"出生月":-1,
        u"出生日":-1,
        u"身份证号":-1,
        u"年龄":-1,
        u"最高学历":-1,
        u"毕业学校":-1,
        u"专业":-1,
        u"毕业时间":-1,
        u"居住现状":-1,
        u"自我介绍":-1,
        u"籍贯-省":-1,
        u"籍贯-市":-1,
        u"籍贯-区/县":-1,
        u"籍贯街道":-1,
        u"现居住地-省":-1,
        u"现居住地-市":-1,
        u"现居住地-区/县":-1,
        u"婚姻状况":-1,
        u"期望行业":-1,
        u"期望薪资":-1,
        u"期望职位":-1,
        u"期望地点-省":-1,
        u"期望地点-市":-1,
        u"期望地点-区/县":-1,
        u"期望地点-街道":-1,
        u"开始时间":-1,
        u"结束时间":-1,
        u"学校":-1,
        u"学院":-1,
        u"专业":-1,
        u"学历":-1,
        u"教育类型":-1,
        u"证明老师姓名":-1,
        u"证明老师电话":-1,
        u"学校地点-省":-1,
        u"学校地点-市":-1,
        u"学校地点-区/县":-1,
        u"学校地点-街道":-1,
        u"工作类型":-1,
        u"开始时间":-1,
        u"结束时间":-1,
        u"公司全称":-1,
        u"公司简称":-1,
        u"企业规模":-1,
        u"企业行业":-1,
        u"企业性质":-1,
        u"部门":-1,
        u"岗位名称":-1,
        u"岗位性质":-1,
        u"岗位类别":-1,
        u"岗位级别":-1,
        u"下属人数":-1,
        u"工作职责":-1,
        u"工作成绩":-1,
        u"底薪":-1,
        u"提成":-1,
        u"作息类型":-1,
        u"离职原因":-1,
        u"工作地(省)":-1,
        u"工作地(市)":-1,
        u"工作地(区/县)":-1,
        u"证明人":-1,
        u"证明人电话":-1,
        u"开始时间":-1,
        u"结束时间":-1,
        u"项目名称":-1,
        u"项目简介":-1,
        u"项目人数":-1,
        u"担任角色":-1,
        u"项目公司":-1,
        u"项目职责":-1,
        u"项目成绩":-1,
        u"语种":-1,
        u"证书级别":-1,
        u"描述":-1,
        u"证书/荣誉名称":-1,
        u"获得年月":-1,
        u"授予机构":-1,
        u"描述":-1,
    }


def read_excel():
    data = xlrd.open_workbook("./resume_template_2003.xls") 
    table = data.sheets()[0]
    nrows = table.nrows
    ncols = table.ncols
    print table.row(2)[2].value
    FoundBLine=False
    iset0 = set(map(lambda x:x.value, table.row(1)))

    if u'简历渠道' in iset0 and u'电话号码' in iset0:
        FoundBLine=True
    if FoundBLine:
        for i, value in enumerate(table.row(1)):
            print value.encode('utf-8')," ",i
            iDict[value] = i   
                            
    for key, value in iDict.iteritems():
        print key, value

    return
    # Found the comment info line
    for rownum in xrange(table.nrows):
        iset=set(table.row(rownum))
        
        #for colnum in xrange(table.ncols):
if __name__ == "__main__":
    read_excel()

