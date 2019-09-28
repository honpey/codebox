# -*- coding=utf-8 -*-
import xlrd
import uuid


class Student():
    def __init__(self, id, **kw):
        self.id = id
        for k, v in kw.items():
            setattr(self, k, v)

    def __str__(self):
        return '%s(id=%s,column1=%s,column2=%s,column3=%s,column4=%s)' \
               % (
                   self.__class__.__name__, self.id, self.column1, self.column2, self.column3,
                   self.column4)


def read_excel():
    workbook = xlrd.open_workbook(r'resume_template_2003.xls')
    print('打印所有sheet:', workbook.sheet_names())

    sheet2 = workbook.sheet_by_index(0)  # sheet索引从0开始
    rows_num = sheet2.nrows
    cols_num = sheet2.ncols
    for r in range(rows_num):
        entity_dict = {}
        for c in range(cols_num):
            cell_value = sheet2.row_values(r)[c]
            if (cell_value is None or cell_value == ''):
                cell_value = (get_merged_cells_value(sheet2, r, c))
                # 构建Entity
            the_key = 'column' + str(c + 1);
            # 动态设置各属性值
            entity_dict[the_key] = cell_value
        entity_dict['id'] = getUUID()
        stu = Student(**entity_dict)
        print(stu)


def get_merged_cells(sheet):
    """
    获取所有的合并单元格，格式如下：
    [(4, 5, 2, 4), (5, 6, 2, 4), (1, 4, 3, 4)]
    (4, 5, 2, 4) 的含义为：行 从下标4开始，到下标5（不包含）  列 从下标2开始，到下标4（不包含），为合并单元格
    :param sheet:
    :return:
    """
    return sheet.merged_cells

def get_merged_cells_value(sheet, row_index, col_index):
    """
    先判断给定的单元格，是否属于合并单元格；
    如果是合并单元格，就返回合并单元格的内容
    :return:
    """
    merged = get_merged_cells(sheet)
    for (rlow, rhigh, clow, chigh) in merged:
        if (row_index >= rlow and row_index < rhigh):
            if (col_index >= clow and col_index < chigh):
                cell_value = sheet.cell_value(rlow, clow)
                # print('该单元格[%d,%d]属于合并单元格，值为[%s]' % (row_index, col_index, cell_value))
                return cell_value
                break
    return None


def getUUID():
    return uuid.uuid1().hex


if __name__ == "__main__":
    read_excel()
