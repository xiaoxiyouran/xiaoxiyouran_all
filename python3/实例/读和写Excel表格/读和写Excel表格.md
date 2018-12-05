# 读和写Excel表格

一个简单的例子， 用的是 python 3.5, 需要安装两个包：

```python
import xlrd


workbook = xlrd.open_workbook('01.xlsx')
print(workbook.sheet_names())                  #查看所有sheet
booksheet = workbook.sheet_by_index(0)         #用索引取第一个sheet
# booksheet = workbook.sheet_by_name('Sheet 1')  #或用名称取sheet
#读单元格数据
# cell_11 = booksheet.cell_value(0,0)
# cell_21 = booksheet.cell_value(1,0)
#读一行数据
# row_3 = booksheet.row_values(2)
# print(cell_11, cell_21, row_3)

# for i in range(4):


allLines = []
# 每一行的数据
for i in range(4):
    row = booksheet.row_values(i+1)

    cols = []
    for cell in row:
        value = cell.split('\n');
        print(value)
        cols.append(value)

    for r_index in range(len(cols[0])):
        oneline = []
        for c_index in range(len(cols)):
            oneline.append(cols[c_index][r_index])
        allLines.append(oneline)





from openpyxl import Workbook

workbook = Workbook()
booksheet = workbook.active  # 获取当前活跃的sheet,默认是第一个sheet
# 存第一行单元格cell(1,1)
# booksheet.cell(1, 1).value = 6  # 这个方法索引从1开始
# booksheet.cell("B1").value = 7
# 存一行数据
# booksheet.append([11, 87])
for i in range(len(allLines)):
    booksheet.append(allLines[i])

workbook.save("test_openpyxl.xlsx")
```

