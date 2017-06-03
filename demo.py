from sklearn import tree
from xlrd import open_workbook

wb = open_workbook('data.xls')

s=wb.sheets()[4]
xF=[]
yF=[]

for row in range(5,s.nrows):
	x=[]
	for col in range(7,7+3): 
		x.append((int)(s.cell(row,col).value))	
	yF.append('male' if (int)(s.cell(row,11).value) ==1 else 'female')
	xF.append(x)

print(xF)
print(yF)

clf=tree.DecisionTreeClassifier()
clf=clf.fit(xF,yF)

c=input('Enter Chest size (mm):')
w=input('Enter Waist size (mm):')
f=input('Enter Foot size (mm):')

prediction=clf.predict([[c,w,f]])

print('For given data, i predict: ', prediction[0])