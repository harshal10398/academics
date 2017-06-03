from xlrd import open_workbook
wb = open_workbook('data.xls')
# for s in wb.sheets():
#     print ('Sheet:',s.name)

print(wb.sheets()[4].name)
s=wb.sheets()[4]
print('s.nrows: ', s.nrows)
values=[]
for row in range(5,100):# range(s.nrows):
	col_value=[]

	for col in range(7,7+3): #range (s.ncols):
		value = (s.cell(row,col).value)
		#print (value)
		try : value = str(int(value))
		except : pass
		col_value.append(value)
		#print (col_value)
	#values.append(col_value)
	print(col_value, s.cell(row,11).value)

#print(values)

#    values = []
#    for row in range(s.nrows):
#         col_value = []
#         for col in range(s.ncols):
#             value  = (s.cell(row,col).value)
#             try : value = str(int(value))
#             except : pass
#             col_value.append(value)
#         values.append(col_value)
# print (values)