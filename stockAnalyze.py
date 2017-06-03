import csv
import datetime
from sklearn import tree
x=[]
y=[]
	
with open('divislab.csv') as csvfile:
	#spamreader=csv.reader(csvfile,quotechar='\t',delimiter=',')
	reader=csv.DictReader(csvfile)
	for row in reader:
		#date=row['Date'].split('-')
		prev_close=(float)(row['Prev Close'].strip())
		open_price=(float)(row['Open Price'].strip())
		avg_price=(float)(row['Average Price'].strip())
		close_price=(float)(row['Close Price'].strip())
		date=datetime.datetime.strptime(row['Date'],'%d-%b-%Y').strftime('%d-%m-%Y').split('-')
		print(date, prev_close, open_price, avg_price, close_price)
		#x.append([(int)(date[0]),(int)(date[1]),(int)(date[2]),prev_close,open_price])
		x.append([prev_close,open_price])
		y.append((int)(close_price))
#print('x: ',x)
#print('y: ',y)
clf=tree.DecisionTreeClassifier()
clf=clf.fit(x,y)
#day mon year prev_close open_prc
#prediction=clf.predict([[31,5,2017,588.00,588.90]])
prediction=clf.predict([[588.00,588.90]])
print(prediction)